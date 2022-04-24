#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
int sum[maxn],a[maxn],t,n,s;
bool is_ok(int mid)
{
	for(int i=1;i+mid-1<=n;++i)
	{
		if(sum[i+mid-1]-sum[i-1]>=s)
		return true;
	}
	return false;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&s);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		if(sum[n]<s)
		{printf("0\n");continue;}
		int left=1,right=n+1;
		while(left<right)
		{	
			int mid=(left+right)/2;
			if(is_ok(mid))right=mid;
			else left=mid+1;
		}
		printf("%d\n",right);
	}
	return 0;
}

