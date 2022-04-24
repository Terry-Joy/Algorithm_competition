#include<iostream>
#include<cstdio>
using namespace std;
int tree[2500000][2],tot=1,a[101000],t,n,m,v[2500000],b;
void insert(int x,int id)
{
	int now=1;
	for(int i=31;i>=0;--i)
	{
		bool k=x&(1<<i);
		if(!tree[now][k]) tree[now][k]=++tot;
		now=tree[now][k];
	}
	v[now]=id;
}
int find(int x)
{
	int now=1;
	for(int i=31;i>=0;--i)
	{
		bool k=x&(1<<i);
		if(tree[now][k^1])now=tree[now][k^1];
		else  now=tree[now][k];
	}
	return a[v[now]];
}
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d%d",&n,&m);
		printf("Case #%d:\n",t);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			insert(a[i],i);
		}
		for(int i=1;i<=m;++i)
		{
			scanf("%d",&b);
			printf("%d\n",find(b));
		} 
	}
	return 0;
}
