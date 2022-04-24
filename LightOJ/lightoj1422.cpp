#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=110;
int dp[maxn][maxn],a[maxn],tot=0;
int main()
{
   int t,n;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      for(int i=1;i<=n;++i)
      {
         scanf("%d",&a[i]);
         dp[i][i]=1; 
      }
      for(int len=2;len<=n;++len)
      {
         for(int i=1;i+len-1<=n;++i)
         {
            int j=i+len-1;
            dp[i][j]=dp[i][j-1]+1;      //选择穿新
            for(int k=i;k<=j-1;++k)
            {
               if(a[k]==a[j])
                  dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j-1]);//看之前的 
            } 
         } 
      }
      printf("Case %d: %d\n",++tot,dp[1][n]);
   } 
   return 0; 
}
