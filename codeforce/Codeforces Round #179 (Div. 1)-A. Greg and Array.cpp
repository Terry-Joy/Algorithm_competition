#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int n,m,k;ll t[maxn],t2[maxn];ll a[maxn];int x,y;//t[i]表示把[i,n]的操作做一遍 
struct op
{
	int l,r;
	ll d;
}o[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;++i)
		scanf("%d%d%lld",&o[i].l,&o[i].r,&o[i].d);
	for(int i=1;i<=k;++i)
	{
		scanf("%d%d",&x,&y);
		t[x]++;		
		t[y+1]--;		
	}
	ll sum=0;
	for(int i=1;i<=m;++i)
	{
		sum+=t[i];
		o[i].d*=sum;	
	}
	for(int i=1;i<=m;++i)
	{
		t2[o[i].l]+=o[i].d;
		t2[o[i].r+1]-=o[i].d; 
	}
	sum=0;
	for(int i=1;i<=n;++i)
	{
		sum+=t2[i];
		printf("%lld ",a[i]+sum);
	}
	return 0;
}
		

