#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
int main()
{
   ll n,k;
   scanf("%lld%lld",&n,&k);
   ll ans=0;
   for(int l=1;l<=n;)
   {	    
      if(k/l==0)break;	
      ll r=(k/(k/l));
      if(r>n)ans-=(n-l+1)*(n+l)/2*(k/l);
      else ans-=(r-l+1)*(l+r)/2*(k/l);
      l=r+1;  
   } 
   ans+=n*k;
   printf("%lld\n",ans);
   return 0; 
}
