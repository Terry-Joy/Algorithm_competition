#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=998244353;
ll n,m,k,inv[maxn],fac[maxn];
ll mypow(ll a,ll b)
{
   ll ans=1;
   while(b)
   {
      if(b&1)ans=ans*a%mod;
      a=a*a%mod;
      b>>=1; 
   } 
   return ans;
}
void init()
{
   fac[0]=1;
   inv[0]=1;
   for(int i=1;i<=maxn-2;++i)
   {
      fac[i]=fac[i-1]*i%mod;
      inv[i]=mypow(fac[i],mod-2); 
   } 
}
ll C(ll n,ll m)
{
   return fac[n]*inv[n-m]%mod*inv[m]%mod; 
}
int main()
{
   init(); 
   int t;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%lld%lld%lld",&n,&m,&k);
      ll ans=C(m+k-1,m-1);
      ll cnt=min(k/n,m);
      for(int i=1;i<=cnt;++i)
      {
         if(i%2==1)ans=(ans-C(m,i)*C(k+m-1-i*n,m-1)%mod+mod)%mod;
         else ans=(ans+C(m,i)*C(k+m-1-i*n,m-1)%mod+mod)%mod; 
      } 
      printf("%lld\n",ans);
   }
   return 0; 
}
