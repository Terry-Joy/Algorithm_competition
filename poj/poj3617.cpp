#include<cstdio>
#include<iostream>
using namespace std;
int N;char cow[2010];
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
	for(int i=0;i<N;++i)
	scanf(" %c",&cow[i]);
	int l=0,r=N-1,ans=0;
	while(l<=r)
	{
		bool is=false;
		for(int i=0;l+i<=r;++i)
		{
			if(cow[l+i]<cow[r-i])
			{
				is=true;
				ans++;
				break;
			}
			else if(cow[l+i]>cow[r-i])
			{
				is=false;
				ans++;
				break;
			}
		}
		if(is)
		putchar(cow[l++]);
		else putchar(cow[r--]);
		if(ans%80==0)
		putchar('\n');
	}
	}
	return 0;
} 
