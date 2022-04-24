#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=7e7+5;
int a[maxn];
int que[maxn];
int main()
{
   int t,n,m,k,p,q,r,mod;
   scanf("%d",&t); 
   while(t--)
   {
      scanf("%d%d%d%d%d%d%d",&n,&m,&k,&p,&q,&r,&mod);
      for(int i=1;i<=k;++i)
         scanf("%d",&a[i]);
      for(int i=k+1;i<=n;++i)
         a[i]=(1ll*p*a[i-1]+1ll*q*i+r)%mod;
      int h=1,t=0;
      int mx,cnt;
      ll ans1=0,ans2=0;
      for(int i=n;i;--i)
      {
         while(h<=t&&a[que[t]]<=a[i])t--;
         que[++t]=i;
         while(h<=t&&i+m-1<que[h])h++;
         if(i+m-1<=n)
         {
            mx=a[que[h]];cnt=t-h+1;
            ans1+=(1ll*mx^i);
            ans2+=(1ll*cnt^i);
         }
      } 
      printf("%lld %lld\n",ans1,ans2);
   }
   return 0; 
}
