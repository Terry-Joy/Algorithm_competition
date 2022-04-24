#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node
{
	int x,y;
};
node pre[6][6];
int map[6][6];int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}},vis[6][6];
void print(node a)
{
	if(a.x==0&&a.y==0)
		{
			printf("(0,0)\n");
			return;	
		}
	print(pre[a.x][a.y]);
	printf("(%d,%d)\n",a.x,a.y);
}
void bfs()
{
	queue<node>q;
	node s,e;
	s.x=0,s.y=0,vis[0][0]=1;
	q.push(s);
	while(q.size())
	{
		s=q.front();q.pop();
		if(s.x==4&&s.y==4)print(s);
		for(int i=0;i<4;++i)
		{
			e.x=s.x+dir[i][0];
			e.y=s.y+dir[i][1];
			if(!vis[e.x][e.y]&&e.x<5&&e.x>=0&&e.y<5&&e.y>=0&&map[e.x][e.y]==0)
			{
				pre[e.x][e.y]=s;
				vis[e.x][e.y]=1;
				q.push(e);		
			}
		}
	}
}
int main()
{
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
	scanf("%d",&map[i][j]);
	bfs();
	return 0;
}
