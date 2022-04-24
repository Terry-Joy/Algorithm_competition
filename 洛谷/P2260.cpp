#include<iostream>
#include<cstdio>
#include<cstring>
#define inv2 9970209
#define inv6 3323403
using namespace std;
typedef long long ll;
const ll mod=19940417;
ll G(ll n,ll k)
{
    ll l=1,r=0,ans=0;
    for(;l<=n&&k/l;l=r+1){ //特判0的地方
        r=min(k/(k/l),n);
        ans=(ans+(k/l)*(l+r)%mod*(r-l+1)%mod*inv2%mod)%mod;
    }
    return ans;
}
ll F(ll x){return (x*x%mod-G(x,x)%mod+mod)%mod;}
ll S(ll x)
{
   return x%mod*(x+1)%mod*(2*x+1)%mod*inv6%mod; 
}
int main()
{
   ll n,m;
   scanf("%lld%lld",&n,&m);
   ll ans=0;
   if(n>m)swap(n,m);
   ans=(ans+F(n)*F(m)%mod)%mod;
   ans=(ans-n*m%mod*n%mod+mod)%mod;
   ans=(ans+m*G(n,n)%mod+n*G(n,m)%mod)%mod;
   ll l=1,r=0;
   for(;l<=n;l=r+1)
   {
      r=min(n/(n/l),m/(m/l));
      ans=(ans-(n/l)*(m/l)%mod*((S(r)-S(l-1)))%mod+mod)%mod; 
   } 
   cout<<ans<<"\n";
   return 0; 
}
