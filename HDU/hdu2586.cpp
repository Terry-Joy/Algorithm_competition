#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int maxn=1e5;
int f[maxn][20],d[maxn],dis[maxn],n,m,t,lg[maxn];
int head[maxn],next1[2*maxn],ver[2*maxn],edge[2*maxn],tot=0;
void add(int x,int y,int z)
{
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
void dfs(int now,int fa)
{
    f[now][0]=fa;d[now]=d[fa]+1;
    for(int i=1;i<=lg[d[now]];++i)
    	f[now][i]=f[f[now][i-1]][i-1];
    for(int i=head[now];i;i=next1[i])
    	if(ver[i]!=fa)
    	{
    		dis[ver[i]]=dis[fa]+edge[i];
			dfs(ver[i],now);
		}
}
int lca(int x,int y)
{
   if(d[x]>d[y])swap(x,y);
   for(int i=lg[d[y]];i>=0;--i)
      if(d[f[y][i]]>=d[x])y=f[y][i];
   if(x==y)return x;
   for(int i=lg[d[x]];i>=0;--i)
      if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
   return f[x][0]; 
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	tot=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;++i)head[i]=d[i]=dis[i]=0;
        dis[1]=0;
        for(int i=1;i<n;++i)
        {
           int a,b,c;
           scanf("%d%d%d",&a,&b,&c);
           add(a,b,c);
           add(b,a,c); 
    	}
        dfs(1,0);
        for(int i=1;i<=m;++i)
        {
           int x,y;
           scanf("%d%d",&x,&y);
           printf("%d\n",dis[x]+dis[y]-2*dis[lca(x,y)]);
        }
    }
    return 0;
}
