#include<cstdio>
using namespace std;
int map[120][120],visited[120][120];
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct Node
{
	int x,y;
	int f;
}queue[1000];
void print(int head)
{
	while(queue[head].f!=-1)
	{
		print(queue[head].f);
		printf("(%d, %d)\n",queue[head].x,queue[head].y);
		return;
	}
	printf("(0, 0)\n");
}
void bfs()
{
	queue[0]={0,0,-1};
	int head=0,tail=1;
	visited[0][0]=1;
	Node last;
	while(head<tail)
	{
		if(queue[head].x==4&&queue[head].y==4)
		{
			print(head);
			return;
		}
		for(int i=0;i<4;++i)
		{
			last.x=queue[head].x+d[i][0];
			last.y=queue[head].y+d[i][1];
			last.f=head;
			if(last.x>=0&&last.x<=4&&last.y>=0&&last.y<=4)
			{
				if(!visited[last.x][last.y]&&!map[last.x][last.y])
				{
					visited[last.x][last.y]=1;
					
					queue[tail++]=last;
				} 
			}
		}
		head++;
	}
}
int main()
{
	for(int i=0;i<=4;++i)
		for(int j=0;j<=4;++j)
			scanf("%d",&map[i]);
	memset(visited,0,sizeof(visited));
	bfs();
	return 0;		 
}
