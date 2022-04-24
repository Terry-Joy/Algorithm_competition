#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
ll dp[10][3];
const int maxn=5e7;
int n,a[10];
ll l,r,mid;
ll dfs(int pos,bool limit,int pre)
{
    if(pos==-1)return 1;
    if(!limit&&dp[pos][pre]!=-1)return dp[pos][pre];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;++i)
    { 
        if(i==6&&pre==2)continue;
        ans+=dfs(pos-1,limit&&i==a[pos],(i==6)?pre+1:0);
    }
    if(!limit)dp[pos][pre]=ans;
    return ans;
}
ll solve(ll x)
{
    ll t=x;
    int pos=0;
    while(x)
    {
       a[pos++]=x%10;
       x/=10; 
    }
    return t+1-dfs(pos-1,1,0);
}
int main()
{
   memset(dp,-1,sizeof(dp));
   int t;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       l=666,r=1e10+1;
       while(l<r)
       { 
         mid=(l+r)>>1;
         if(solve(mid)<n)l=mid+1;
         else r=mid;
       }
       printf("%lld\n",r);
   }
   return 0; 
}
