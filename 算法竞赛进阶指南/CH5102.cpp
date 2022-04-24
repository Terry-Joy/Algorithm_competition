#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e10-1;	
int dp[1002][210][210],a[1002],c[210][210];
int main()
{
	int l,n;
	scanf("%d%d",&l,&n);
	for(int i=1;i<=l;++i)
		for(int j=1;j<=l;++j)
			scanf("%d",&c[i][j]);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][1][2]=0;
	a[0]=3;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=l;++j)
			for(int k=1;k<=l;++k)
			{
				int last=a[i-1];
				if(k==j||k==last||j==last)continue;
				dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]+c[last][a[i]]);
				dp[i][last][k]=min(dp[i][last][k],dp[i-1][j][k]+c[j][a[i]]);
				dp[i][j][last]=min(dp[i][j][last],dp[i-1][j][k]+c[k][a[i]]);
			}
	}	
	int ans=maxn;
	for(int i=1;i<=l;++i)
		for(int j=1;j<=l;++j)
		{
			int z=a[n];
			if(i==j||z==i||z==j)continue;
			ans=min(ans,dp[n][i][j]);
		}
		printf("%d",ans);
	return 0;
}

