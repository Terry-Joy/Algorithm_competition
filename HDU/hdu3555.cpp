#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;

ll dp[66][11][2];
int a[66];

ll dfs(int pos,int pre,bool is,bool limit)
{
   if(pos==-1)return is;
   if(limit==0&&dp[pos][pre][is]!=-1)return dp[pos][pre][is];//状态表示要完全
   int up=limit?a[pos]:9;
   ll ans=0;
   for(int i=0;i<=up;++i)
   {
       ans+=dfs(pos-1,i,is||(pre==4&&i==9),limit&&i==a[pos]); 
   } 
   if(!limit)dp[pos][pre][is]=ans;
   return ans;
}

ll solve(ll x)
{ 
    int pos=0;
    while(x)
    {
       a[pos++]=x%10;
       x/=10; 
    }
    return dfs(pos-1,0,0,1);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int t;
    scanf("%d",&t);
    while(t--)
    {
       ll n;
       scanf("%lld",&n);
       printf("%lld\n",solve(n)); 
    }
}
