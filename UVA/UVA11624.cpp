#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
struct Node
{
	int x,y,step;
	Node(int i,int j,int k):x(i),y(j),step(k){}
};
char map[1002][1002];
bool vis[1002][1002];
int n,r,c,dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int time111[1002][1002],sx,sy;
queue<Node>q;
void fbfs()
{
	while(q.size())
	{
		Node s=q.front();q.pop();
		Node e=s;
		for(int i=0;i<4;++i)
		{
			e.x=s.x+dir[i][0];
			e.y=s.y+dir[i][1];
			if(e.x>=0&&e.x<r&&e.y>=0&&e.y<c&&map[e.x][e.y]!='#'&&!vis[e.x][e.y])
			{
				vis[e.x][e.y]=1;
				e.step=s.step+1;
				time111[e.x][e.y]=e.step;
				q.push(e);
			}
		}
	}
}
int bfs()
{
	queue<Node>p;
	memset(vis,0,sizeof(vis));
		p.push(Node(sx,sy,0));
	vis[sx][sy]=1;
	while(p.size())
	{
		Node s=p.front();p.pop();
		Node e=s;
		if(s.x==0||s.x==r-1||s.y==c-1&&s.y==0)return s.step+1;
		e=s;e.step++;
		for(int i=0;i<4;++i)
		{
			e.x=s.x+dir[i][0];
			e.y=s.y+dir[i][1];
			if(e.x>=0&&e.x<r&&e.y>=0&&e.y<c&&!vis[e.x][e.y]&&map[e.x][e.y]!='#'&&e.step<time111[e.x][e.y])
			{
				vis[e.x][e.y]=1;
				e.step=s.step+1;
				p.push(e);
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&r,&c);
		while(!q.empty()) q.pop();
		memset(time111,INF,sizeof(time111));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<r;++i)
		{
			scanf("%s",map[i]);
			for(int j=0;j<c;++j)
			{
				if(map[i][j]=='F')
				{
					q.push(Node(i,j,0));
					vis[i][j]=1;
					time111[i][j]=0;	
				}
				if(map[i][j]=='J')
				{
					sx=i;
					sy=j;
				}
			} 
		}
		fbfs();
		int ans=bfs();
		if(ans==-1)printf("IMPOSSIBLE\n");
		else printf("%d\n",ans);
	}	
	return 0;
}
