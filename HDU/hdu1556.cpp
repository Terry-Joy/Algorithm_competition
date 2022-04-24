#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int dif[maxn],ans[maxn],n,l,r;
int main()
{
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(dif,0,sizeof(dif));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&l,&r);
			dif[l]++;
			dif[r+1]--;
		}
		for(int i=1;i<=n;++i)
		{
			ans[i]=ans[i-1]+dif[i];
			if(i!=n)
				printf("%d ",ans[i]);
		}
		printf("%d\n",ans[n]);
	}
	return 0;
} 
