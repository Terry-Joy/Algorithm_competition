#include<iostream>
#include<cstdio>
using namespace std;
int dp[3005][3005],a[3005],b[3005];//dp[i][j]表示a前i个元素和以b[j]结尾的LCIS 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
	{	//val是决策集合S(i,j)中dp[i-1][k] 的最大值 
		int val=0;
		if(b[0]<a[i])val=dp[i-1][0];
		for(int j=1;j<=n;++j)
		{
			if(a[i]==b[j])dp[i][j]=val+1;
			else dp[i][j]=dp[i-1][j];
			if(b[j]<a[i])val=max(val,dp[i-1][j]);//新的j进入时，缩小决策集合 记录中间变量k 
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,dp[n][i]);
	printf("%d",ans);
	return 0;
}
