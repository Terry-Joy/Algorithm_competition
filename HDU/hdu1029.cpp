#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a;
	while(~scanf("%d",&n))
	{
		int temp,time=0;
		while(n--)
		{
			scanf("%d",&a);
			if(time<=0)temp=a;
			if(a==temp)time++;
			else time--;
		}
		printf("%d\n",temp);	
	}
	return 0;
} 
