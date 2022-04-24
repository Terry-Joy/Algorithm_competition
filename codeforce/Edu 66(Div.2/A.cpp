#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      ll n,k,ans=0;
      scanf("%lld%lld",&n,&k);
      while(n)
      {
          ll x=n%k;
          if(x)ans+=x,n-=x;
          else
            ans++,n/=k;  
      } 
      printf("%lld\n",ans);
   }
   return 0; 
}
