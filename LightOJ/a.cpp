#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll dp[40][40],n,m;
int a[40];

ll dfs(int pos,bool limit,bool lead,int d,ll sum)
{
   if(pos==-1)return sum;
   if(limit==0&&lead==0&&dp[pos][sum]!=-1)return dp[pos][sum];
   ll ans=0;
   int up=limit?a[pos]:9;
   for(int i=0;i<=up;++i)
   {
         ans+=dfs(pos-1,limit&&(i==a[pos]),lead&&(i==0),d,sum+((i==d)&&(lead==0||i))); 
   } 
   if(!limit&&!lead)dp[pos][sum]=ans;
   return ans;
}
ll solve(ll x,int d)
{ 
    memset(dp,-1,sizeof(dp));
    int pos=0;
    while(x)
    {
       a[pos++]=x%10;
       x/=10; 
    }
    return dfs(pos-1,1,1,d,0);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    { 
       scanf("%lld%lld",&n,&m);
       printf("%lld ",solve(m,0)-solve(n-1,0));
    }
   return 0; 
}
