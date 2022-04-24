#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=4e4+1000;
struct rec
{
	int x,y,z;
}edge[maxn];
int fa[1050],rank[1050],n,m,ans;
bool cmp1(rec a,rec b)
{
	return a.z>b.z;
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
		{
			scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].z);
		}
		sort(edge+1,edge+1+m,cmp1);
		for(int i=1;i<=n;++i)
		{
			fa[i]=i;
			rank[i]=0;	
		}
		int trees=n;
		for(int i=1;i<=m;++i)
		{
			int k=find(edge[i].x);
			int q=find(edge[i].y);
			if(k==q)continue;
			if(rank[k]<rank[q])	
				fa[k]=q;
			else
			{
				fa[q]=k;
				if(rank[k]==rank[q])
					k++;
			}
			trees--;
			ans+=edge[i].z;
		}
		if(trees!=1)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
