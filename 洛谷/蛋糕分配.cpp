#include<cstdio>
#include<cmath>
using namespace std;
const int INF=0x7FFFFFFF;
int r[30],h[30],n,m;
int minn=INF;
void dfs(int x,int s,int v,int z)//x代表当前层数，z代表枚举的下界，s表示当前面积，v表示剩余体积 
{
	if(v<0)return;
	if(s>=minn)return;
	if(v==0&&x==m+1)
	{
		s+=r[1]*r[1];
		if(s<minn)
		minn=s;
		return;
	}
	if(s+r[1]*r[1]+2*z>minn)return;	
	for(int i=r[x-1]-1;i>=z;--i)
	for(int j=h[x-1]-1;j>=z;--j)
	{
		if(v-i*i*j>=0&&x<=m)
		{
			r[x]=i;
			h[x]=j;
			dfs(x+1,s+(2*i*j),v-i*i*j,z-1);
			r[x]=0;
			h[x]=0;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	r[0]=(int)sqrt(20000/3);
	h[0]=(int)sqrt(20000/3);
	dfs(1,0,n,m);
	if(minn==INF)
	printf("%d",0);
	else printf("%d",minn);
	return 0;
} 
