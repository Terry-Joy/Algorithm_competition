#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=6010;
vector<int>G[maxn];
int dp[maxn][2],a[maxn],n,x,y,deg[maxn];
void dfs(int x,int fa){ 
    dp[x][1]=a[x];
    for(auto&v:G[x]){ 
        if(v==fa)continue;
        dfs(v,x);
        dp[x][0]+=max(dp[v][0],dp[v][1]);
        dp[x][1]+=dp[v][0];
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    while(cin>>x>>y){
        if(x+y==0)break;
        deg[x]++;
        G[x].pb(y);
        G[y].pb(x);
    }
    int i;
    for(i=1;i<=n;++i){ 
        if(!deg[i])break;
    }
    dfs(i,-1);
    cout<<max(dp[i][0],dp[i][1])<<"\n";
    return 0;
}
