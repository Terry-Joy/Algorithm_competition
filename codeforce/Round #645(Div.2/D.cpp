#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=4e5+5;
ll a[maxn],sum[maxn];
int main()
{
   ll n,x;
   scanf("%lld%lld",&n,&x);
   for(int i=1;i<=n;++i)
    { 
      scanf("%lld",&a[i]);
      a[i+n]=a[i];
      sum[i]=(1+a[i])*a[i]/2;sum[i+n]=sum[i];
    }
   for(int i=1;i<=2*n;++i)
       a[i]+=a[i-1],sum[i]+=sum[i-1];
   ll ans=-1;
   for(int i=1;i<=2*n;++i)          //结尾点必定是月份最后一天
   {
      if(a[i]<x)continue;
      ll k=a[i]-x;
      ll j=lower_bound(a+1,a+1+2*n,k)-a;
      if(a[i]-a[j]==x)ans=max(ans,sum[i]-sum[j]);
      else
      {
         ll rest=k-a[j-1];
         ans=max(ans,sum[i]-sum[j-1]-(1+rest)*rest/2);//去掉多余的日期 
      }  
   } 
   printf("%lld",ans);
   return 0; 
}
