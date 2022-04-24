#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const double pi=3.14159265358979323846;
int main()
{
	int t;
	double r1,r2;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%lf%lf",&r1,&r2);
		double k=atan2(r1,r1+r2); 
		double j2=k*180/pi,j1=90-2*j2;
		printf("%.10lf\n",(r1*(r1+r2)/2)-j2*pi*r2*r2/360-j1*pi*r1*r1/360-cos(j1*pi/180)*r1*r1/2);
	}	
	return 0;
} 
