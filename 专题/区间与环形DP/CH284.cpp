#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
char s[310];
ll dp[310][310];
const ll mod=1e9;
int main()
{
   scanf("%s",s+1);
   int k=strlen(s+1);
   for(int i=1;i<=k;++i)
      dp[i][i]=1;
   for(int len=3;len<=k;++len)
   {
      for(int i=1;i+len-1<=k;++i)
      {
         int j=i+len-1;
         if(s[i]!=s[j])continue;
         dp[i][j]=dp[i+1][j-1];     //对应整颗子树
         for(int k=i+2;k<j;++k)
         {
            if(s[k]==s[i]) 
               dp[i][j]=(dp[i][j]+dp[i+1][k-1]*dp[k][j])%mod;//枚举第一颗子树
         } 
      } 
   } 
   printf("%lld\n",dp[1][k]);
   return 0; 
}
