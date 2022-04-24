#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
int dp[maxn][105][2][2],tmp[105][2][2],n,K,sz[maxn];
vector<int>G[maxn];
void add(int&x,ll y){
    if(y>=mod)y%=mod;
    x+=y;
    if(x>=mod)x-=mod;
}
void dfs(int x,int f){
    sz[x]=dp[x][0][0][0]=dp[x][1][1][0]=1;
    for(auto&v:G[x]){
        if(v==f)continue;
        dfs(v,x);
        for(int i=0;i<=min(sz[x],K);++i){
            for(int j=0;j<=1;++j)
                for(int k=0;k<=1;++k)
                    tmp[i][j][k]=dp[x][i][j][k],dp[x][i][j][k]=0;
        }
        for(int i=min(sz[x],K);i>=0;--i){
            for(int j=min(sz[v],K-i);j>=0;--j){
                add(dp[x][i+j][0][0],1ll*tmp[i][0][0]*dp[v][j][0][1]);
                add(dp[x][i+j][1][0],1ll*tmp[i][1][0]*(dp[v][j][0][0]+dp[v][j][0][1]));
                add(dp[x][i+j][0][1],1ll*tmp[i][0][1]*(dp[v][j][0][1]+dp[v][j][1][1])+1ll*tmp[i][0][0]*dp[v][j][1][1]);
                add(dp[x][i+j][1][1],1ll*tmp[i][1][1]*(1ll*dp[v][j][0][0]+dp[v][j][0][1]+dp[v][j][1][0]+dp[v][j][1][1]));
                add(dp[x][i+j][1][1],1ll*tmp[i][1][0]*(dp[v][j][1][0]+dp[v][j][1][1]));
            }
        }
        sz[x]+=sz[v];
    }
}
int main(){
    scanf("%d%d",&n,&K);
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].pb(y);G[y].pb(x);
    }
    dfs(1,0);
    cout<<(dp[1][K][0][1]+dp[1][K][1][1])%mod<<"\n";
    return 0;
}