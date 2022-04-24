#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int r,c,dp[200][200],map[200][200],ans=0,x2[4]={0,-1,0,1},y2[4]={-1,0,1,0};
int dfs(int x,int y)
{
	if(dp[x][y])return dp[x][y];
	dp[x][y]=1;
	for(int i=0;i<4;++i)
	{
		int xx=x+x2[i];
		int yy=y+y2[i];
		if(xx>=1&&xx<=r&&yy>=1&&yy<=c&&map[x][y]>map[xx][yy])
		dp[x][y]=max(dp[x][y],dfs(xx,yy)+1);
	}
	return dp[x][y];
}
int main()
{
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;++i)
	for(int j=1;j<=c;++j)
	scanf("%d",&map[i][j]);
	for(int i=1;i<=r;++i)
	for(int j=1;j<=c;++j)
	ans=max(ans,dfs(i,j));
	printf("%d",ans);
	return 0;
}
