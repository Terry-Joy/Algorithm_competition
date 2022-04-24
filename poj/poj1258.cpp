#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int n,d[120],a[120][120],v[120],ans;
void prim()
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[1]=0;
	for(int i=1;i<n;++i)
	{
		int x=0;
		for(int j=1;j<=n;++j)
		if(!v[j]&&(x==0||d[j]<d[x]))
			x=j;
		v[x]=1;
		for(int y=1;y<=n;++y)
		if(!v[y])
		d[y]=min(d[y],a[x][y]);
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&a[i][j]);
		prim();
		for(int i=2;i<=n;++i)
			ans+=d[i];
		printf("%d\n",ans);
	}
	return 0;
}
