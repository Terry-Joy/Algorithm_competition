#include<iostream>
#include<cstdio>
using namespace std;
int n,m,t,dp[2][210][210][2],s,now,pre=1;
char a[1010],b[201];
const int mod=1000000007;
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;++i)
	{
		swap(now,pre);
		dp[now][1][1][0]=s;
		if(a[i]==b[1])dp[now][1][1][1]=1,++s;
		for(int j=2;j<=m;++j)
		{
			for(int k=1;k<=t;++k)
			{
				if(a[i]==b[j])
				{
					dp[now][j][k][1]=((dp[pre][j-1][k-1][1]+dp[pre][j-1][k][1])%mod+dp[pre][j-1][k-1][0])%mod;
				}
				dp[now][j][k][0]=(dp[pre][j][k][0]+dp[pre][j][k][1])%mod;
			}
		}
		for(int j=1;j<=m;++j)
			for(int k=1;k<=t;++k)
				dp[pre][j][k][1]=dp[pre][j][k][0]=0;
	}
	printf("%d",(dp[now][m][t][1]+dp[now][m][t][0])%mod);
	return 0;
}
