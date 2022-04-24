#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+1000;
bool v[maxn];int prime[maxn],cnt=0;
void primes()
{
	memset(v,0,sizeof(v));
	v[0]=v[1]=1;
	for(int i=2;i<=51000;++i)
	{
		if(!v[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=51000;++j)
		{
			v[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	int t,k=0,l,r;
	scanf("%d",&t);
	primes();
	while(t--)
	{
		int m=0;
		memset(v,0,sizeof(v));
		scanf("%d%d",&l,&r);
		if(l==1)v[0]=1;
		for(int i=1;i<=cnt;++i)
		{
			for(int j=l/prime[i];j<=r/prime[i];++j)
				if(j>1)v[prime[i]*j-l]=1;
		}
		for(int i=l;i<=r;++i)
			if(!v[i-l])++m;
		printf("Case %d: %d\n",++k,m);
	}
	return 0;
}
