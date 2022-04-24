#include<cstdio>
using namespace std;
const int maxn=1e5+10;
const int max_1=1e4;
int n,m,a,b,fa[maxn],ans,an[maxn],t;
struct City
{
	int x,y;
}line[maxn];
int find(int x)
{
	if(fa[x]==x)
	return x;
	else return fa[x]=find(fa[x]);
}
bool unit(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		fa[x]=y;
		return true;
	}
	else
	return false;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		t=0;
		ans=n;
		for(int i=0;i<maxn;++i)
			fa[i]=i;
			an[t]=n;
		for(int i=0;i<m;++i)
			scanf("%d%d",&line[i].x,&line[i].y);
		for(int i=m-1;i>=0;--i)
		{
			if(unit(line[i].x,line[i].y))
				an[++t]=--ans;
			else
				an[++t]=ans;	
		}
			an[t]=n;
		for(int i=t-1;i>=0;--i)
			printf("%d\n",an[i]);
	}
	return 0;
} 
