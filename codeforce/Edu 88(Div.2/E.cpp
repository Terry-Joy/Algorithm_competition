#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e5+10;
const ll mod=998244353;
ll fac[maxn],inv[maxn];
   int n,k;
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
   fac[0]=fac[1]=inv[0]=inv[1]=1;
   for(int i=2;i<=500005;++i)
   {    
       fac[i]=fac[i-1]*i%mod; 
       inv[i]=inv[i-1]*mypow(i,mod-2)%mod;
   }
}
ll C(int n,int m)
{
   if(n<0||m<0||n<m)return 0;
   return fac[n]*inv[n-m]%mod*inv[m]%mod; 
}
int main()
{
   init(); 
   scanf("%d%d",&n,&k);
   ll ans=0;
   for(int i=1;i<=n;++i)
       ans=(ans+C(n/i-1,k-1))%mod;//选定基数后，必须得是该基数的倍数才满足
   printf("%lld\n",ans);
   return 0; 
}
