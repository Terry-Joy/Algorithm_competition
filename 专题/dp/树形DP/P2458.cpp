#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1600;
const int INF=1e9;
vector<int>G[maxn];
int dp[maxn][3];
int n,k,a[maxn],m,x,y;
void dfs(int x,int fa){
    int cnt=0,del=INF;
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs(v,x);
        dp[x][0]+=min(dp[v][1],dp[v][2]);
        dp[x][1]+=min(dp[v][1],min(dp[v][2],dp[v][0]));
        if(dp[v][1]<dp[v][2])cnt++;
        else del=min(del,dp[v][1]-dp[v][2]);
        dp[x][2]+=min(dp[v][1],dp[v][2]);
    }
    if(!cnt)dp[x][2]+=del;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        cin>>a[x]>>k;
        for(int j=1;j<=k;++j){
            cin>>y;
            G[x].pb(y);
            G[y].pb(x);
        }
    }
    for(int i=1;i<=n;++i){
        dp[i][1]=a[i];
    }
    dfs(1,0);
    cout<<min(dp[1][1],dp[1][2])<<"\n";
    return 0;
}