#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
int a[maxn],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int temp=1; 
	for(int i=30;i>=0;--i)//数据范围最多31位 
	{
		int ans=0;
		for(int j=1;j<=n;++j)
		{
			if(((a[j]>>i)&1)==1)//位运算取出每一位 
			{
				ans++;			//判断有几个1 
				temp=j;
				if(ans>1)break;
			}
		}
		if(ans==1)break;
	}
	printf("%d ",a[temp]);
	for(int i=1;i<temp;++i)
		printf("%d ",a[i]);
	for(int i=temp+1;i<=n;++i)
		printf("%d ",a[i]);
	
	return 0;
} 
