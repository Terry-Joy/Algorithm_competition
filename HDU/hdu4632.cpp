#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int dp[1005][1005];
char s[1005];
const int mod=1e4+7;
int main()
{
   int t,k=0;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%s",s+1);
      int n=strlen(s+1);
      for(int i=1;i<=n;++i)
        dp[i][i]=1;
      for(int len=2;len<=n;++len)
      {
         for(int i=1;i+len-1<=n;++i)
         {
            int j=i+len-1;
            dp[i][j]=(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+mod)%mod;
            if(s[i]==s[j])
               dp[i][j]=(dp[i][j]+dp[i+1][j-1]+1)%mod; 
         } 
      }
      printf("Case %d: %d\n",++k,dp[1][n]);
   } 
   return 0; 
}
