#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
double map[210][210],d[210];//d[]表示1到n上所有通路的路径的一条边的最小的最大值 
int x[210],y[210],n;
bool v[210];
const int INF=0x3f3f3f3f;
void dijkstra(){
	for(int i=1;i<=n;++i)d[i]=INF;
	memset(v,0,sizeof(v));
	d[1]=0;
	for(int i=1;i<n;++i)
	{
		int x=0;
		for(int j=1;j<=n;++j)
			if(!v[j]&&(x==0||d[j]<d[x]))x=j;
		v[x]=1;
		for(int j=1;j<=n;++j)
			d[j]=min(max(d[x],map[x][j]),d[j]);
	}
}
int main()
{
	int t=0;
	while(~scanf("%d",&n)&&n)
	{
		int a,b;
		for(int i=1;i<=n;++i)
			scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				map[i][j]=map[j][i]=sqrt(double(x[i]-x[j])*(x[i]-x[j])+double(y[i]-y[j])*(y[i]-y[j]));
			dijkstra();
			printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++t,d[2]);
	}
	return 0;
}
