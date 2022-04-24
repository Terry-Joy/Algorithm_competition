#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int d[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,1},{0,0,-1}};//记录方向移动带来的变化 
char map[35][35][35];//层 行 列
bool vis[35][35][35];
int l,r,c,sx,sy,sz,ex,ey,ez;
struct node{
	int x,y,z,step;
};
bool check(int x,int y,int z)
{
	if(x<0 || y<0 || z<0 || x>=l || y>=r || z>=c)
        return 1;
    else if(map[x][y][z] == '#')
        return 1;
    else if(vis[x][y][z])
        return 1;
    return 0;
}
int bfs()
{
	queue<node>q;
	node now,next;
	now.x=sx,now.y=sy,now.z=sz,now.step=0;
 	q.push(now),vis[now.x][now.y][now.z]=1;
 	while(q.size())
 	{
 		now=q.front();q.pop();
 		if(now.x==ex&&now.y==ey&&now.z==ez)return now.step;
 		for(int i=0;i<6;++i)
 		{
 			next=now;
			next.x=now.x+d[i][0];
			next.y=now.y+d[i][1];
			next.z=now.z+d[i][2];
			if(check(next.x,next.y,next.z))
                continue;
            vis[next.x][next.y][next.z] = 1;
            next.step = now.step+1;
            q.push(next);
		 }
	 }
	 return 0;
}
int main()
{
	while(scanf("%d%d%d",&l,&r,&c)&&(l+r+c))
	{
		for(int i=0;i<l;++i)
		{
			for(int j=0;j<r;++j)
			{
				scanf("%s",map[i][j]);
				for(int k=0;k<c;++k)
				{
					if(map[i][j][k]=='S')//记录起点 
					{
						sx=i,sy=j,sz=k;
					} 
					else if(map[i][j][k]=='E')
					{
						ex=i,ey=j,ez=k;
					}	//记录终点 
				}	
			}
		}
		memset(vis,0,sizeof(vis));//重新初始化 
		 int ans;
        ans = bfs();
        if(ans)
            printf("Escaped in %d minute(s).\n",ans);
        else
            printf("Trapped!\n");
	}
	return 0;
} 
