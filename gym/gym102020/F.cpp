#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long ll;
using namespace std;
ll dp[22];
const ll mod=1e9+7;
int main()
{
   dp[1]=0,dp[2]=1,dp[3]=2;
   int n;
   scanf("%d",&n);
   for(int i=4;i<=n;++i)
       dp[i]=(i-1)*(dp[i-1]+dp[i-2])%mod;//错排问题
   printf("%d",dp[n]);
   return 0; 
}
