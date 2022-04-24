#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=100010;
int barn[maxn],n,c; 
bool is_ok(int x)
{
	int i=0,sum=1;
	while(i<n)
	{
		int temp=barn[i++];
		while(i<n&&barn[i]-temp<x)
		++i;
		if(i<n&&barn[i]-temp>=x)
		sum++;
	}
	return sum>=c;
}
int main()
{
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		for(int i=0;i<n;++i)
		scanf("%d",&barn[i]);
		sort(barn,barn+n);
		int left=-1,right=barn[n-1]-barn[0];
		while(left<right)
		{
			int mid=(right+left+1)/2;
			if(is_ok(mid))
			left=mid;
			else right=mid-1;
		}
		printf("%d\n",left);
	}
	return 0;
}
