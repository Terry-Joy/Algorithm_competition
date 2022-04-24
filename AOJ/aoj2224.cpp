#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<cmath>
using namespace std;
const int maxn=1e5;
struct Rec
{
	double s,e,cost;
}edge[maxn];
struct Node
{
	double x,y;
}node[maxn];
int n,m,fa[maxn];
long double ans,sum;
bool cmp1(Rec x,Rec y)
{
	return x.cost>y.cost;
}
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans=0;
		sum=0;
		for(int i=1;i<=n;++i)
			scanf("%lf%lf",&node[i].x,&node[i].y);
		for(int i=1;i<=m;++i)
		{
			scanf("%lf%lf",&edge[i].s,&edge[i].e);
			int k=edge[i].s,j=edge[i].e;
			edge[i].cost=sqrt((node[k].x-node[j].x)*(node[k].x-node[j].x)+(node[k].y-node[j].y)*(node[k].y-node[j].y));
			sum+=edge[i].cost;
		}
		sort(edge+1,edge+m+1,cmp1);
		for(int i=1;i<=n;++i)
			fa[i]=i;
		for(int i=1;i<=m;++i)
		{
			int x=find(edge[i].s);
			int y=find(edge[i].e);
			if(x==y)continue;
			fa[x]=y;
			ans+=edge[i].cost;
		}
		printf("%.3llf\n",sum-ans);
	}	
	return 0;
}

