#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
const int maxn=1e5;
int fa[20010],rank[20010],k,n,m,r;
long long ans;
struct rec
{
	int x,y,z;
}edge[maxn];
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool cmp1(rec x,rec y)
{
	return x.z>y.z;
}
int main()
{
	scanf("%d",&k);
	while(k--)
	{
		ans=0;
		scanf("%d%d%d",&n,&m,&r);
		int sum=n+m;
		for(int i=0;i<r;++i)
		{
			scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].z);
			edge[i].y=edge[i].y+n; 
		}
		for(int i=0;i<sum;++i)
		{
			fa[i]=i;
			rank[i]=0;
		}
		sort(edge,edge+r,cmp1);
		for(int i=0;i<r;++i)
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
			ans+=edge[i].z;
		}
		printf("%lld\n",10000*(sum)-ans);
	}
	return 0;
}
 
