#include<bits/stdc++.h>
#define pb push_back 
#define fi first  
#define se second
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
vector<int>G[maxn];
pair<int,int>a[maxn];
int n,cnt,sz[maxn];
ll dp[maxn][4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i].fi>>a[i].se;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i){
        int j;
        for(j=i;j<=n;++j)if(a[j].fi!=a[j+1].fi)break;
        cnt++;
        if(j-i+1<=4){
            for(int k=i;k<=j;++k)
                G[cnt].pb(a[k].se);
        }else{
            G[cnt].pb(a[i].se);
            G[cnt].pb(a[i+1].se);
            G[cnt].pb(a[j].se);
            G[cnt].pb(a[j-1].se);
        }
        sz[cnt]=G[cnt].size();
        i=j;
    }
    for(int i=1;i<=cnt;++i)
        for(int j=0;j<4;++j)
            dp[i][j]=-1;
    for(int j=0;j<sz[1];++j)
        dp[1][j]=0;
    for(int i=2;i<=cnt;++i){
        for(int j=0;j<sz[i];++j){
            if(sz[i-1]==1)dp[i][j]=max(dp[i][j],dp[i-1][0]+abs(G[i][j]-G[i-1][0]));
            for(int k=0;k<sz[i-1];++k){
                for(int f=0;f<sz[i-1];++f){
                    if(k!=f)
                        dp[i][j]=max(dp[i][j],dp[i-1][k]+abs(G[i][j]-G[i-1][f]));
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<sz[cnt];++i)
        ans=max(ans,dp[cnt][i]);
    cout<<ans<<"\n";
    return 0;
}