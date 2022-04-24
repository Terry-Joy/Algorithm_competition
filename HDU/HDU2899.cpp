#include<iostream>
using namespace std;
const double esp=1e-8;
double T,y;
bool fx(double x1,double x2,double y)
{
	return 	6*x1*x1*x1*x1*x1*x1*x1+8*x1*x1*x1*x1*x1*x1+7*x1*x1*x1+5*x1*x1-y*x1>6*x2*x2*x2*x2*x2*x2*x2+8*x2*x2*x2*x2*x2*x2+7*x2*x2*x2+5*x2*x2-y*x2;
}
double Fx(double x1)
{
	return 	6*x1*x1*x1*x1*x1*x1*x1+8*x1*x1*x1*x1*x1*x1+7*x1*x1*x1+5*x1*x1-y*x1;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>y;
		double left=0,right=100;
		while(right-left>esp)
		{	
			double mid=(right+left)/2;
			double mid1=mid-esp,mid2=mid;
			if(fx(mid1,mid2,y))
			left=mid;
			else right=mid;
		}
		double k=Fx(left);
		printf("%.4lf\n",k);
	}
	return 0;
} 
