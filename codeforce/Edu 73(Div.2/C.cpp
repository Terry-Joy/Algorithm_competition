#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",min(a,min(b,(a+b+c)/3)));
	} 
	return 0;
} 
