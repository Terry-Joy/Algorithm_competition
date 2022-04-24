#include<bits/stdc++.h>

using namespace std;

struct edge {
    int v, w;
};
vector<edge> g[100005], tree[100005];
int par[100005], wp[100005];

int a[32];
void insert(int w) {
    for(int i=29;i>=0;--i) {
        if(w>>i&1) {
            if(!a[i]) {
                a[i]=w;
                return;
            }
            w^=a[i];
        }
    }
}
int query(int x) {
    for(int i=29;i>=0;--i) {
      if((x^a[i])>x)x^=a[i];
    }
    return x;
}
int find(int x) {
    if(par[x] == x) return x;
    int y = find(par[x]);
    wp[x] ^= wp[par[x]];
    par[x] = y;
    return y;
}
int merge(int u, int v, int w) {
    int x = find(u), y = find(v);
    if(x == y) {
//        cout << "ins: " << (wp[u] ^ wp[v] ^ w) << endl;
        insert(wp[u] ^ wp[v] ^ w);
        return 0;
    }
    wp[x] = wp[u] ^ wp[v] ^ w;
    par[x] = y;
    return 1;
}

int wtree[100005], pre[100005];
void dfs(int u, int fa, int w) {
    wtree[u] = w;
    for(edge e : tree[u]) {
        if(e.v == fa) continue;
        dfs(e.v, u, e.w ^ w);
    }
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i) par[i] = i;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if(merge(u, v, w)) {
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
        }
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0, 0);
    for(int i=1;i<=n;++i) pre[i]^=pre[i-1]^wtree[i];
    while(q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
//        for(int i = l; i <= r; ++i) {
//            for(int j = i + 1; j <= r; ++j) {
//                ans ^= query(wtree[i] ^ wtree[j]);
//            }
//        }
        if((r-l)&1) ans^=(pre[r]^pre[l-1]);
        if((r-l+1)%4==0 || (r-l+1)%4==1)
        {
            for(int i=29;i>=0;--i) {//除掉基元
                if(ans^a[i]<ans) ans^=a[i];
            }
        }
        else ans = query(ans);
        cout << ans << endl;
    }
}
