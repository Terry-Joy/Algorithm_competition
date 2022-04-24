#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+5,M=4e5+5;
int head[N],ver[M],next1[M],tot,hc[N],vc[M],nc[M],c[N],dcc,tc,d[N],lg[N];
int dfn[N],low[N],n,m,num;
int f[N][20],fa[N];
bool bridge[M];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void add_c(int x,int y)
{
   vc[++tc]=y,nc[tc]=hc[x],hc[x]=tc; 
}
void tarjan(int x,int in_edge)      //求桥
{
   dfn[x]=low[x]=++num;
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(!dfn[y])
      {
         tarjan(y,i);
         low[x]=min(low[x],low[y]);
         if(dfn[x]<low[y]) 
            bridge[i]=bridge[i^1]=1;
      } 
      else if(i!=(in_edge^1))
          low[x]=min(low[x],dfn[y]);
   } 
}
void dfs(int x)                 //求e-DCC
{
   c[x]=dcc;
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(c[y]||bridge[i])continue;
      dfs(y); 
   } 
}
void init()
{
    for(int i=1;(1<<i)<=n;++i)
        for(int j=1;j<=n;++j)
            f[j][i]=f[f[j][i-1]][i-1];
}
void dfs2(int now,int fa)           //倍增预处理
{
   d[now]=d[fa]+1;
   f[now][0]=fa;
   for(int i=hc[now];i;i=nc[i])
   {
        int y=vc[i];
        if(y!=fa)
            dfs2(y,now);
   } 
}
int find(int x)
{
   if(x==fa[x])return x;
   return fa[x]=find(fa[x]); 
}
int lca(int x,int y)
{
    if(d[x]>d[y])swap(x,y);
    for(int i=lg[d[y]];i>=0;--i)
        if(d[f[y][i]]>=d[x])y=f[y][i];
    if(x==y)return x;
    for(int i=lg[d[y]];i>=0;--i)
        if(f[y][i]!=f[x][i])
            y=f[y][i],x=f[x][i];
    return f[x][0];
}
int main()
{
   for(int i=2;i<=N;++i)
       lg[i]=lg[i>>1]+1;
   int T=0;
   while(~scanf("%d%d",&n,&m)&&(n|m))
   {
      tot=1,num=dcc=0;
      for(int i=1;i<=n;++i)
          head[i]=hc[i]=d[i]=dfn[i]=low[i]=c[i]=0;
      for(int i=1;i<=2*m+1;++i)
          bridge[i]=0;
      for(int i=1;i<=m;++i)
      {
         int a,b;
         scanf("%d%d",&a,&b);
         add(a,b);
         add(b,a);
      }
      //求桥 e-DCC
      for(int i=1;i<=n;++i)
          if(!dfn[i])tarjan(i,0);
      for(int i=1;i<=n;++i)
      {
         if(!c[i])
         {
            ++dcc;
            dfs(i); 
         } 
      }
      tc=1;
      for(int i=2;i<=tot;++i)   //缩点
      {
         int x=ver[i^1],y=ver[i];
         if(c[x]==c[y])continue; 
         add_c(c[x],c[y]);  
      }
      dfs2(1,0);
      init();
      int q;
      scanf("%d",&q);
      for(int i=1;i<=dcc;++i)
          fa[i]=i;
      int ans=dcc-1;
      printf("Case %d:\n",++T);
      while(q--)
      {
        int x,y;
        scanf("%d%d",&x,&y);
        x=c[x],y=c[y];
        int p=lca(x,y);
        x=find(x);
        while(d[x]>d[p])        
        {
           fa[x]=f[x][0];
           ans--;
           x=find(x);           //利用并查集的路径压缩直接跳过所有已经标记的边
        }
        y=find(y);
        while(d[y]>d[p])
        {
           fa[y]=f[y][0];
           ans--;
           y=find(y); 
        }
        printf("%d\n",ans);
      }
      cout<<"\n";
   }
   return 0;
}
