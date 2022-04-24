#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
char s[N];
int a[20][20], cnt[20];
int tmp[1<<18], gg[1<<18];
int n, m, k;
void solve(int u, int v){
    memset(tmp, 0, sizeof(tmp));
    for(int i = 1, j; i <= n;){
        while(i <= n && s[i]-'a' != u) ++i;
        int t = 0;
        j = i+1;
        while(j <= n && s[j] -'a' != u && s[j]-'a' !=  v) {
            t |= 1 << s[j]-'a';
            ++j;
        }
        if(j > n) break;
        if(s[j] - 'a' == v){
            i = j+1;
            tmp[t] = 1;
        }
        if(s[j] - 'a' == u)
            i = j;
    }
    for(int i = 0; i <= k; ++i){
        if(tmp[i]){
            gg[i] = 1;
            for(int j = 0; j < m; ++j){
                if(j == u || j == v) continue;
                tmp[i|(1<<j)] = 1;
            }
        }
    }
    return ;
}
bool vis[1<<18];
int ans;
void DFS(int x, int len){
    if(vis[x])return;
    vis[x] = 1;
    ans = min(ans, len);
    for(int i = 0; i < m; ++i){
        if(gg[x | (1<<i)]) continue;
        DFS(x|1<<i, len-cnt[i]);
    }
    return ;
}

void dfs(){
    scanf("%s", s+1);
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    k = (1<<m) - 1;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            if(a[i][j] == 0)
                solve(i,j);
    for(int i = 1; i <= n; ++i){
        cnt[s[i]-'a']++;
    }
    ans = n;
    DFS(0, n);
    printf("%d\n", ans);
    return ;
}
int main(){
    scanf("%d%d",&n,&m);
    dfs();	
    return 0;
}
