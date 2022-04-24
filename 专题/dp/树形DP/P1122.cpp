#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=16005;
vector<int>G[maxn];
int dp[maxn],a[maxn],n;
void dfs(int x,int fa){
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs(v,x);
        dp[x]+=max(0,dp[v]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)dp[i]=a[i];
    int x,y;
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1,0);
    int ans=-2147483647;
    for(int i=1;i<=n;++i)ans=max(ans,dp[i]);
    cout<<ans<<"\n";
    return 0;
}