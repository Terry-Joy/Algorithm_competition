#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e6+100;
bool v[maxn];ll prime[maxn],cnt=0;
void primes()
{
	memset(v,0,sizeof(v));
	v[1]=v[0]=1;
	
	for(int i=2;i<=maxn;++i)
	{
		if(!v[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=maxn;++j)
		{
			v[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	int t;
	primes();
	scanf("%d",&t);
	int f=0;
	while(t--)
	{
		ll a,b,ans=1;
		scanf("%lld%lld",&a,&b);
		int m=0;
		if(b*b>a){printf("Case %d: 0\n",++f);continue;}
		else
		{
			for(int i=1;prime[i]*prime[i]<=a&&i<=cnt;++i)
			{
					if(a==1)break;
				int temp=0;
				while(a%prime[i]==0)
				{
					temp++;
					a/=prime[i];
				}
				ans*=(temp+1);
				
			}
			if(a>1)	ans*=2;
				ans/=2;
			for(int i=1;i<b;++i)
			{
				if(a%i==0)
				{
					ans--;
				}
			}
		printf("Case %d: %lld\n",++f,ans);
		}
	}
	return 0;
}
