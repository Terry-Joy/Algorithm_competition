#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=1e6+10,mod=1e9;
int dp[maxn];
int main()
{
   int n;
   scanf("%d",&n);
   dp[0]=dp[1]=1;
   for(int i=2;i<=n;++i)
   {
      if(i&1) 
         dp[i]=dp[i-1];
      else
         dp[i]=(dp[i-1]+dp[i>>1])%mod; 
   }
   printf("%d",dp[n]);
   return 0; 
}

