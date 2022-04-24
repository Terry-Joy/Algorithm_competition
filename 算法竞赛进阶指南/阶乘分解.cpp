#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long 
const int maxn=1e6+100;
int prime[maxn],cnt=0;bool v[maxn];
using namespace std;
void init(int n)
{
	memset(v,0,sizeof(v));
	v[1]=v[0]=1;
	for(int i=2;i<=n;++i)
	{
		if(!v[i]){prime[++cnt]=i;}
		for(int j=1;j<=cnt&&prime[j]*i<=n;++j)
		{
			v[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	init(n);
	for(int i=1;i<=cnt;++i)
	{
		ll ans=0;
		ll p=prime[i];
		printf("%lld ",p);
		while(p<=n)
		{
			ans+=n/p;
			p*=prime[i];	
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
