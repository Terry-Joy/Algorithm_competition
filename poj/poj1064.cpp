#include<cstdio>
#include<cmath>
using namespace std;
int n,k;
double cable[10010];
const double INF=100010;
bool is_ok(double x)
{
	int sum=0;
	for(int i=0;i<n;++i)
	{
		sum+=int(cable[i]/x);
	}
	return sum>=k;
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
	for(int i=0;i<n;++i)
	scanf("%lf",&cable[i]);
	double l=0,r=INF;
	for(int i=0;i<100;++i)
	{
		double mid=(l+r)/2;
		if(is_ok(mid))
		l=mid;
		else r=mid;
	}
	printf("%.2f\n",floor(l*100)/100);
	}
	return 0;
}
