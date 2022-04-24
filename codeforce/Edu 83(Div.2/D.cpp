#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll mod=998244353; 
ll mypow(ll a,ll b)
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
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){x=1,y=0;return a;}
	ll d=exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-y*(a/b);
	return d;
}
ll inv(ll a,ll mod)
{
	ll x,y;
	ll d=exgcd(a,mod,x,y);
	if(d==1)
		return (x%mod+mod)%mod;
	else
		return -1;
}
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll nn=n-1;
	ll sum=0;
	ll a=1,b=1;int f=1;
	for(ll i=m;i>=m-nn+1;i--)
	{
		a*=i;a%=mod;
		b*=m-i+1;b%=mod;
	}
	sum=a*inv(b,mod)%mod;
	ll k=(n-2)*mypow(2,n-3)%mod;
	sum=sum*k%mod;
	printf("%lld\n",sum);
	return 0;
}
