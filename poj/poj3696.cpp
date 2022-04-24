#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
const int maxn=50000;
using namespace std;
bool v[maxn];int prime[maxn],cnt=0;
ll a,t=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
void primes()
{
	v[1]=v[0]=1;
	for(int i=2;i<=maxn;++i)
	{
		if(!v[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=maxn;++j)
		{
			v[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
ll mul(ll a,ll b,ll p)
{
	ll ans=0;
	while(b)
	{
		if(b&1)ans=(ans+a)%p;
		a=a*2%p;b>>=1;
	}
	return ans;
}
ll mypow(ll a,ll b,ll p)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans=mul(ans,a,p);
		a=mul(a,a,p);
		b>>=1;
	}
	return ans;
}
ll phi(ll a)
{
	ll ans=a;
	for(int i=1;i<=cnt&&prime[i]*prime[i]<=a;++i)
	{
		if(a%prime[i]==0)
		{
			ans=ans/prime[i]*(prime[i]-1);
			while(a%prime[i]==0)a/=prime[i];
		}
	}
	if(a>1)ans=ans/a*(a-1);
	return ans;
}
ll number()
{
		a=9*a/(gcd(8,a));
		ll sum=phi(a);
		if(gcd(a,10)!=1){ return 0;}
		else 
		{
			int s=sqrt(sum);
			for(int i=1;i<=s;++i)
				if(sum%i==0&&mypow(10,i,a)==1)
						return i;
			for(int i=s-1;i;--i)
				if(sum%i==0&&mypow(10,sum/i,a)==1)
						return sum/i;
			return 0;
		}
}
int main()
{
	primes();
	while(scanf("%lld",&a)&&a)
	{
		printf("Case %d: %lld\n", ++t, number());
	}
}
