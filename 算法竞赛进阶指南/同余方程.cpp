#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll x,y;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){x=1,y=0;return a;}
	ll d=exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-(a/b)*y;
	return d;
}
int main()
{
	ll a,b;
	scanf("%lld%lld",&a,&b);
	ll gcd=exgcd(a,b,x,y);
	ll x0=x*(1/gcd);
	b/=gcd;
	x0=(x0%b+b)%b;
	printf("%lld",x0);
	return 0;
}
