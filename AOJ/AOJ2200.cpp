#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int road[210][210],sea[210][210],dp[1005][205],tar[1005];
int n,m,x,y,t,r;string c;
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		memset(road,0x3f,sizeof(road));
		memset(sea,0x3f,sizeof(sea));
		memset(dp,0x3f,sizeof(dp));
		while(m--)
		{
			cin>>x>>y>>t>>c;
			if(c=="S")
				sea[x][y]=sea[y][x]=t;
			else 
				road[x][y]=road[y][x]=t;
		}
		for(int i=1;i<=n;++i)
			road[i][i]=sea[i][i]=0;		
		scanf("%d",&r);
		for(int i=1;i<=r;++i)
			scanf("%d",&tar[i]);
		for(int k=1;k<n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
				{
					road[i][j]=min(road[i][j],road[i][k]+road[k][j]);
					sea[i][j]=min(sea[i][j],sea[i][k]+sea[k][j]);	
				}
		dp[1][tar[1]]=0;
		for(int i=1;i<=r;++i)
			for(int j=1;j<=n;++j)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+road[tar[i-1]][tar[i]]);
				for(int k=1;k<=n;++k)
					dp[i][k]=min((long long)dp[i][k],(long long)dp[i-1][j]+sea[j][k]+road[tar[i-1]][j]+road[k][tar[i]]);
			}
		int ans=0x7f7f7f7f;
		for(int i=1;i<=n;++i)
			ans=min(ans,dp[r][i]);
		printf("%d\n",ans);
	}
	return 0;
}

