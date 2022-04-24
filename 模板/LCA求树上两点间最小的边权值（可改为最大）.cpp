#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e4+100,M=5e4+100;
int head[N],next1[2*M],edge[2*M],ver[2*M],tot=0,fa[N],d[N],dp[N][23],dis[N][23],v[N];
int n,m;
const int INF=0x3f3f3f3f;
int get(int x)
{
   if(x==fa[x])return x;
   return fa[x]=get(fa[x]); 
}
struct Node{ 
    int x,y,z;
    bool operator<(const Node&a)const
    {
       return z>a.z; 
    }
}ed[2*M];
void add(int x,int y,int z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
void kruskal()
{
    for(int i=1;i<=n;++i)
        fa[i]=i;
    sort(ed+1,ed+1+m);
    for(int i=1;i<=m;++i)
    {
       int a=get(ed[i].x);int b=get(ed[i].y);
       if(a==b)continue;
       fa[a]=b;
       add(ed[i].x,ed[i].y,ed[i].z);
       add(ed[i].y,ed[i].x,ed[i].z);
    }
}
void dfs(int now,int fa)
{
   v[now]=1,dp[now][0]=fa,d[now]=d[fa]+1;
   for(int i=head[now];i;i=next1[i])
   {
       if(ver[i]!=fa)
        {
           dis[ver[i]][0]=edge[i];
           dfs(ver[i],now); 
        } 
   } 
}
void init()
{
	for(int i=1;(1<<i)+1<=n;++i)
		for(int j=1;j<=n;++j)
		{
			dp[j][i]=dp[dp[j][i-1]][i-1];
			dis[j][i]=min(dis[j][i-1],dis[dp[j][i-1]][i-1]);
		 } 
}
int lca(int x,int y)
{
    if(get(x)!=get(y))return -1;
    if(d[x]>d[y])swap(x,y);
    int ans=INF;
    for(int i=20;i>=0;--i)
    {
       if(d[dp[y][i]]>=d[x])
       {
          ans=min(ans,dis[y][i]);
          y=dp[y][i]; 
       } 
    }
    if(x==y)return ans;
    for(int i=20;i>=0;--i)
    {
       if(dp[x][i]!=dp[y][i])
       {
          ans=min(ans,min(dis[x][i],dis[y][i]));
          x=dp[x][i];
          y=dp[y][i]; 
       } 
    }
    ans=min(ans,min(dis[x][0],dis[y][0]));
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
       int a,b,c;
       scanf("%d%d%d",&a,&b,&c);
       ed[i].x=a,ed[i].y=b,ed[i].z=c; 
    }
   kruskal();
   for(int i=1;i<=n;++i)
   {
   		if(!v[i])			//防如果不为一颗树 
   		dfs(i,0);	   
	}
   init();
   int q;
   scanf("%d",&q);
   for(int i=1;i<=q;++i)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      printf("%d\n",lca(a,b)); 
   }  
   return 0;
}
