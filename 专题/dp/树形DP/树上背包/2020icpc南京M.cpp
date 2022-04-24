#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=2e3+5;
const ll INF=1e18;
ll dp[maxn][maxn][2];
int t,n,fa,val[maxn],sz[maxn];
vector<int>G[maxn];
void dfs(int x){
    sz[x]=1;
    for(auto&v:G[x]){
        dfs(v);
        for(int j=sz[x];j>=0;--j){
            for(int k=sz[v];k>=0;--k){
                if(k){
                	if((j+k)!=sz[x]+sz[v])//这些if不加也可以 因为INF不转移了
                    	dp[x][j+k][0]=min(dp[x][j+k][0],dp[x][j][0]+dp[v][k][0]+val[v]);
                    if(j>0&&k>0)
                        dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+dp[v][k][1]);
                    if(j>0&&k!=sz[v])
                        dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+dp[v][k][0]);
                    if(k>0&&(j+k)!=sz[x]+sz[v]) 
                        dp[x][j+k][0]=min(dp[x][j+k][0],dp[x][j][0]+dp[v][k][1]);
                }else{
                    if(dp[x][j][0]!=INF&&dp[v][k][0]!=INF){//最小值要特判自己转移自己
                        dp[x][j][0]=dp[x][j][0]+dp[v][k][0]+val[v];
                    }
                    if(dp[x][j][1]!=INF&&dp[v][k][0]!=INF){
                        dp[x][j][1]=dp[x][j][1]+dp[v][k][0];
                    }
                }
            }
        }
        sz[x]+=sz[v];
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=n;++i)G[i].clear();
        scanf("%d",&n);
        for(int i=2;i<=n;++i){
            scanf("%d",&fa);
            G[fa].pb(i);
        }
        for(int i=1;i<=n;++i)
            for(int j=0;j<=n;++j)
                dp[i][j][1]=dp[i][j][0]=1e18;
        for(int i=1;i<=n;++i)scanf("%d",&val[i]),dp[i][1][1]=0,dp[i][0][0]=val[i];
        dfs(1);
        cout<<min(dp[1][0][0],dp[1][0][1]);
        for(int i=1;i<=n;++i)
            cout<<" "<<min(dp[1][i][0],dp[1][i][1]);
        cout<<"\n";
    }
    return 0;
}