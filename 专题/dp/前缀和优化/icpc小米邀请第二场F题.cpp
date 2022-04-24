#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e3+5;
ll dp[maxn][maxn],inv3,rsum[maxn],ans,r[maxn];
int n,m;
const ll mod=1e9+7;
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ans;
}
int main(){ 
    inv3=(mod+1)/3;
    while(~scanf("%d%d",&n,&m)){ 
        ans=1;
        int low=0,a,b;
        rsum[0]=1;
        dp[0][0]=1;
        for(int i=1;i<=n;++i)rsum[i]=0,r[i]=0;
        for(int i=1;i<=m;++i){ 
           scanf("%d%d",&a,&b); 
           r[b]=max(r[b],1ll*a); 
        }
        for(int i=1;i<=n;++i){ 
            rsum[i]=0;
            for(int j=0;j<i;++j)
                dp[i][j]=rsum[j]*inv3%mod;
            dp[i][i]=ans*inv3%mod;
            for(int j=0;j<=i;++j)//行前缀和维护
                rsum[i]=(rsum[i]+dp[i][j])%mod;
            ans=(ans+rsum[i])%mod;//答案维护
            if(r[i]>low){ //枚举去重
                for(int j=0;j<=i;++j)
                    for(int k=low;k<r[i];++k){ 
                        rsum[j]=(rsum[j]-dp[j][k]+mod)%mod;
                        ans=(ans-dp[j][k]+mod)%mod;
                        dp[j][k]=0;
                    }
                low=r[i];
            }
        }
        for(int i=1;i<=n;++i)
            ans=ans*6%mod;
        cout<<ans%mod<<"\n";
    }
    return 0;
}
