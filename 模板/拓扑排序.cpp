#include<iostream>
using namespace std;
int ver[],next[],head[],edge[],deg[];//degͳ����� 
void add(int x,int y,int z)
{
	ver[++tot]=y,edge[tot]=z,next[tot]=head[x],head[x]=tot;
	deg[y]++;
}
void topsort()//bfs�������� 
{
	queue<int>q;
	for(int i=1;i<=n;++i)
		if(!deg[i])q.push(i);//Ԥ�������Ϊ0�����
	while(q.size())
	{
		int x=q.front,q.pop();
		a[++cnt]=x;//a��¼������
		for(int i=head[x];i;i=next[i])
		{
			int y=ver[i];
			if(--deg[i]==0)q.push(y);//��x����Ķ�-1���ж� 
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
