#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[52][52],dp[110][52][52];
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
	for(int j=1;j<=n;++j)
		scanf("%d",&a[i][j]);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m+n-2;++i)
	{
		for(int j=1;j<=min(i+1,m);++j)
		for(int k=1;k<=min(i+1,m);++k)
		{
			if(j==k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[j][i-j+3]);//��ͬͬʱ���� 
			else dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[j][i-j+3]+a[k][i-k+3]);//��ͬͬʱ���� 
			if(j==k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]+a[j][i-j+2]);//��ͬʱͬʱ���� 
			else dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]+a[j][i-j+2]+a[k][i-k+2]);//��ͬʱͬʱ���� 
			if(j==k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[j][i-j+2]);//һ��һ�� 
			else dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[j][i-j+2]+a[k][i-k+3]);
			if(j==k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[j][i-j+3]);
			else dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[j][i-j+3]+a[k][i-k+2]);
		}
	}
	printf("%d",dp[m+n-2][m][m]);
	return 0;
}
