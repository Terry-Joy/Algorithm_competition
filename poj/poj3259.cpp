#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=520,M=5500,INF=0x3f3f3f3f;
int head[N],next[M],ver[M],edge[M],cnt[N],tot,d[N],a,b,c,x,y,z,v[N];
void add(int x,int y,int z)
{
	ver[++tot]=y,edge[tot]=z,next[tot]=head[x],head[x]=tot;
}
bool spfa()
{
	queue<int>q;
	for(int i=0;i<=a;++i)
	{
		d[i]=INF;
		v[i]=0;
	}
	d[1]=0,v[1]=1;
	q.push(1),cnt[1]=0;
	while(q.size())
	{
		int x=q.front();q.pop();
		v[x]=0;
		for(int i=head[x];i;i=next[i])
		{
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				cnt[y]++;
				if(cnt[y]>=a)return true;
				if(!v[y])q.push(y),v[y]=1;
			}
		}
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		tot=0;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0;i<=a;++i){head[i]=0,cnt[i]=0;}
		for(int i=1;i<=b;++i)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		for(int i=1;i<=c;++i)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,-z);
		} 
		if(spfa())puts("YES");
		else puts("NO");
	}
}
