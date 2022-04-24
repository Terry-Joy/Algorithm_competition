#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105;
const int mod=998244353;
ll f[maxn],g[maxn],w[maxn],sum[maxn],fm[maxn];
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){ 
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>w[i],sum[i]=sum[i-1]+w[i];
    for(int i=1;i<=n;++i){ 
        fm[i]=mypow(sum[n]-w[i],mod-2);     
    }
    f[n]=sum[n]*fm[n]%mod;
    ll s1=w[n]*(f[n]+1)%mod;
    for(int i=n-1;i;--i){ 
        f[i]=(sum[i]+s1)*fm[i]%mod;
        s1=(s1+w[i]*(f[i]+1))%mod;
    }
    g[n]=(sum[n]+w[n]*f[n]*2)%mod*fm[n]%mod;

    ll sum1=(w[n]*f[n]*2+w[n])%mod,sum2=w[n]*g[n]%mod;
    for(int i=n-1;i;--i){ 
        sum1=(sum1+w[i]*f[i]*2+w[i])%mod;
        g[i]=(sum[i-1]+sum1+sum2)%mod*fm[i]%mod;
        sum2=(sum2+w[i]*g[i])%mod;
    }
    ll ans=0,inv=mypow(sum[n],mod-2);
    for(int i=1;i<=n;++i){ 
        ans=(ans+w[i]*inv%mod*(g[i]+2*f[i]+1))%mod;
    }
    cout<<ans;
    return 0;   
}
