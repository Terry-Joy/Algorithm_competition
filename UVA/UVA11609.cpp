#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
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
int main()
{
    int t,k=0;
    scanf("%d",&t);
    while(t--)
    {
       int a;
       scanf("%d",&a);
       printf("Case #%d: %lld\n",++k,a%mod*mypow(2,a-1)%mod); 
    }
    return 0;
}
