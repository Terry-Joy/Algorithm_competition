#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
const int maxn=1010;
using namespace std;
int d[maxn],n,m,x,map[maxn][maxn],a,b,t,max1[maxn],result[maxn],ans=0;
const int max2=0x3f;
bool is_used[maxn];
void dijkstra(int x)
{
	memset(d,0x3f,sizeof(d));
	memset(is_used,0,sizeof(is_used));
	for(int j=1;j<=n;++j)
		d[j]=map[x][j]; 
	d[x]=0;
	for(int i=1;i<=n-1;++i)
	{
		int k=0;
		for(int j=1;j<=n;++j)
			if(!is_used[j]&&(x==0||d[j]<d[k]))
				k=j;
		is_used[k]=1;
		for(int y=1;y<=n;++y)
		d[y]=min(d[y],d[k]+map[k][y]);
	}
}
void traverse()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			swap(map[i][j],map[j][i]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	memset(map,0x3f,sizeof(map));
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&t);
		map[a][b]=t;
	}
	dijkstra(x);
	for(int i=1;i<=n;++i)
		max1[i]=d[i];
	traverse();
	dijkstra(x);
	for(int i=1;i<=n;++i)
	{
		result[i]=max1[i]+d[i];
		ans=max(ans,result[i]);
	}
	cout<<ans;
	return 0;
}
