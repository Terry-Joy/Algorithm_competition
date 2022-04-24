#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int dp[105][105],n,a[105],INF=0x3f3f3f3f,sum[105];
int main()
{
   int t;
   scanf("%d",&t);
   int k=0;
   while(t--)
   {
      scanf("%d",&n);
      sum[0]=0;
      for(int i=1;i<=n;++i)
      { 
         scanf("%d",&a[i]); 
         sum[i]=sum[i-1]+a[i];
      }
      for(int i=1;i<n;++i)
          for(int j=i+1;j<=n;++j)
              dp[i][j]=0;
      for(int len1=2;len1<=n;++len1)
      {
         for(int i=1;i+len1-1<=n;++i) 
         {
            int j=i+len1-1;
            dp[i][j]=INF;
            for(int k=1;k<=j-i+1;++k)
                dp[i][j]=min(dp[i][j],(k-1)*a[i]+dp[i+1][i+k-1]+dp[i+k][j]+k*(sum[j]-sum[i+k-1]));    //其实这里把特判k=1和k=j-i+1的情况包含进去了，因为该情况下，影响为0
         }
      }
      printf("Case #%d: %d\n",++k,dp[1][n]);
   }
   return 0; 
}
