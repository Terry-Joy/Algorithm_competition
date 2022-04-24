#include<iostream>
#include<cstring>
using namespace std;
int dp[1010],a[1010];
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		a[0]=0;
		for(int i=1;i<=n;++i)
		{
			for(int k=0;k<i;++k)
			{
				if(a[k]<a[i])
					dp[i]=max(dp[k]+a[i],dp[i]);
			}
			
		}
		int ans=0;
		for(int i=1;i<=n;++i)
			ans=max(dp[i],ans);
		printf("%d\n",ans);
	}
	return 0;
} 
