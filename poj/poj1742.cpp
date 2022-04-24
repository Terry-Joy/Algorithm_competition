#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool dp[100002];int a[110],c[110],n,m;
int main()
{
	while(~scanf("%d%d",&n,&m)&&(n|m))
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
			scanf("%d",&c[i]);
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=n;++i)
		{
			if(a[i]*c[i]>m)				//二进制完全背包优化 
			for(int j=a[i];j<=m;++j)
			{
				dp[j]|=dp[j-a[i]];
				continue;
			}
			for(int k=1;c[i];k<<=1)
			{
				if(c[i]<k)k=c[i];
				c[i]-=k;
				int na=k*a[i],nc=k*c[i];
				for(int t=m;t>=na;--t)
					dp[t]|=dp[t-na];
			}
		}
		int ans=0;
		for(int i=1;i<=m;++i)
			ans+=dp[i];
		printf("%d\n",ans);
	}
	return 0;
}
