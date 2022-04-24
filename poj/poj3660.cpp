#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[110][110],n,m;
bool v[110]; 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		dp[a][b]=1; 				//a赢b时则dp[a][b]=1 
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dp[i][j]|=dp[i][k]&dp[k][j];		//传递闭包 
	int ans=n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			{
				if(i==j)
					continue;
				if(dp[i][j]==0&&dp[j][i]==0)		//双向为0时不确定 
				{
					if(!v[i])
					{
						ans--;
						v[i]=1;
					}
					if(!v[j])
					{
						ans--;
						v[j]=1;
					}
				}		
			}
			printf("%d\n",ans);
			return 0;
} 
