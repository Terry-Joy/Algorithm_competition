#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll mod=1e9+7;
vector<int>G[maxn];
ll dp[maxn][4];
int n,k,col[maxn];
void dfs(int x,int fa){
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs(v,x);
        dp[x][1]=dp[x][1]*(dp[v][2]+dp[v][3])%mod;
        dp[x][2]=dp[x][2]*(dp[v][1]+dp[v][3])%mod;
        dp[x][3]=dp[x][3]*(dp[v][1]+dp[v][2])%mod;
    }
}
int main(){
    scanf("%d%d",&n,&k);
        int x,y;
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        G[x].pb(y);
        G[y].pb(x);
    }
    for(int i=1;i<=k;++i){
        scanf("%d%d",&x,&y);
        col[x]=y;
    }
    for(int i=1;i<=n;++i){
        if(col[i]){
            for(int j=1;j<=3;++j){
                if(j!=col[i])
                    dp[i][j]=0;
                else dp[i][j]=1;
            }
        }else for(int j=1;j<=3;++j)dp[i][j]=1;
    }
    dfs(1,0);
    ll ans=0;
    for(int j=1;j<=3;++j)
            ans+=dp[1][j],ans%=mod;
    cout<<ans<<"\n";
    return 0;
}