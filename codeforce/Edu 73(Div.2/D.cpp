#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
const int maxn=3e5+5;
const ll INF=1e18+2;
int a[maxn],cost[maxn];ll dp[maxn][3];
int main()
{
	int q,n;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d%d",&a[i],&cost[i]);
		for(int i=1;i<=n;++i)
			for(int j=0;j<3;++j)
				dp[i][j]=INF;
		dp[0][0]=dp[0][1]=dp[0][2]=0;
		for(int i=1;i<=n;++i)
		{
			for(int k=0;k<3;++k)
			{
				for(int j=0;j<3;++j)
				{
					if(a[i]+j!=a[i-1]+k)
					{
						dp[i][j]=min(dp[i][j],dp[i-1][k]+j*cost[i]);
					} 
				}
			}
		}
		ll ans=INF; 
		for(int i=0;i<2;++i)
		 ans=min(ans,dp[n][i]);
		 printf("%lld\n",ans);
	}
	return 0;
} 
