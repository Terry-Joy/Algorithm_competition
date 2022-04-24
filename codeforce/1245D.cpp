#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=4e3;
const int max1=4e6+10;
long long fa[maxn],n,c[maxn],k[maxn],add[maxn],ans,sum,con,x2[maxn],y2[maxn],rank1[maxn];
struct Node
{
	int x,y;
}node[maxn];
struct rec
{
	long long s,e,cost;
}edge[((maxn+1)*maxn/2)+maxn+10];
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool cmp1(rec a,rec b)
{
	return a.cost<b.cost;
}
int main()
{
	ans=0,sum=0,con=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&node[i].x,&node[i].y);
	for(int i=1;i<=n;++i)
		scanf("%lld",&c[i]);
	for(int i=1;i<=n;++i)
		scanf("%lld",&k[i]);
	for(int i=1;i<=n;++i)
	{
		edge[i].cost=c[i];
		edge[i].s=0;
		edge[i].e=i;	
	}
	int num=n;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			edge[++num].s=i;
			edge[num].e=j;
			edge[num].cost=(k[i]+k[j])*(abs(node[i].x-node[j].x)+abs(node[i].y-node[j].y));
		}
	sort(edge+1,edge+num+1,cmp1);
	for(int i=0;i<=n;++i)
		{
		fa[i]=i;
		rank1[i]=0;
		}
	for(int i=1;i<=num;++i)
	{
		int x=find(edge[i].s);
		int y=find(edge[i].e);
		if(x==y)continue;
		if(rank1[x]<rank1[y])
		fa[x]=y;
		else 
		{
			fa[y]=x;
			if(rank1[x]==rank1[y])
				rank1[x]++;
		}
		ans+=edge[i].cost;
		if(edge[i].s==0)
			add[++sum]=edge[i].e;
		if(edge[i].s!=0)
		{
			x2[++con]=edge[i].s;
			y2[con]=edge[i].e;				
		}
	}	
	printf("%lld\n",ans);
	printf("%lld\n",sum);
	for(int i=1;i<=sum;++i)
		printf("%lld ",add[i]);
	putchar('\n');
	printf("%lld\n",con);
	for(int i=1;i<=con;++i)
	cout<<x2[i]<<" "<<y2[i]<<"\n";
	return 0;
} 
