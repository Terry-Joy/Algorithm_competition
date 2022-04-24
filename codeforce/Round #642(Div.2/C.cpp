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
   ll a,b,c,d;
   scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
   ll ans=0;
   for(int i=b;i<=c;++i)
   {
       ll xm=max(a,c-i+1);
       if(i+xm>d)
           ans+=(b-xm+1)*(d-c+1);
       else if(d-i>=xm&&d-i<=b)
        { 
           		ans+=((b-d+i)*(d-c+1)+(xm+i+d-2*c)*(d-xm-i+1)/2);
		}
       else if(d-i>b)
           ans+=(b+xm+2*i-2*c)*(b-xm+1)/2;
   } 
   printf("%lld",ans);
   return 0;
}
