#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=120,M=400;
int tot=0,head[N],next[M],ver[M],cnt[N];double cost[M],exchange[M];
int n,m,s;double v,d[N];//d[]表示到某种类型货币时的最大值 
bool vis[N];
void add(int x,int y,double ex,double cos)
{
	ver[++tot]=y,cost[tot]=cos,exchange[tot]=ex,next[tot]=head[x],head[x]=tot;
}
bool spfa()
{
	queue<int>q;
	d[s]=v;
	q.push(s),vis[s]=1;
	cnt[s]=0;
	while(q.size())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=next[i])
		{
			int y=ver[i];double cos=cost[i],exch=exchange[i];
			if(d[y]<(d[x]-cos)*exch)			//求最大值，所以这里是小于 
			{
				d[y]=(d[x]-cos)*exch;
				cnt[y]++;
				if(cnt[y]>=n)return true;
				if(!vis[y])q.push(y),vis[y]=1;
			}
		}		
	} 
	return false;
}
int main()
{
	scanf("%d%d%d%lf",&n,&m,&s,&v);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		double r1,c1,r2,c2;
		scanf("%lf%lf",&r1,&c1);
		add(a,b,r1,c1);
		scanf("%lf%lf",&r2,&c2);
		add(b,a,r2,c2);
	}
	if(spfa())
		printf("YES\n");
	else 
		printf("NO\n");
	return 0;
}
