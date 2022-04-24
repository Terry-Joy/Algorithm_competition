#include<iostream>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
int main()
{
	int t;int k=1;
	LL n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("Case %d: %lld\n",k++,n-(LL)(sqrt(n))-(LL)(sqrt(n/2)));
	}
	return 0;
}  
