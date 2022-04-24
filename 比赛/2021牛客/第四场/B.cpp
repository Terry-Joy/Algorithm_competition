#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=105;
typedef long long ll;
int n,p[maxn],sum;
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
    cin>>n;
    for(int i=1;i<=n;++i)cin>>p[i],sum+=p[i];
    sum=mypow(sum,mod-2);
    for(int i=1;i<=n;++i)
        p[i]=1ll*p[i]*sum%mod;
    ll F=1,F1=0;
    for(int i=1;i<=n;++i){ 
        ll inv=mypow((1-p[i]+mod)%mod,mod-2);
        F=F*inv%mod;
        F1=(F1+1ll*p[i]*inv%mod)%mod;
    }
    ll ans=(2*F1*F+F)%mod;
    cout<<ans;
    return 0;
}
