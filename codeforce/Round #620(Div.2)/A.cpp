#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) 
	{
		ll x,y,a,b;
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		if((y-x)%(a+b)==0)printf("%lld\n",(y-x)/(a+b));
		else printf("-1\n");
	}
	return 0;
} 
