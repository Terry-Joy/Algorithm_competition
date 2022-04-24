#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int a[33];
ll dp[33][10][33];

ll dfs(int pos,bool limit,int pre,int sum)
{
   if(pos==-1)return sum;
   if(!limit&&dp[pos][pre][sum]!=-1)return dp[pos][pre][sum];
   int up=limit?a[pos]:1;
   ll ans=0;
   for(int i=0;i<=up;++i)
       ans+=dfs(pos-1,limit&&i==a[pos],i,(pre==1&&i==1)?sum+1:sum);
   if(!limit)dp[pos][pre][sum]=ans;
   return ans;
}

ll solve(int x)
{
   int pos=0;
   while(x)
   {
      a[pos++]=x&1;
      x>>=1; 
   } 
   return dfs(pos-1,1,0,0);
}

int main()
{   
    memset(dp,-1,sizeof(dp));
    int t;
    scanf("%d",&t);
    int k=0;
    while(t--)
    {
       int x;
       scanf("%d",&x);
       printf("Case %d: %lld\n",++k,solve(x)); 
    }
    return 0;
}
