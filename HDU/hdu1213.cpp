#include<cstdio>
#include<cstring> 
using namespace std;
const int maxn=1010;
int t,fa[maxn],rank[maxn],ans;
int find(int x)
{
	if(fa[x]==x)
		return x;
	else 
		return fa[x]=find(fa[x]);
}
void unit(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
	return;
	if(rank[x]<rank[y])
	fa[x]=y;
	else
	{
		fa[y]=x;
		if(rank[x]==rank[y])
		rank[x]++;
	}
}
int main()
{
	scanf("%d",&t);
	int a,b,x,y;
	while(t--)
	{
		scanf("%d%d",&a,&b);
		ans=0;
		for(int i=1;i<=a;++i)
		{
			fa[i]=i;
			rank[i]=0;
		}
		while(b--)
		{
			scanf("%d%d",&x,&y);
			unit(x,y);
		}
		for(int j=1;j<=a;++j)
		if(j==fa[j])
		ans++;
		printf("%d\n",ans);
	}
	return 0;
}
