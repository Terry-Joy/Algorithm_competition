#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long 
using namespace std;

int t,A,B,a[15];
int dp[15][4600];//枚举到当前位置后缀<=sum的有几个 
ll num;

int dfs(int pos,bool limit,ll sum)
{
   if(pos==-1)return sum>=0;
   if(sum<0)return 0;//剪枝 
   if(!limit&&dp[pos][sum]!=-1)return dp[pos][sum]; 
   ll ans=0;
   int up=limit?a[pos]:9;
   for(int i=0;i<=up;++i)
       ans+=dfs(pos-1,limit&&(i==a[pos]),sum-(1<<pos)*i);
   if(!limit)dp[pos][sum]=ans;
   return ans; 
}

int solve(int x)
{
   int p=0;
   while(x)
   {
      a[p++]=x%10;
      x/=10; 
   } 
   return dfs(p-1,1,num);
}

int main()
{
   scanf("%d",&t);
   int f=0;
   memset(dp,-1,sizeof(dp));
   while(t--)
   {
      scanf("%d%d",&A,&B);
      num=0;
      int k=1;
      while(A)
      {
          num=num+(A%10*k);
          A/=10; 
          k<<=1; 
      } 
      printf("Case #%d: %d\n",++f,solve(B));
   }
   return 0; 
}
