#include<cstdio>
#include<cstring>
#include<cmath> 
const int INF=0x7FFFFFFF; 
int dp[600][600],m,n,x1,y2,z1,minn=0,ans=INF,clo[600][600];
int fx[4]={-1,0,1,0},fy[4]={0,-1,0,1};
using namespace std;
void dfs(int x,int y,int sum,bool flag)
{
	if(x<1||y>m||x>m||y<1)return;
	if(sum>=dp[x][y])return;
	dp[x][y]=sum;
	if(x==m&&y==m)
	{
		if(sum<ans)
		ans=sum;
		return;
	}
	for(int i=0;i<4;++i)
	{
		int xx=fx[i]+x;
		int yy=fy[i]+y;
		if(clo[xx][yy])
		{
			if(clo[x][y]!=clo[xx][yy])
			dfs(xx,yy,sum+1,false);
			else dfs(xx,yy,sum,false);
		}
		else 
		if(!flag)
		{
			clo[xx][yy]=clo[x][y];
			dfs(xx,yy,sum+2,true);
			clo[xx][yy]=0;
		}
	} 
}
int main()
{
	memset(dp,0x7f,sizeof(dp));
	scanf("%d%d",&m,&n);
	while(n--)
	{
		scanf("%d%d%d",&x1,&y2,&z1);
		clo[x1][y2]=z1+1;
	}
	dfs(1,1,0,false);
	printf("%d",ans==INF?-1:ans);
	return 0;
}
