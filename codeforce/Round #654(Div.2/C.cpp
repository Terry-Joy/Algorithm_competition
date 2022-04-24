#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      ll a,b,n,m;
      scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
      if(a+b<m+n||min(a,b)<m)puts("No");
      else puts("Yes");
   } 
   return 0; 
}
