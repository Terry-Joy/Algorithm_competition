#include<iostream>
#include<cstdio>
using namespace std;
int dp[3005][3005],a[3005],b[3005];//dp[i][j]��ʾaǰi��Ԫ�غ���b[j]��β��LCIS 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
	{	//val�Ǿ��߼���S(i,j)��dp[i-1][k] �����ֵ 
		int val=0;
		if(b[0]<a[i])val=dp[i-1][0];
		for(int j=1;j<=n;++j)
		{
			if(a[i]==b[j])dp[i][j]=val+1;
			else dp[i][j]=dp[i-1][j];
			if(b[j]<a[i])val=max(val,dp[i-1][j]);//�µ�j����ʱ����С���߼��� ��¼�м����k 
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		ans=max(ans,dp[n][i]);
	printf("%d",ans);
	return 0;
}
