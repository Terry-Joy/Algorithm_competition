#include<iostream>
using namespace std;
int a[11][11];
int main()
{
	int n,j,k,flag;
	cin>>n;
	int t=0;
	for(int i=1;i<=n;++i)
	{
		if(i%2==1)
		{
			j=i;
			k=1;
			for(;j>=1;j--,++k)
			{
				t++;
				a[j][k]=t;
			}
		}
		else  
		{
			j=1;
			k=i;
			for(;k>=1;j++,--k)
			{
				t++;
				a[j][k]=t;
			}
		}
	}
	if(n%2==0)
	flag=1;//flag等于1时从左下向右上 
	else flag=0;
	for(int i=1;i<n;++i)
	{
		if(flag==1)
		{
			j=n;
			k=i+1;
			for(;j>=2;--j,++k)
			{
				t++;
				a[j][k]=t;
			}
			flag=0;
		}
		else 
		{
			j=i+1;
			k=n;
			for(;j<=n;++j,--k)
			{
				t++;
				a[j][k]=t;
			}
			flag=1;
		}
	} 
	for(int q=1;q<=n;++q)
	{
		for(j=1;j<=n;++j)
		cout<<a[q][j]<<" ";
		cout<<endl;
	}
	return 0;
} 
