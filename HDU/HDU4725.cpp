#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=2e5+5,M=1e6+1000,INF=0x3f3f3f3f;
typedef pair<int,int>P;
priority_queue<P,vector<P>,greater<P> >q;
int head[M],ver[M],edge[M],next11[M],tot,n,m,c,d[M],cnt[M];
bool v[M];
void add(int x,int y,int z)
{
	ver[++tot]=y,edge[tot]=z,next11[tot]=head[x],head[x]=tot;
}
void dijkstra()
{
	for(int i=0;i<=2*n;++i){d[i]=INF,v[i]=0;}
	d[1]=0;
	q.push(make_pair(0,1));
	while(q.size())
	{
		int x=q.top().second;q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=next11[i])
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
	int t,a,k=1;
	scanf("%d",&t);
	while(t--)
	{
		tot=0;
		for(int i=0;i<=2*n+1;++i)
			head[i]=0;
		scanf("%d%d%d",&n,&m,&c);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&cnt[i]);
		}	
		for(int i=1;i<=n;++i)
		{
			add(n+cnt[i],i,0);//层与该层的点 
			if(cnt[i]>1)
				add(i,cnt[i]+n-1,c);//与上层层点建边 
			if(cnt[i]<n)
				add(i,cnt[i]+n+1,c);//与下层层点建边 
		} 
		for(int i=1;i<=m;++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		dijkstra();
		if(d[n]>=INF)
			printf("Case #%d: -1\n",k++);
		else 
			printf("Case #%d: %d\n",k++,d[n]);
	}
	return 0;
} 
