#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
const ll mod=1e9+7;
int n,k;
ll fac[maxn],facinv[maxn];
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void init(){ 
    fac[1]=fac[0]=1;
    for(int i=2;i<maxn;++i)fac[i]=fac[i-1]*i%mod;
    facinv[maxn-1]=mypow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i)
        facinv[i]=facinv[i+1]*(i+1)%mod;
}
ll C(int n,int m){ 
    if(n<m)return 0;
    return  fac[n]*facinv[n-m]%mod*facinv[m]%mod;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin>>n>>k;
    ll ans=0;
    for(int i=0;i<=min(k,n-1);++i)
        ans=(ans+C(n,i)*C(n-1,n-i-1)%mod)%mod;
    cout<<ans;
    return 0;
}
