#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=1010;
const int M=4010;
int head[N],next[M],ver[M],edge[M],t,n,tot,d[N];//记得开两倍 
bool v[N];
typedef pair<int,int>P;
priority_queue<P,vector<P>,greater<P> >q; 
void add(int x,int y,int z)
{
	ver[++tot]=y,edge[tot]=z,next[tot]=head[x],head[x]=tot;
}
void dijkstra()
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[n]=0;q.push(make_pair(0,n));
	while(q.size())
	{
		int x=q.top().second;q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=next[i])
		{
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				q.push(make_pair(d[y],y));
			}
		}
	}
}
int main()
{
		scanf("%d%d",&t,&n);
		int a,b,c;
		for(int i=1;i<=t;++i)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
		}
		dijkstra();
		printf("%d\n",d[1]);
	return 0;
} 
