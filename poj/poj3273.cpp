#include<cstdio>
#include<iostream> 
using namespace std;
const int maxn=1e6+5;
double money[maxn];
int n,k;
double INF=1e4+2;
bool is_ok(double x)
{
	int ans=money[0],sum=1;//防最后一个 
	for(int i=1;i<n;++i)
	{
		if(money[i]+ans<=x)
		ans+=money[i];
		else 
		{
			ans=money[i];
			sum++;
		}
	}
	return sum>k;
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
	double num=0;
	double left;
	for(int i=0;i<n;++i)
	{
		scanf("%lf",&money[i]);
		if(left<money[i])
		left=money[i];
		num+=money[i];
	}
	double right=num;
	int mid;
	for(int i=0;i<100;++i)
	{
		mid=(left+right)/2;
		if(is_ok(mid))
		left=mid+1;
		else right=mid-1;
	}
	cout<<left<<"\n";
	}
	return 0;
}
