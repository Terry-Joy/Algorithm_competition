#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int dp[1010][1010],wi[1010],vi[1010];
int main()
{
	int n,v,t,ans;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>v;
		for(int i=1;i<=n;++i)
			cin>>vi[i];
		for(int i=1;i<=n;++i)
			cin>>wi[i];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;++i)
		{ 
			for(int j=0;j<=v;++j)
			{
				if(j<wi[i])
					dp[i][j]=dp[i-1][j];
				else 
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-wi[i]]+vi[i]);
			}
		}
		printf("%d\n",dp[n][v]);
	}
	return 0;
}
