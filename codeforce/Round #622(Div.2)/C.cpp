#include<iostream>
#include<cstdio>
#define ll long long 
using namespace std;
int a[1010],b[1010],ans2[1010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)b[j]=0;
		b[i]=a[i];
		for(int j=i-1;j>=1;--j)b[j]=min(a[j],b[j+1]);
		for(int j=i+1;j<=n;++j)b[j]=min(a[j],b[j-1]);
		ll sum=0;
		for(int j=1;j<=n;++j)
			sum+=b[j];
		if(sum>ans)
		{
			ans=sum;
			for(int k=1;k<=n;++k)
				ans2[k]=b[k];
		}
	}
	for(int i=1;i<=n;++i)
		printf("%d ",ans2[i]);
	return 0;
}
