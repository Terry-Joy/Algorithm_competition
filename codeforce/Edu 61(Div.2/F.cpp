#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int dp[510][510];
char s[510];
int main()
{
   int n;
   scanf("%d",&n);
   scanf("%s",s+1); 
   memset(dp,0,sizeof(dp));
   for(int i=1;i<=n;++i)
       dp[i][i]=1;
   for(int len=2;len<=n;++len)
   {
      for(int l=1;l<=n-len+1;++l)
      {
         int r=l+len-1;
         if(s[l]==s[r])dp[l][r]=dp[l+1][r-1]+1;
         else dp[l][r]=min(dp[l+1][r],dp[l][r-1])+1;
         for(int k=l;k<=r;++k)
         {
            dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]-1); 
         } 
      } 
   }
   cout<<dp[1][n]<<"\n";
   return 0; 
}
