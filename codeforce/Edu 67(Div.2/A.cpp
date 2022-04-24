#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long 

using namespace std;

int main()
{
   ll t,n,s,q;
   scanf("%lld",&q);
   while(q--)
   {
      scanf("%lld%lld%lld",&n,&s,&t);
      printf("%lld",max(s,t)-(s+t-n)+1);
   }
   return 0; 
}
