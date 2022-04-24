#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1505;
vector<int>G[maxn];
int n,dp[maxn][2],x,y,a;
void dfs(int x,int fa){
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs(v,x);
        dp[x][1]+=min(dp[v][0],dp[v][1]);
        dp[x][0]+=dp[v][1];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&x,&y);
        for(int j=1;j<=y;++j){
            scanf("%d",&a);
            G[x].pb(a);
            G[a].pb(x);
        }
    }
    for(int i=0;i<n;++i)dp[i][1]=1;
    dfs(0,-1);
    cout<<min(dp[0][0],dp[0][1])<<"\n";
    return 0;
}