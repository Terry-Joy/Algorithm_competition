#include<iostream>
#include<cstdio>
#define ll long long 
using namespace std;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){x=1,y=0;return a;}
	ll d=exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-y*(a/b);
	return d;
}
int main()
{
	ll a,b,c,k,x,y;
	while(scanf("%lld%lld%lld%lld",&a,&b,&c,&k))
	{
		if(a==0&&b==0&&c==0&&k==0)
			break;
		ll c2=b-a;
		k=(ll)1<<k;
		ll Gcd=exgcd(c,k,x,y);
		if(c2%Gcd!=0){puts("FOREVER");continue;}
		
		x=x*(c2/Gcd);
		k/=Gcd;
		x=(x%k+k)%k;
		printf("%lld\n",x);
		
	}	
	return 0;
}
