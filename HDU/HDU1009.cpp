#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct fatmouse
{
	int ji;
	int fi;
	double b;
};
fatmouse a[1000000];

bool cmp2(fatmouse x,fatmouse y)
{
	return x.b>y.b;
}
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		if(m==-1&&n==-1)
		break;
		memset(a,0,sizeof(a));
	
		for(int i=0;i<n;++i)
		{
			cin>>a[i].ji>>a[i].fi;
			a[i].b=a[i].ji*1.0/a[i].fi*1.0;
		}
		sort(a,a+n,cmp2);
		double sum=0;
		for(int i=0;i<n;++i)
		{
			if(m>=a[i].fi)
			{
				m-=a[i].fi;
				sum+=a[i].ji;
				
			}
			else if(m<a[i].fi)
			{
				sum+=((m*1.0)/a[i].fi)*a[i].ji;
				break;
			}
		}
		printf("%.3lf\n",sum);
	}
	return 0;
} 
