#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll x2,y2,m,n,l,x,y;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){x=1;y=0;return a;}
	ll d=exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-(a/b)*y;
	return d;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld",&x2,&y2,&m,&n,&l);
	ll g=exgcd(n-m,l,x,y);
	x=x*(x2-y2)/g;
	x=(x%l+l)%l;
	if((x2-y2)%g==0)printf("%lld",x);
	else printf("Impossible");
	return 0;	
} 
