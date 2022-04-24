#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long 
using namespace std;
int n;
const int maxn=1e7+10;
const int mod=99999997;
ll a[maxn],b[maxn],a1[maxn],b1[maxn],p[maxn],c[maxn];
bool cmp1(ll x, ll y)
{
	return a[x]<a[y];
}
bool cmp2(ll x,ll y)
{
	return b[x]<b[y];
}
ll ask(ll x)
{
	ll ans=0;
	while(x)
	{
		ans+=c[x];
		ans%=mod;
		x-=x&-x;
	}
	return ans;
}
void add(ll x)
{
	for(;x<=n;x+=x&-x){
		c[x]++;c[x]%=mod;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		a1[i]=i,b1[i]=i;
	}
	for(int i=1;i<=n;++i)
	scanf("%lld",&b[i]);
	sort(a1+1,a1+n+1,cmp1);
	sort(b1+1,b1+n+1,cmp2);
	for(int i=1;i<=n;++i)
		p[b1[i]]=a1[i];
	ll sum=0;
	for(int i=n;i>=1;--i)
	{
		sum+=ask(p[i]-1);
		sum%=mod;
		add(p[i]);
	}
	printf("%lld",sum);
	return 0;
}
