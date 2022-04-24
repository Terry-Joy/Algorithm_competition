#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=110,INF=0x3f3f3f3f;
int d[110],a[110][110];
int n,q,b,k,x;
bool v[N];
void dijkstra()
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[q]=0;
	for(int i=1;i<n;++i)
	{
		int x=0;
		for(int j=1;j<=n;++j)
			if(!v[j]&&(x==0||d[j]<d[x]))x=j;
			v[x]=1;
		for(int y=1;y<=n;++y)
		{
			d[y]=min(d[y],d[x]+a[x][y]); 
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&q,&b);
	memset(a,0x3f,sizeof(a));	//地图忘了初始化！！ 
		for(int i=1;i<=n;++i)a[i][i]=0; 
	for(int i=1;i<=n;++i)
	{
		int k;
		scanf("%d",&k);
		for(int f=1;f<=k;++f)
		{
			scanf("%d",&x);
			if(f==1)
				a[i][x]=0;
			else
				a[i][x]=1;
		}
	}	

	dijkstra();
	if(d[b]>=INF)printf("-1\n");
	else
		printf("%d\n",d[b]);
	return 0;
} 
