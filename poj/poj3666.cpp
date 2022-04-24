#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int dp[2002][2002];int a[2002],b[2002];	
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];	
	}
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		int temp=dp[i-1][0];
		for(int j=1;j<=m;++j)
		{
			temp=min(temp,dp[i-1][j]);
			dp[i][j]=temp+abs(a[i]-b[j]);
		}
	}
	int ans=1<<30;
	for(int i=1;i<=m;++i)
		ans=min(ans,dp[n][i]);
	printf("%d",ans);
	
}
