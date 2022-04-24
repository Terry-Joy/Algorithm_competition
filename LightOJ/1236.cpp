#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e6+5;
bool v[10000005];ll prime[maxn],cnt=0;
void primes()
{
	memset(v,0,sizeof(v));
	v[1]=v[0]=1;
	for(ll i=2;i<=10000005;++i)
	{
		if(!v[i])prime[++cnt]=i;
	 	for(int j=1;j<=cnt&&prime[j]*i<=10000005;++j)
		{
			v[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	primes();
	int t,k=0;
	scanf("%d",&t);
	while(t--)
	{
		ll n,ans=1,sum;
		scanf("%lld",&n);
		for(ll i=1;i<=cnt&&prime[i]*prime[i]<=n;++i)
		{
				sum=0;	
			if(n%prime[i]==0)
			{
				while(n%prime[i]==0){n/=prime[i],sum++;} 
			}
			ans*=(2*sum+1); 
		}
		if(n>1)ans*=3;
		ans=ans/2+1;
		printf("Case %d: %lld\n",++k,ans);
	}
	return 0;
} 
