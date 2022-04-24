#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=5e3+5;
const int mod=998244353;
int n,t,dp[maxn][maxn],k,u,v,ans,md[maxn],tmp[maxn];
vector<int>G[maxn];
void add(int&x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
void dfs(int x,int f){
    dp[x][0]=1;
    for(auto&v:G[x]){
        if(v==f)continue;
        dfs(v,x);
        for(int i=0;i<=max(md[x],md[v])+1;++i)tmp[i]=0;
        for(int i=0;i<=min(md[x],k);++i){
            for(int j=0;j<=min(md[v],k);++j){  
                add(tmp[i],mul(dp[x][i],dp[v][j]));
                if(i+j+1>k)continue;
                add(tmp[max(i,j+1)],mul(dp[x][i],dp[v][j]));
            }
        }
        md[x]=max(md[x],md[v]+1);
        for(int i=0;i<=md[x];++i)dp[x][i]=tmp[i];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;++i){
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1,0);
    for(int i=0;i<=k;++i)add(ans,dp[1][i]);
    cout<<ans<<"\n";
    return 0;
}