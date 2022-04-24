#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=3835;
int dp[2][maxn][2],a[maxn];

int main()
{
   int n,b;
   memset(dp,-1,sizeof(dp));
   scanf("%d%d",&n,&b);
   for(int i=1;i<=n;++i)
    
      scanf("%d",&a[i]);
   
   memset(dp,0xcf,sizeof(dp));              //不存在的情况注意初始化
   dp[1&1][0][0]=0;dp[1&1][1][1]=0;
   for(int i=2;i<=n;++i)
   {
      for(int j=0;j<=b;++j)
      { 
          dp[i&1][j][0]=max(dp[(i-1)&1][j][0],dp[(i-1)&1][j][1]);
          if(j-1>=0)dp[i&1][j][1]=max(dp[(i-1)&1][j-1][1]+a[i],dp[(i-1)&1][j-1][0]);
      }
   }
   int ans=-1;
   ans=max(dp[n&1][b][1],dp[n&1][b][0]);
   memset(dp,0xcf,sizeof(dp));
   dp[1][1][1]=a[1];
   for(int i=2;i<=n;++i)                //补充情况成环
   {
      for(int j=0;j<=b;++j)
      { 
          dp[i&1][j][0]=max(dp[(i-1)&1][j][0],dp[(i-1)&1][j][1]);
          if(j-1>=0)dp[i&1][j][1]=max(dp[(i-1)&1][j-1][1]+a[i],dp[(i-1)&1][j-1][0]);
      }
    }
   ans=max(ans,dp[n&1][b][1]);
   printf("%d",ans);
   return 0; 
}