#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll dp[maxn][5],sum[maxn],ans=0;
int n,k;
vector<int>G[maxn];
void dfs(int x,int f){ 
    dp[x][0]=1;
    sum[x]=1;
    for(auto&v:G[x]){ 
        if(v==f)continue;
        dfs(v,x);
        for(int i=0;i<k;++i)
            for(int j=0;j<k;++j){ 
                ll need=(k-(i+j+1)%k)%k;
                ans+=need*dp[x][i]*dp[v][j];
            }
        for(int i=0;i<k;++i)
            dp[x][(i+1)%k]+=dp[v][i];
        sum[x]+=sum[v];
    }
    ans+=sum[x]*(n-sum[x]);
}
int main(){
    scanf("%d%d",&n,&k);
    int a,b;
    for(int i=1;i<n;++i){ 
        scanf("%d%d",&a,&b);
        G[a].pb(b);G[b].pb(a);
    } 
    dfs(1,-1);
    cout<<ans/k;
    return 0;
}
