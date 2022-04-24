#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int a[22][22];
int dp[1<<20],b;
int main()
{
   int n,m,cnt;
   scanf("%d%d",&n,&m);
   dp[0]=1;
   for(int i=1;i<=n;++i)
   {
      scanf("%d",&cnt);
      for(int j=1;j<=cnt;++j)
      {
         scanf("%d",&b);
         a[i][b]=1; 
      }
   } 
   int f=(1<<m)-1;
   for(int i=1;i<=n;++i)
   {
      for(int j=f;j>=0;--j)
      {
         if(dp[j])
         {
            for(int k=1;k<=m;++k)
            {
               if(a[i][k]==0||(j&(1<<k-1)))continue; //被用过不喜欢
               dp[j|(1<<k-1)]+=dp[j];
            } 
            dp[j]=0;            //保证倒序由i-1阶段向i更新的时候，dp[j]已经清空了
         } 
      } 
   }
   int ans=0;
   for(int i=0;i<=f;++i)
       ans+=dp[i];
   printf("%d\n",ans);
   return 0; 
}
