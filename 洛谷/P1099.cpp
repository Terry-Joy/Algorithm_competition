#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=310;
int head[N],ver[2*N],edge[2*N],next1[2*N],vis[N],n,s,d[N],start,end,id=0,pre[N],r[N],t;
int dis[N],fa[N],ans=2147483647,ans2=-ans,tot=0,ans1=0;
void add(int x,int y,int z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
int dfs(int x)
{	
    for(int i=head[x];i;i=next1[i])
    {
       int y=ver[i];
       if(!fa[y])
       {
          dis[y]=dis[x]+edge[i];
          if(!vis[y])
          	ans1=max(dis[y],ans1);
          dfs(y); 
       } 
    }
    return ans1;
} 
void dfs(int x)
{
	for(int i=head[x];i;i=next1[i])
	{
		int y=ver[i];
		if(!vis[y]&&fa[x]!=y)
		{
			fa[y]=x;
			dis[y]=dis[x]+edge[i];
			dfs(y);
		}
	}
}
void dfs2(int x)
{
	for(int i=head[x];i;i=next1[i])
	{
		int y=ver[i];
		if(!vis[y]&&fa[x]!=y)
		{
			fa[y]=x;
			dis[y]=dis[x]+edge[i];
			dfs(y);
		}
	}
}
void init()
{
   start=bfs(1);
   end=bfs(start); 
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<n;++i)
    { 
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    init();
    for(int i=start;i;i=pre[i])
    {
       for(int j=i;j;j=pre[j]) 
       {
          if(d[i]-d[j]<=s)
          {
             memset(vis,0,sizeof(vis));
             ans2=-0x3f3f3f3f;
             for(int k=i;k!=j;k=pre[k])
                 vis[k]=1;
                 vis[j]=1;
             for(int k=i;k!=j;k=pre[k])
             {
             	memset(fa,0,sizeof(fa));
                dis[k]=0;
                ans1=0;
                ans2=dfs(k);
             } 
             ans=min(ans2,ans);
          }
       else break;
       }
    }
    printf("%d",ans);
    return 0;
}
