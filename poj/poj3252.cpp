#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int a[33],dp[33][33][33];

int dfs(int pos,bool limit,bool lead,int sum0,int sum1)
{
   if(pos==-1)return sum0>=sum1;
   if(!limit&&!lead&&dp[pos][sum0][sum1]!=-1)return dp[pos][sum0][sum1];
   int up=limit?a[pos]:1;
   int ans=0;
   for(int i=0;i<=up;++i)
   {
      ans+=dfs(pos-1,limit&&i==a[pos],lead&&i==0,sum0+(i==0&&lead==0),sum1+(i==1)); 
   }
   if(!limit&&!lead)dp[pos][sum0][sum1]=ans;
   return ans;
}

int solve(int x)
{
   int pos=0;
   while(x)
   {
      a[pos++]=x%2;
      x/=2; 
   } 
   return dfs(pos-1,1,1,0,0);
}

int main()
{
   int l,r;
   memset(dp,-1,sizeof(dp));
   scanf("%d%d",&l,&r);
   printf("%d\n",solve(r)-solve(l-1));
   return 0; 
}
