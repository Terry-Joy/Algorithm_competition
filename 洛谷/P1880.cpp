#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int fi[400][400],sum[400],a[400];
int main()
{
	int n;
	scanf("%d",&n);
	memset(fi,0x3f,sizeof(fi));
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		fi[i][i]=0;
	}
	
	for(int len=2;len<=n;++len)
	{
		for(int l=1;l<=n-len+1;++l)
		{
			int r=l+len-1;
			for(int k=l;k<r;++k)
			{
				fi[l][r]=min(fi[l][r],fi[l][k]+fi[k+1][r]+sum[r]-sum[l-1]);
			}
		}
	}
	printf("%d\n",fi[1][n]);
	return 0;
} 
