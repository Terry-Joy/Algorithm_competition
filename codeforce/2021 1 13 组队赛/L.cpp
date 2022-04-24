#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+80000;
ll dp[4][maxn+5][55];
int t,n,m,h[55],g[4*55],st[4*55],ed[4*55],des[55];
const ll INF=4e18;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int i=1;i<=t;++i)
        for(int j=0;j<=maxn;++j)
            for(int k=1;k<=50;++k)
                dp[i][j][k]=INF;
    for(int i=1;i<=t;++i){ 
        cin>>n>>m;
        for(int j=1;j<=n;++j)cin>>h[j];
        for(int j=1;j<=m;++j)cin>>st[j]>>ed[j]>>g[j];;
        cin>>des[i];
        dp[i][0][1]=0;
        for(int j=0;j<=maxn;++j){ 
            for(int k=1;k<=n;++k)
                dp[i][j+1][k]=min(dp[i][j+1][k],dp[i][j][k]+h[k]);
            for(int k=1;k<=m;++k){ 
                dp[i][j+1][ed[k]]=min(dp[i][j+1][ed[k]],dp[i][j][st[k]]+g[k]);
            }
        }
    }
    ll ans=INF;
    for(int j=0;j<=maxn;++j){ 
        ll num=0;
        for(int i=1;i<=t;++i)num+=dp[i][j][des[i]];
        ans=min(ans,num);
    }
    cout<<ans<<"\n";
    return 0;
}
