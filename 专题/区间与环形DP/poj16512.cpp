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

   for(int len=3;len<=n;++len)
   {
      for(int i=1;i+len-1<=n;++i)
      {
         int j=i+len-1;
         dp[i][j]=INF;          //初始化
         for(int k=i+1;k<=j-1;++k)
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]); 
      } 
   } 
   printf("%d\n",dp[1][n]);
   return 0; 
}
