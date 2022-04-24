#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
char s[1010],ans[1010];
const int maxn=1e3+5;
int dp[maxn][maxn],n,len;
int dfs(int pos,int mod)
{
   if(pos==len)return mod==0;
   if(dp[pos][mod]!=-1)return dp[pos][mod];
   if(s[pos]=='?')
   {
      for(int i=0;i<=9;++i)
      {
         if(!pos&&!i)continue;
         ans[pos]=i+'0';
         dp[pos][mod]=dfs(pos+1,(mod*10+i)%n);
         if(dp[pos][mod]==1)return dp[pos][mod]; 
      } 
   } 
   else
   {
      ans[pos]=s[pos];
      dp[pos][mod]=dfs(pos+1,(mod*10+s[pos]-'0')%n); 
   }
   return dp[pos][mod];
}
int main()
{
   scanf("%s",s); 
   scanf("%d",&n);
   len=strlen(s);
   memset(dp,-1,sizeof(dp));
   if(dfs(0,0)==1)
   { 
       ans[len]=0;
       for(int i=0;i<len;++i)
           putchar(ans[i]);
       puts("");
   }
   else
       puts("*");
   return 0; 
}
