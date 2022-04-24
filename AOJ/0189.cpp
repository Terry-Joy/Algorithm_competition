#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e9;
int dp[50][50],n,m,a,b,c,num,sum,ans;
int main()
{
	while(cin>>n&&n)
	{
		m=0;	
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				dp[i][j]=maxn;
		for(int i=0;i<n;++i)
		{
			dp[i][i]=0;
			cin>>a>>b>>c;
			dp[a][b]=dp[b][a]=c;
			m=max(m,max(a,b));
		}
		for(int k=0;k<=m;++k)
			for(int i=0;i<=m;++i)
				for(int j=0;j<=m;++j)
		dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		sum=maxn,ans=0;
		for(int i=0;i<=m;++i)
		{
			num=0;
			for(int j=0;j<=m;++j)
				num+=dp[i][j];
			if(num<sum)
			{
				sum=num;
				ans=i;
			}
		}
		cout<<ans<<" "<<sum<<endl;
	}
	return 0;
}
