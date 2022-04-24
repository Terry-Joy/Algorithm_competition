#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;

ll dp[40][40];
ll a[40];

ll dfs(int pos,bool limit,bool lead,ll sum)
{
    if(pos==-1)return lead?1:sum;
    if(lead==0&&limit==0&&dp[pos][sum]!=-1)return dp[pos][sum];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;++i)
    {
       ans+=dfs(pos-1,limit&&(i==a[pos]),lead&&(i==0),sum+((i==0)&&(lead==0))); 
    }
    if(!limit&&!lead)dp[pos][sum]=ans;
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
   return dfs(pos-1,1,1,0);
}

int main()
{ 
    int t;
    ll n,m;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    int k=0;
    while(t--)
    {
       scanf("%lld%lld",&n,&m); 
           printf("Case %d: %lld\n",++k,solve(m)-solve(n-1));
    }
    return 0;
}
