#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;

ll dp[65][65538];

int a[65];
ll th[65],n,k;

ll dfs(int pos,bool limit,int mod,int d,bool lead)
{
    if(pos==-1)
    {
    	if(lead)
    		return 0;
    	else
			return mod==d;
	} 
    if(!limit&&dp[pos][mod]!=-1)return dp[pos][mod];
    int up=limit?a[pos]:1;
    ll ans=0;
    for(int i=0;i<=up;++i)
        ans+=dfs(pos-1,limit&&i==a[pos],(mod+i*th[pos])%k,d,lead&&i==0);
    if(!limit)dp[pos][mod]=ans;
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
    memset(dp,-1,sizeof(dp));
    ll ans=dfs(pos-1,1,0,0,1);
    for(int i=1;i<=k-1;++i)
        ans^=dfs(pos-1,1,0,i,1);
    return ans;
}

int main()
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%lld%lld",&n,&k);
       th[0]=1;
       for(int i=1;i<=64;++i)
          th[i]=th[i-1]*3%k;
       printf("%lld\n",solve(n)); 
    }
    return 0;
}
