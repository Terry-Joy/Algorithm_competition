#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
struct rec
{
	int x,y,z;
}edge[20100];
int n,m,fa[2010],rank[2010],ans;
bool cmp1(rec a,rec b)
{
	return a.z<b.z;
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
		for(int i=1;i<=m;++i)
			scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].z);
		sort(edge+1,edge+1+m,cmp1);
		for(int i=1;i<=n;++i)
		{
			fa[i]=i;
			rank[i]=0;
		}
		for(int i=1;i<=m;++i)
		{
			int x=find(edge[i].x);
			int y=find(edge[i].y);
			if(x==y)continue;
			if(rank[x]<rank[y])
			fa[x]=y;
			else 
			{
				fa[y]=x;
				if(rank[x]==rank[y])
				rank[x]++;
			}
			ans=max(ans,edge[i].z);
		}
		printf("%d\n",ans);
	}
	return 0;
}
