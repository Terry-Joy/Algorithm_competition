#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e6+10;
bool v[maxn];
void primes()
{
	memset(v,0,sizeof(v));
	v[1]=v[0]=1;
	for(int i=2;i*i<=maxn;++i)
	{
		if(!v[i])
		{
			for(int j=i*i;j<=maxn;j+=i)
			v[j]=1;
		}
	}
}
int main()
{
	int t;
	primes();
	scanf("%d",&t);
	int k,m=0,q;
	while(t--)
	{
		ll ans=0;
		scanf("%d",&k);
		for(int i=1;i<=k;++i)
		{
			scanf("%d",&q);
			for(int j=q+1;;++j)
			if(!v[j])	
			{
				ans+=j;
				break;
			}
		}
		printf("Case %d: %lld Xukha\n",++m,ans);
	} 
	return 0;
}
