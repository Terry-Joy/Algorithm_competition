#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e7+100;
int n;
bool v[maxn];int prime[maxn],phi[maxn],cnt=0;
ll sum[maxn];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
void primes()
{
	memset(v,0,sizeof(v));
	v[1]=v[0]=1;phi[1]=1;
	for(int i=2;i<=n;++i)
	{
		if(!v[i])phi[i]=i-1,prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=n;++j)
		{
			v[prime[j]*i]=1;
			if(gcd(prime[j],i)==1)phi[prime[j]*i]=phi[prime[j]]*phi[i];//欧拉函数性质筛，互质 
			else phi[i*prime[j]]=phi[i]*prime[j];//不互质 
			if(i%prime[j]==0)break; 
		}
	}	
}
int main()
{
	scanf("%d",&n);
	primes();
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+phi[i];
	ll ans=0;
	for(int i=1;i<=cnt&&prime[i]<=n;++i)
		ans+=((sum[n/prime[i]]<<1)-1);
	printf("%lld",ans);		
	return 0;
}
