#include<cstdio>
using namespace std;
const int maxn=5e5+10;
long long a[maxn],a_sum[maxn],n,k,b,m=0;
double answer(int x)
{
	return (double)a[m]-(double)(a_sum[x]+a[m])*1.0/(x+1)*1.0;
}
int main()
{
	scanf("%d",&n);
	a_sum[0]=0;
	while(n--)
	{
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d",&b);
			a[++m]=b;
			a_sum[m]=a_sum[m-1]+a[m];
		}
		else
		{
			int left=0,right=m-1;
			while(left<right)
			{
				int mid=(left+right+1)>>1;
				int mid1=mid-1;
				if(answer(mid1)<answer(mid))
				left=mid;
				else
				right=mid-1;
			}
			printf("%.8lf\n",answer(left));
		}
	}
	return 0;
}
