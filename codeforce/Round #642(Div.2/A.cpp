#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#define ll long long
using namespace std;

int main()
{
   int t;
   scanf("%d",&t);
   ll a,b;
   while(t--)
   {
      scanf("%lld%lld",&a,&b);
      ll k=1;
      bool  flag=0;
      while(k!=b&&flag==0)
      { 
          ll minn=11;
		  ll maxn=-1;
          ll x=a;
          while(x)
          { 
            minn=min(minn,x%10);
            maxn=max(maxn,x%10);
            x/=10;
          }
          k++;
          if(minn==0||maxn==0)
              flag=1;
          a+=minn*maxn;	
          if(flag)break;
      }
          printf("%lld\n",a);
   }
   return 0; 
}
