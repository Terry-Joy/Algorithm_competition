#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int LL;
const int MAXN = 2e5+7;

vector<pair<int,int> > G[MAXN];
int n, k;
LL f[MAXN][2], ret;


void dfs(int u, int par){
    vector<int> vec;
    for(auto &e : G[u]){
        int v = e.first, w = e.second;
        if(v==par) continue;
        dfs(v,u);
        vec.push_back(v);
        f[v][0] += w; f[v][1] += w;
    }
    sort(vec.begin(),vec.end(),[](const int x, const int y){
        return f[x][0] > f[y][0];
    });
    LL ans = 0;
    for(int v : vec) ans += f[v][0];            // 子节点中没有>k的点的情况
    ret = max(ret,ans);
    if((int)vec.size() <= k){
        LL delta = 0;                           // 选取一个子节点>k
        for(int v : vec) delta = max(delta,f[v][1] - f[v][0]);
        ret = max(ret,ans+delta);
    }else{
        // 选取一个子节点>k 且当前点选k个
        ans = 0; for(int i = 0; i < k; i++) ans += f[vec[i]][0];
        LL delta = 0;
        for(int i = 0; i < k; i++) delta = max(delta,f[vec[i]][1]-f[vec[i]][0]);
        for(int i = k; i < (int)vec.size(); i++) delta = max(delta,f[vec[i]][1] - f[vec[k-1]][0]);
        ret = max(ret,ans+delta);
    }
    f[u][0] = f[u][1] = 0;
    if((int)vec.size() < k){
        LL delta = 0;
        for(int v : vec) f[u][0] += f[v][0], delta = max(delta,f[v][1]-f[v][0]);
        f[u][1] = max(f[u][0] + delta, f[u][0]);
    }else{
        if(k==1){
            for(int v : vec) f[u][1] += f[v][0];
            return;
        }
        for(int i = 0; i < k - 1; i++) f[u][0] += f[vec[i]][0];
        f[u][1] = f[u][0];
        for(int i = k - 1; i < (int)vec.size(); i++) f[u][1] += f[vec[i]][0];
        LL delta = 0;
        for(int i = 0; i < k - 1; i++) delta = max(delta,f[vec[i]][1]-f[vec[i]][0]);
        for(int i = k - 1; i < (int)vec.size(); i++) delta = max(delta,f[vec[i]][1]-f[vec[k-2]][0]);
        f[u][1] = max(f[u][1],f[u][0]+delta);
    }
}

void solve(){
    scanf("%d %d",&n,&k);
    for(int i = 1; i <= n; i++) G[i].clear();
    for(int i = 1; i < n; i++){
        int u, v, w;
        scanf("%d %d %d",&u,&v,&w);
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    ret = 0;
    if(k) dfs(1,0);
    cout << ret << endl;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("Local.in","r",stdin);
    freopen("ans.out","w",stdout);
    #endif
    int tt; for(scanf("%d",&tt); tt; tt--) solve();
    return 0;
}