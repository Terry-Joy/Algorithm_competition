#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const double maxn=1e12;
double f[160][160],m[160],r2,temp;char c;
int n,x[160],y[160];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{	
		 	scanf("%c",&c);
			if(c=='1')
				f[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			else
				f[i][j]=maxn;
		}
		f[i][i]=0;
	} 
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			if(i!=j&&i!=k&&j!=k)
			if(f[i][k]<maxn-1&&f[k][j]<maxn-1)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	memset(m,0,sizeof(m));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(f[i][j]<maxn)
				m[i]=max(m[i],f[i][j]);
	double minx=1e20;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j&&f[i][j]>maxn-1)
			{
				temp=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));;
				minx=min(minx,m[i]+m[j]+temp);	
			} 
	int r=0;
	for(int i=1;i<=n;++i)
	minx=max(minx,m[i]);
	printf("%.6lf",minx);
	return 0;
}
