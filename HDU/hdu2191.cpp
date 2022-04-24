#include<iostream>
#include<cstring>
using namespace std;
int dp[120],n,m,p[120],h[120],c[120],t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(dp,0,sizeof(dp)); 
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
			scanf("%d%d%d",&p[i],&h[i],&c[i]);
		for(int i=1;i<=n;++i)
			for(int k=1;c[i];k<<=1)
			{
				if(c[i]<k)k=c[i];
				c[i]-=k;
				for(int v=n;v>=k*p[i];--v)
				dp[v]=max(dp[v],dp[v-k*p[i]]+k*h[i]);
			}
		printf("%d\n",dp[n]);
	}
	return 0;
}
