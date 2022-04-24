#include<iostream>
#include<cstdio>
#include<cstring> 
#include<queue>
using namespace std;
struct node
{
	int x,y,step;
}s1,s2;
int n,m,yx,yy,mx,my,dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}},step1[202][202],step2[202][202],maxn=0x3f3f3f3f;
char map[202][202];
bool vis[202][202];
void bfs(node s,int step[][202])
{
	queue<node>q;
	node e;
	vis[s.x][s.y]=1;
	q.push(s);
	while(q.size())
	{
		s=q.front();q.pop();
		for(int i=0;i<4;++i)
		{
			e.x=s.x+dir[i][0];
			e.y=s.y+dir[i][1];
			if(!vis[e.x][e.y]&&e.x>=0&&e.x<n&&e.y>=0&&e.y<m&&map[e.x][e.y]!='#')
			{
				vis[e.x][e.y]=1;
				step[e.x][e.y]=step[s.x][s.y]+1;
				q.push(e);
			}
		}
	}
} 
void init()
{
	maxn=0x3f3f3f3f;
	memset(vis,0,sizeof(vis));
	memset(step1,0,sizeof(step1));
	memset(step2,0,sizeof(step2));
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;++i)
		{
			scanf("%s",map[i]);
			for(int j=0;j<m;++j)
			{
				if(map[i][j]=='Y')
				{
					s1.x=i;s1.y=j;
				}
				if(map[i][j]=='M')
				{
					s2.x=i;s2.y=j;
				}
			}
		}
		init();
		bfs(s1,step1);
		memset(vis,0,sizeof(vis));
		bfs(s2,step2);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				if(map[i][j]=='@'&&step1[i][j]!=0&&step2[i][j]!=0)
					maxn=min(maxn,step1[i][j]+step2[i][j]);
			}
			printf("%d\n",maxn*11);
	}
	return 0;
}
