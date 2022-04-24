#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
char s[105];
int a[105];
ll dp[103][10][2];//dp[i][j][k]表示第i位 pre1是j, 前面是否递增标志
const ll MOD=1e9+7;

ll dfs(int pos,bool limit,bool lead,int pre1,bool flag)
{
   if(pos==-1)return 1;
   if(!limit&&!lead&&dp[pos][pre1][flag]!=-1)return dp[pos][pre1][flag];
   int up=limit?a[pos]:9;
   ll ans=0;
   for(int i=0;i<=up;++i)
   {
      if(flag&&pre1>i)continue;
      int st=0;
      if(!lead&&(i>pre1)||flag)//不要在当前状态改变状态量 应该传参
          st=1;
      ans=(ans+dfs(pos-1,limit&&i==a[pos],lead&&i==0,i,st))%MOD; 
   }  
   if(!limit&&!lead)dp[pos][pre1][flag]=ans;
   return ans;
}

int main()
{
   int t;
   scanf("%d",&t);
   memset(dp,-1,sizeof(dp));
   while(t--)
   {    
      scanf("%s",s);
      int len=strlen(s);
      for(int i=0;i<len;++i)
      {
         a[i]=s[len-i-1]-'0'; 
      }
      printf("%lld\n",dfs(len-1,1,1,0,0)-1);
   } 
   return 0; 
}
