#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=1e4+1000;
const int INF=1e9;
int ver[maxn],edge[maxn],head[maxn],next[maxn],v[maxn],d[maxn],cnt[maxn],n,ml,md,tot,a,b,c,flag=0;
void add(int x,int y,int z)
{
	ver[++tot]=y,edge[tot]=z,next[tot]=head[x],head[x]=tot;
}
void spfa(int k)
{
	queue<int>q;
	fill(d,d+n+1,INF);
	fill(v,v+n+1,0);
	d[k]=0,v[k]=1,cnt[k]=0;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		v[x]=0;
		for(int i=head[x];i;i=next[i])
		{
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				if(!v[y])
				{
					q.push(y);v[y]=1;
					cnt[y]=cnt[x]+1;
					if(cnt[y]>=n)
					{
					flag=1;
					return;
					}
				}
			}
		}
	} 
	
}
int main()
{
	while(scanf("%d%d%d",&n,&ml,&md)!=EOF)
	{
		fill(next,next+n+1,0);
		tot=0;
		while(ml--)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
		}
		while(md--)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(b,a,-c);
		}
		spfa(1);
		if(flag)
			printf("-1\n");
		else
			{
				int ans=d[n];
				if(ans==INF)
					printf("-2\n");
				else
					printf("%d\n",ans);
			} 
	}
	return 0;
} 
