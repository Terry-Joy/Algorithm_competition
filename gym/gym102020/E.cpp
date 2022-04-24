#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=1e9+7;
ll dp[maxn],sum[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],tot=0;
ll n;
void add(int x,int y)
{
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
ll mypow (ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1; 
    } 
    return ans;
}
void dfs(int now,int fa)
{ 
    for(int i=head[now];i;i=next1[i])
    {
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,now);
        sum[now]+=sum[y];
        dp[now]=dp[now]+dp[y]+(sum[y]*(n-sum[y])); 
    }
}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
        sum[i]=1;
    for(int i=1;i<n;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a); 
    }
    dfs(1,0);
    dp[1]%=mod;
    printf("%lld\n",dp[1]*mypow(1ll*n*(n+1)/2%mod,mod-2)%mod);
    return 0; 
}
