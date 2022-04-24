#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,dp[20][2],a[20];

int dfs(int pos,int pre,int sta,bool limit)
{
    if(pos==-1)return 1;
    if(!limit&&dp[pos][sta]!=-1)return dp[pos][sta];
    int up=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=up;++i)
    {
       if(i==2&&pre==6)continue;
       if(i==4)continue;
       ans+=dfs(pos-1,i,i==6,limit&&i==a[pos]); 
    }
    if(!limit)dp[pos][sta]=ans;
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
   return dfs(pos-1,-1,0,true);
}

int main()
{
    memset(dp,-1,sizeof(dp));       //数位DP中只跟数字本身的性质有关的而与输入无关可以这样初始化
    while(~scanf("%d%d",&n,&m))
    {
       if(n==0&&m==0)break;
       printf("%d\n",solve(m)-solve(n-1)); 
    }
}
