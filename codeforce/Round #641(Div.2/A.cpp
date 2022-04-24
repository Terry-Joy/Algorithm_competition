#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+10;
int di[maxn];
int main()
{
   for(int i=2;i<=maxn;++i)
   {
      int cnt=0;
      for(int j=2;j*j<=i;++j)
      {
         if(i%j==0)
         {
            di[i]=j,cnt++;
            break; 
         }
      } 
      if(cnt==0)
          di[i]=i;
   }
   int t;
   scanf("%d",&t);
   ll ans=0;
   while(t--)
   { 
       ll n,k;
       scanf("%lld%lld",&n,&k);
       if(n%2==0)
           ans=n+2*k;
       else
       {
          ans=n+di[n];
          k--;
          ans=ans+2*k; 
       }
       printf("%lld\n",ans);
   }
   return 0; 
}
