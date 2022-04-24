#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5005;
const ll mod=1e9+7;
ll f[maxn],g[maxn],fac[maxn];
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
    ll n,r,c,k;
    cin>>n>>r>>c>>k;
    for(int i=1;i<=5000;++i)fac[i]=mypow(i,n);
    for(int i=1;i<=r;++i)
        for(int j=i;j<=r;++j)
            f[j-i+1]=(f[j-i+1]+(fac[i]-fac[i-1]+mod)*(fac[r-j+1]-fac[r-j]+mod)%mod)%mod;
    for(int i=1;i<=c;++i)
        for(int j=i;j<=c;++j)
            g[j-i+1]=(g[j-i+1]+(fac[i]-fac[i-1]+mod)*(fac[c-j+1]-fac[c-j]+mod)%mod)%mod;
    ll ans=0;
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j){
            if(i*j>=k)ans=(ans+f[i]*g[j]%mod)%mod;
        }
    cout<<ans<<"\n";
    return 0;
}