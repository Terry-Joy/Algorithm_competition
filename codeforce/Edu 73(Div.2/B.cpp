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
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
		{
			if((i+j)&1)
				printf("B");
			else 
				printf("W"); 
		}
		putchar('\n');
	}
	return 0;
} 
