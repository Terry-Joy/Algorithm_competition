#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const int maxn=1e5+100;
ll fac[maxn],c[maxn]; 
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
	fac[0]=c[0]=1;
	for(int i=1;i<maxn;++i)
	{
		fac[i]=(fac[i-1]*i)%mod;
		c[i]=mypow(fac[i],mod-2);
	}
}
ll C(ll n,ll m)
{
	return ((fac[n] * c[m]) % mod) * c[n - m] % mod;
}
int main()
{
   init();
   int t;
 ll n,m;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%lld %lld",&n,&m);
      printf("%lld %lld\n",C(n,m-1),C(n-1,m-1));
   }
   return 0; 
}

