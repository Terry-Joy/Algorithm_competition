#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int dp[20][12],n,m,a[20];

int dfs(int pos,int pre,bool limit,bool lead)
{
   if(pos==-1)return 1;
   if(!limit&&!lead&&dp[pos][pre]!=-1)return dp[pos][pre];
   int up=limit?a[pos]:9;
   int ans=0;
   for(int i=0;i<=up;++i)//数位DP必须把所有的状态枚举出来
   {
      if(!lead)                 //没有前导0
      {
         if(abs(i-pre)<2)continue;
         else ans+=dfs(pos-1,i,limit&&i==a[pos],0);//满足题目 
      }
      if(lead&&i)ans+=dfs(pos-1,i,limit&&i==a[pos],0);//有前导0且当前也是0
      if(lead&&i==0)ans+=dfs(pos-1,i,0,1); //有前导然后重新开始
      
   } 
   if(!lead&&!limit)dp[pos][pre]=ans;
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
    return dfs(pos-1,0,true,true);
}   

int main()
{
    scanf("%d%d",&n,&m);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(m)-solve(n-1));
}
