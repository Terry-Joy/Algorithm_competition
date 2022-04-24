#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int t;
   scanf("%d",&t);
   ll a,b,c,d;
   while(t--)
   {
      scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
      if(b>=a)
      { 
         cout<<b<<endl;
         continue;
      }
      if(c<=d)
      {
         puts("-1");
         continue; 
      }
      ll k=(a-b)%(c-d);
      if(k!=0)k=(a-b)/(c-d)+1;
      else k=(a-b)/(c-d);
      cout<<k*c+b<<endl;
   }
   return 0; 
}
