#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e6+2;
const int INF=1e9;
int dp[maxn],pre[maxn],a[maxn];
int main()
{
	int n,m;
	while(~scanf("%d%d",&m,&n))
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			dp[i]=0;
			pre[i]=0;
		}
		int temp;
		for(int i=1;i<=m;++i)
		{
			temp=-INF;
			for(int j=i;j<=n;++j)
			{
				dp[j]=max(dp[j-1]+a[j],pre[j-1]+a[j]);//pre可以给每个i用 
				pre[j-1]=temp;
				temp=max(temp,dp[j]);//j即将增大为j+1 检查j是否能进入新的决策集合 
			}
		}
		printf("%d\n",temp);
	}
	return 0;
} 
