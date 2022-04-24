#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long 
using namespace std;

int dp[35][11][2][15],a[35];//dp[pos][pre][is][mod]表示到第k位前面一位是什么 是否出现了13 余数是什么

int dfs(int pos,bool limit,int pre,int mod,bool is)//状态表示要完全
{
   if(pos==-1)return (mod==0&&is);
   if(!limit&&dp[pos][pre][is][mod]!=-1)return dp[pos][pre][is][mod];
   int up=limit?a[pos]:9;
   int ans=0;
   for(int i=0;i<=up;++i)
        ans+=dfs(pos-1,limit&&(i==a[pos]),i,(mod*10+i)%13,is||(pre==1&&i==3));
   if(!limit)
       dp[pos][pre][is][mod]=ans;
   return ans;
}

int solve(int x)
{
    int pos=0;
    while(x)
    {
       a[pos++]=x%10;
       x/=10; 
    }
    return dfs(pos-1,1,0,0,0);
}

int main()
{
   memset(dp,-1,sizeof(dp)); 
   int n;
   while(~scanf("%d",&n))
   {
      printf("%d\n",solve(n)); 
   }
   return 0; 
}
