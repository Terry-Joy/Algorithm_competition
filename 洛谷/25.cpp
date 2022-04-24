#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
const int max1=2e4+10;
struct rec{int st,to,cost;}edge[maxn];
int n,m,fa[max1],rank[max1],Em[maxn];
void init()
{
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
		rank[i]=0;
	}
}
bool cmp1(rec x,rec y)
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&edge[i].st,&edge[i].to,&edge[i].cost);
	init();
	sort(edge+1,edge+1+m,cmp1);
	for(int i=1;i<=m;++i)
	{
		int x=find(edge[i].st),y=find(edge[i].to);
		if(x==y){printf("%d",edge[i].cost);return 0;}
		else 
		{
			if(!Em[edge[i].st])	
				Em[edge[i].st]=edge[i].to;
			else {
			if(rank[find(Em[edge[i].st])]<rank[find(edge[i].to)]) 
			fa[find(Em[edge[i].st])]=find(edge[i].to);
			else {
				fa[find(edge[i].to)]=find(Em[edge[i].st]);
				if(rank[find(Em[edge[i].st])]==rank[find(edge[i].to)])
				rank[find(Em[edge[i].st])]++;
			}
			}
			if(!Em[edge[i].to])	
				Em[edge[i].to]=edge[i].st;
			else {
			if(rank[find(Em[edge[i].to])]<rank[find(edge[i].st)]) 
			fa[find(Em[edge[i].to])]=find(edge[i].st);
			else {
				fa[find(edge[i].st)]=find(Em[edge[i].to]);
				if(rank[find(Em[edge[i].to])]==rank[find(edge[i].st)])
				rank[find(Em[edge[i].to])]++;
			}
			}
		}
	}
	printf("0");
	return 0;
}
 
