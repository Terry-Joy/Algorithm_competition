#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
const int maxn=1e5+10;
using namespace std;
int n,t,a[2*maxn];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+2*n+1);
		printf("%d\n",a[n+1]-a[n]);	
	} 
	return 0;
} 
