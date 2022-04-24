#include<iostream>
using namespace std;
int ver[],next[],head[],edge[],deg[];//deg统计入度 
void add(int x,int y,int z)
{
	ver[++tot]=y,edge[tot]=z,next[tot]=head[x],head[x]=tot;
	deg[y]++;
}
void topsort()//bfs求拓扑序 
{
	queue<int>q;
	for(int i=1;i<=n;++i)
		if(!deg[i])q.push(i);//预处理入度为0的入队
	while(q.size())
	{
		int x=q.front,q.pop();
		a[++cnt]=x;//a记录拓扑序
		for(int i=head[x];i;i=next[i])
		{
			int y=ver[i];
			if(--deg[i]==0)q.push(y);//将x连向的度-1并判断 
		} 
	} 
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		scanf("%d%d",&x,&y,&z);
		add(x,y,z); 
	}
}
