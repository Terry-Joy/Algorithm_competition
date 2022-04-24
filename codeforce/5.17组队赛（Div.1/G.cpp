#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<stack>
#include<string>
#include<map>
#define ll long long 
using namespace std;
ll dp[100][5];
int a[100];
ll dfs(int pos,bool limit,int mod)
{ 
    if(pos==-1)
        return mod==0;
    if(!limit&&dp[pos][mod]!=-1)return dp[pos][mod];
    int up=limit?a[pos]:1;
    ll ans=0;
    for(int i=0;i<=up;++i)
        ans+=dfs(pos-1,limit&&i==a[pos],(mod+i)%3);
    if(!limit)
        dp[pos][mod]=ans;
    return ans;    
}
int main()
{
    ll n;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%lld",&n))
    { 
        ll x=n;
        int pos=0;
        while(x)
        {
           a[pos++]=x%2;
           x/=2; 
        }
        printf("Day %lld: Level = %lld\n",n,dfs(pos-1,1,0)-1);
    }
    return 0;
}
