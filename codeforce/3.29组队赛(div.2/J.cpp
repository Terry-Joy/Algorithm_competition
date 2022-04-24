#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#define ll long long
using namespace std;
int main()
{
   int t;
   ll n;
   scanf("%d",&t);
   while(t--)
   { 
       scanf("%lld",&n);
       ll k=n;
       ll sum=0;
       while(k)
       { 
          if(k&1)sum++;
          k>>=1; 
       }
       ll num=n+1-(1ll<<sum);
       printf("%lld\n",num);
   }
   return 0; 
}

