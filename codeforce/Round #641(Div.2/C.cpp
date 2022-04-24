#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
   return b?gcd(b,a%b):a; 
}
ll lcm(ll a,ll b)
{
   return a*b/gcd(a,b); 
}
const int maxn=3e5+10;
ll a[maxn],suf[maxn];
int main()
{
  ll n,ans=0;
   scanf("%lld",&n);
   for(int i=1;i<=n;++i)
       scanf("%lld",&a[i]);
   for(int i=n;i>=1;--i)
       suf[i]=gcd(suf[i+1],a[i]);
   for(int i=1;i<=n;++i)
       ans=gcd(ans,lcm(a[i],suf[i+1]));
   printf("%lld\n",ans);
   return 0; 
}
