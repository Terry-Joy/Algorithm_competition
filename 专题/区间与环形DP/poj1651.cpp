#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int dp[105][105],a[105];
const int INF=0x3f3f3f3f;
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
      scanf("%d",&a[i]);

   for(int len=1;len<n;++len)
   {
      for(int i=2;i+len-1<=n-1;++i)
      {
         int j=i+len-1;
         dp[i][j]=INF;
         for(int k=i;k<=j;++k)
            dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[i-1]*a[k]*a[j+1]); 
      } 
   } 
   printf("%d\n",dp[2][n-1]);
   return 0; 
}
