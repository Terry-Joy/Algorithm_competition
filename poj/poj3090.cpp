#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
bool v[1010];int prime[1010],cnt=0,phi[1010],sum[1010];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void  primes()
{
	memset(v,0,sizeof(v));
	phi[1]=1;v[1]=v[0]=1;
	for(int i=2;i<=1009;++i)
	{
		if(!v[i])prime[++cnt]=i,phi[i]=i-1;
		for(int j=1;j<=cnt&&prime[j]*i<=1009;++j)
		{
			v[i*prime[j]]=1;
			if(gcd(i,prime[j])==1)phi[i*prime[j]]=phi[i]*phi[prime[j]];
			else phi[i*prime[j]]=phi[i]*prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	primes();
	int n;
	for(int i=2;i<=1009;++i)
		sum[i]=sum[i-1]+phi[i];
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;++i)
	{
		scanf("%d",&n);
		printf("%d %d %d\n",i,n,3+2*sum[n]);
	}
	return 0;
} 
