#include <bits/stdc++.h>
#define eps 1e-8
#define iinf 0x3f3f3f3f
#define linf (1ll<<60)
#define cl(x) memset(x,0,sizeof(x))
#define mod 998244353ll
#define maxn 300010
using namespace std;
typedef long long ll;
ll read(int x=0)
{
	int c, f=1;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return f*x;
}
ll mypow(ll a, ll b)
{
	ll t=a, ans=1;
	while(b)
    { 
        if(b&1)
        ans=ans*a%mod;
        a=a*a%mod;
    }
	return ans;
}
ll ans=1, n, buf[maxn], a[maxn], k, dp[maxn][2], x[maxn], y[maxn], l1, l2;
ll solve(ll *a, ll len)
{
	if(len==0)return 1ll;
	ll i, ans=1, l, r, j, cnt=0;        
	for(l=1;l<=len and a[l]==-1;l++);
	if(l>len)
	{
		return k*mypow(k-1,len-1)%mod;//两边
	}
	for(r=len;a[r]==-1;r--);            //单边
	ans=ans*mypow(k-1,l-1)%mod;
	ans=ans*mypow(k-1,len-r)%mod;
	for(i=l+1;i<r;i=j+1)
	{
		cnt=0;
		for(j=i;a[j]==-1;j++)cnt++;
		ans=ans*dp[cnt][a[i-1]!=a[j]]%mod;
	}
	return ans;
}
int main()
{
	ll i, j;
    scanf("%lld%lld",&n,&k);
	for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
	for(i=1;i<=n;i+=2)
        x[++l1]=a[i];
	for(i=2;i<=n;i+=2)
        y[++l2]=a[i];
	dp[0][0]=0;
	dp[0][1]=1;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=(k-1)*dp[i-1][1];
		dp[i][1]=dp[i-1][0]+(k-2)*dp[i-1][1];
		dp[i][0]%=mod;
		dp[i][1]%=mod;
	}
	cout<<solve(x,l1)*solve(y,l2)%mod;
	return 0;
}
