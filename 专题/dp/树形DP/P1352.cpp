#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=6e3+5;
vector<int>G[maxn];
int dp[maxn][2],deg[maxn];
void dfs(int x,int fa){
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs(v,x);
        dp[x][1]+=dp[v][0];
        dp[x][0]+=max(dp[v][1],dp[v][0]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&dp[i][1]);
    int x,y;
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        G[x].pb(y);G[y].pb(x);
        deg[x]++;
    }
    int rt=0;
    for(int i=1;i<=n;++i){
        if(!deg[i]){
            rt=i;break;
        }
    }
    dfs(rt,0);
    cout<<max(dp[rt][0],dp[rt][1])<<"\n";
    return 0;
}