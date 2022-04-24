#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=55;
const int mod=1e9+7;
ll dp[2][maxn][maxn];
int L[maxn],n,m,l,r;
void add(ll&x,ll y){ 
    x+=y;
    if(x>=mod)x-=mod;
}
int main(){ 
    while(~scanf("%d%d",&n,&m)){ 
        memset(dp,0,sizeof(dp));
        memset(L,0,sizeof(L));
        for(int i=1;i<=m;++i){ 
            scanf("%d%d",&l,&r);
            L[r]=max(L[r],l);
        }
        dp[0][0][0]=1;
        for(int i=0;i<n;++i){ 
            for(int j=0;j<=i;++j){ 
                for(int k=0;k<=j;++k){ 
                    if(k>=L[i]){ 
                        if(!dp[i&1][j][k])continue;
                        add(dp[(i+1)&1][j][k],6*dp[i&1][j][k]%mod);
                        add(dp[(i+1)&1][i+1][j],2*dp[i&1][j][k]%mod);
                        add(dp[(i+1)&1][i+1][i+1],2*dp[i&1][j][k]%mod);
                    } 
                    dp[i&1][j][k]=0;
                }
            }
        }
        ll ans=0;
        for(int j=0;j<=n;++j)
            for(int k=0;k<=j;++k)
                if(k>=L[n])add(ans,dp[n&1][j][k]);
        cout<<ans<<"\n";
    }
    return 0;
}
