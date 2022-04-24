#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
vector<int>G[maxn];
int a[maxn],b[maxn],n,t;
ll dp[maxn][2];
void dfs(int x,int f){
    dp[x][0]=dp[x][1]=0;
    for(auto&v:G[x]){
        if(v==f)continue;
        dfs(v,x);
        dp[x][1]+=max(dp[v][1]+abs(b[x]-b[v]),dp[v][0]+abs(b[x]-a[v]));
        dp[x][0]+=max(dp[v][0]+abs(a[x]-a[v]),dp[v][1]+abs(a[x]-b[v]));
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)G[i].clear();
        for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
        int x,y;
        for(int i=1;i<n;++i){
            scanf("%d%d",&x,&y);
            G[x].pb(y);G[y].pb(x);
        }
        dfs(1,0);
        cout<<max(dp[1][0],dp[1][1])<<"\n";
    }
    return 0;
}