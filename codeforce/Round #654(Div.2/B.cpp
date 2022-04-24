#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
   int t;
   scanf("%d",&t);
   ll n,r;
   while(t--)
   {
       scanf("%lld%lld",&n,&r);
       if(n>r)
          printf("%lld\n",(r+1)*r/2);
       else if(n<=r)
          printf("%lld\n",((n)*(n-1)/2)+1);
   }
   return 0; 
}
