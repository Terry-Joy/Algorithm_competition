#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e6+5;
bool v[maxn];int prime[maxn/10],phi[maxn],cnt=0;long long sum[maxn];
void primes()
{
	v[0]=v[1]=1,phi[1]=1;
	for(int i=2;i<=maxn;++i)
	{
		if(!v[i])prime[++cnt]=i,phi[i]=i-1;
		for(int j=1;j<=cnt&&prime[j]*i<=maxn;++j)
		{
			v[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				phi[prime[j]*i]=phi[i]*prime[j];
				break;
			}
			else phi[prime[j]*i]=phi[i]*phi[prime[j]];
		} 
	}
}
int main()
{
	primes();
	for(int i=2;i<=maxn;++i)
		sum[i]=sum[i-1]+phi[i];
	int n;
	while(~scanf("%d",&n)&&n)
	{
		printf("%lld\n",sum[n]);
	}
	return 0;
}
