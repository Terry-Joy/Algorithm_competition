#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int n,p;
const int maxn=3e6+100;
ll inv[maxn]={0,1};
int main()
{
	scanf("%d%d",&n,&p);
	printf("1\n");
	for(int i=2;i<=n;++i)
	{
		inv[i]=(ll)(p-p/i)*inv[p%i]%p;//+p是为了保证最小非负 
		printf("%lld\n",inv[i]);
	}
	return 0;
} 
