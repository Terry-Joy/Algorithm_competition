#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e7+7;
int a[64];
ll dp[55][55];

ll dfs(int pos,bool limit,int sum)
{ 
    if(pos==-1)return max(1,sum);
    if(!limit&&~dp[pos][sum])return dp[pos][sum];
    ll ans=1;
    int up=limit?a[pos]:1;
    for(int i=0;i<=up;++i)
        ans=(ans*dfs(pos-1,limit&&i==a[pos],i==1?sum+1:sum)%MOD);
    if(!limit)dp[pos][sum]=ans;
    return ans;
}

ll solve(ll x)
{
    int pos=0;
    while(x)
    {
       a[pos++]=x&1;
       x>>=1; 
    }    
    return dfs(pos-1,1,0);
}

int main()
{
   ll x;
   memset(dp,-1,sizeof(dp));
   scanf("%lld",&x);
   printf("%lld",solve(x));
   return 0; 
}
