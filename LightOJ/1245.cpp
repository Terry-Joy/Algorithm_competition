#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	ll n;int t,k=1;
	scanf("%d",&t);
	while(t--)
	{
		ll ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=sqrt(n);++i)
		{
			ans+=n/i;
		}
		for(int i=1;i<=sqrt(n);++i)
		{
			int r=n/i,l=(n/(i+1))+1;
				ans+=(r-l+1)*(n/r);	
		}
		if( n/(int)sqrt(n) == (int)sqrt(n))
                   ans-= (n/(int)sqrt(n));
		printf("Case %d: %lld\n",k++,ans);
	}
	return 0;
} 
