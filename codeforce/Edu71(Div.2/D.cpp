#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#define ll long long 
using namespace std;
const ll mod=998244353;
const int maxn=1e6+10;
ll n,f[maxn];
struct Node
{
	int f1,f2;	
}node[maxn];
bool cmp1(Node a,Node b)
{
	return a.f2<b.f2;
}
bool cmp2(Node a,Node b)
{
	if(a.f1==b.f1)return a.f2<b.f2;
	return a.f1<b.f1;
}
int main()
{
    f[1]=1;
    for(int i=2;i<maxn;++i)f[i]=(f[i-1]*i)%mod;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
		scanf("%d%d",&node[i].f1,&node[i].f2);
	sort(node+1,node+n+1,cmp1);
	ll ans=1,sum=1;
	for(int i=2;i<=n;++i)
	{
		if(node[i].f2==node[i-1].f2)ans++;
		else 
		{
			sum=(sum*f[ans])%mod;
			ans=1;
		}
	}
	sum=sum*f[ans]%mod;
	ans=1;
	sort(node+1,node+n+1,cmp2);
	ll sum2=1;
	for(int i=2;i<=n;++i)
	{
		if(node[i].f1==node[i-1].f1)ans++;
		else 
		{
			sum2=(sum2*f[ans])%mod;
			ans=1;
		}
	}
	sum2=sum2*f[ans]%mod;
	ans=1;
	int flag=0;
	for(int i=2;i<=n;++i)
		if(node[i].f2<node[i-1].f2)
			flag=1;
	if(flag)
		printf("%lld\n",(f[n]-sum-sum2+2*mod)%mod);
	else
	{
		ll sum3=1;
		for(int i=2;i<=n;++i)
		{
			if(node[i].f1==node[i-1].f1&&node[i].f2==node[i-1].f2)
				ans++;
			else 
				{
					sum3=sum3*f[ans]%mod;
					ans=1;
				}
		}
		sum3=f[ans]*sum3%mod;
		printf("%lld\n",(f[n]-sum-sum2+2*mod+sum3)%mod);
	}
	return 0;
}
