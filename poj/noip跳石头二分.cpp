#include<cstdio>
#include<algorithm>
#include<iostream>= 
using namespace std;
int rock[50010];int L,N,M;
bool clear(int x)
{
	int i=0,temp=0,rocks=0;
	while(i<N)
	{
		if(rock[i]-temp<x)
		{
			++i;
			++rocks;
		}
		else 
		{
			temp=rock[i];
			++i;
		}
		if(rocks>M)
		return false;
	}
	return true;
}
int main()
{
	scanf("%d%d%d",&L,&N,&M);
	for(int i=0;i<N;++i)
		scanf("%d",&rock[i]);
	sort(rock,rock+N);
	int left=0,right=L;
	while(left<right)
	{
		int mid=(left+right+1)/2;
		if(clear(mid))
		left=mid;
		else right=mid-1;
	}
	cout<<left;
	return 0;
} 
