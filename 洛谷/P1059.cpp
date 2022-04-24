#include<cstdio>
using namespace std;
int tong[1010];
int main()
{
	int n,k,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&k);
		tong[k]++;
	}
	for(int i=1;i<= 1000;++i)
	{
		if(tong[i]>0)
		ans++;
	}
	printf("%d",ans);
	putchar('\n');
	for(int i=1;i<= 1000;++i)
	{
		if(tong[i]>0)
		printf("%d ",i);
	}
	return 0;
} 
