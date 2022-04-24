#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn=1e6+5;
int fac[maxn<<1];
void init()
{
   fac[0]=1;
   for(int i=1;i<=2*maxn-5;++i)
      fac[i]=1ll*fac[i-1]*i%mod; 
}
ll mypow(ll a,ll b)
{
   ll ans=1;
   while(b){ 
      if(b&1)ans=ans*a%mod;
      a=a*a%mod;
      b>>=1;
   } 
   return ans;
}
int main()
{
   init(); 
   int n;
   while(~scanf("%d",&n))
      printf("%lld\n",1ll*fac[n]*fac[n]%mod*mypow(fac[2*n+1],mod-2)%mod); 
   return 0; 
}
