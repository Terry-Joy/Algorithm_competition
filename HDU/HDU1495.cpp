#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int s,n,m;
struct node
{
	int x,y,z,step;
};
bool vis[102][102][102];
int bfs()
{
	if(s%2==1)return -1;
	
	queue<node>q;
	memset(vis,0,sizeof(vis));
	node now,next;
	now.x=s;now.y=now.z=now.step=0;
	q.push(now);
	int s2=s/2;
	vis[now.x][now.y][now.z]=1;
	while(q.size())
	{
		now=q.front();q.pop();
		next=now;next.step++;
		if((now.y==now.z&&now.y==s2)||(now.x==s2&&now.x==now.z)||(now.y==s2&&now.y==now.x))
			return now.step;
		if(now.x&&n>now.y)//x->y
		{
			if(now.x<=n-now.y)
			{
				next.x=0;next.y=now.y+now.x;next.z=now.z;
			}
			else{
				next.x=now.x-n+now.y;next.y=n;next.z=now.z;
			}
			if(!vis[next.x][next.y][next.z])
			{
				vis[next.x][next.y][next.z]=1;
				q.push(next);
			}
		}
		if(now.x&&now.z<m)//x->z
		{
			if(now.x<=m-now.z)
			{
				next.x=0;next.y=now.y;next.z=now.z+now.x;
			}
			else{
				next.x=now.x-m+now.z;next.y=now.y;next.z=m;
			}
			if(!vis[next.x][next.y][next.z])
			{
				vis[next.x][next.y][next.z]=1;
				q.push(next);
			}
		}
		if(now.y&&now.x<s)//y->x
		{
			if(now.y<=s-now.x)
			{
				next.x=now.x+now.y;next.y=0;next.z=now.z;
			}
			else{
				next.x=s;next.y=now.y+now.x-s;next.z=now.z;
			}
			if(!vis[next.x][next.y][next.z])
			{
				vis[next.x][next.y][next.z]=1;
				q.push(next);
			}
		}
		if(now.y&&now.z<m)//y->z
		{
			if(now.y<=m-now.z)
			{
				next.x=now.x;next.y=0;next.z=now.z+now.y;
			}
			else{
				next.x=now.x;next.y=now.y+now.z-m;next.z=m;
			}
			if(!vis[next.x][next.y][next.z])
			{
				vis[next.x][next.y][next.z]=1;
				q.push(next);
			}
		}
		if(now.z&&now.x<s)//z->x
		{
			if(now.z<=s-now.x)
			{
				next.x=now.x+now.z;next.y=now.y;next.z=0;
			}
			else{
				next.x=s;next.y=now.y;next.z=now.z+now.x-s;
			}
			if(!vis[next.x][next.y][next.z])
			{
				vis[next.x][next.y][next.z]=1;
				q.push(next);
			}
		}
		if(now.z&&now.y<n)//z->y
		{
			if(now.z<=n-now.y)
			{
				next.x=now.x;next.y=now.y+now.z;next.z=0;
			}
			else{
				next.x=now.x;next.y=n;next.z=now.z+now.y-n;
			}
			if(!vis[next.x][next.y][next.z])
			{
				vis[next.x][next.y][next.z]=1;
				q.push(next);
			}
		}
	}
	return -1;
}
int main()
{
	while(~scanf("%d%d%d",&s,&n,&m)&&(s+n+m))
	{
		int ans=bfs();
		if(ans==-1)
			printf("NO\n");
		else
			printf("%d\n",ans);
	}	
} 
