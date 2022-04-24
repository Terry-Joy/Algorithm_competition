#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=100010;
const int INF=1e7+5;
int n,k;
struct jewel
{
	int index;
	double vi,wi,yi;
}a[maxn];
bool cmp1(const jewel&x,const jewel&y)
{
	return x.yi>y.yi;
}
bool is_ok(double x)
{
	double  sum=0;
	for(int i=0;i<n;++i)
	a[i].yi=a[i].vi-x*a[i].wi;
	sort(a,a+n,cmp1);
	for(int i=0;i<k;++i)
	sum+=a[i].yi;
	return sum>=0;
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
	for(int i=0;i<n;++i)
		{
		scanf("%lf%lf",&a[i].vi,&a[i].wi);
		a[i].index=i+1;
		}
	double left=0,right=INF;
	for(int i=0;i<50;++i)
	{
		double mid=(left+right)/2;
		if(is_ok(mid))
			left=mid;
		else 
			right=mid;
	}
	for(int i=0;i<k-1;++i)
		cout<<a[i].index<<" ";
		cout<<a[k-1].index<<"\n";
	}
	return 0;
}
