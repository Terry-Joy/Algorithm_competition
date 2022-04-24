#include<iostream>
#include<cstdio>
using namespace std;
const int N=3e5+100,M=6e5+100;
int head[N],next1[M],ver[M],tot,temp[N],a[N],d[N],f[N][23];
int n;
void dfs(int now,int fa)
{
   d[now]=d[fa]+1;
   f[now][0]=fa;
   for(int i=head[now];i;i=next1[i])
   {
      if(ver[i]!=fa)
         dfs(ver[i],now); 
   } 
}
void init()
{
   for(int i=1;(1<<i)<=n;++i)
      for(int j=1;j<=n;++j)
         f[j][i]=f[f[j][i-1]][i-1]; 
}
int lca(int x,int y)
{
   if(d[x]>d[y])swap(x,y);
   for(int i=20;i>=0;--i)
      if(d[f[y][i]]>=d[x])y=f[y][i];
   if(x==y)return x;
   for(int i=20;i>=0;--i)
     if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
   return f[x][0];
}
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void dfs2(int x)
{
    for(int i=head[x];i;i=next1[i])
    {
       int y=ver[i];
       if(y==f[x][0])continue;
       dfs2(y);
       temp[x]+=temp[y]; 
    }
}
int main()
{ 
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
       scanf("%d",&a[i]); 
    }
    for(int i=1;i<n;++i)
    {
       int x,y;
       scanf("%d%d",&x,&y);
       add(x,y);
       add(y,x); 
    }
    dfs(1,0);
    init();
    for(int i=1;i<n;++i)
    {
       int Lca=lca(a[i],a[i+1]);
       temp[a[i]]++,temp[a[i+1]]++; 
       temp[Lca]--;
       temp[f[Lca][0]]--;
    }
    dfs2(1);
    for(int i=2;i<=n;++i)
    { 
        temp[a[i]]--;
    }
    for(int i=1;i<=n;++i)
        printf("%d\n",temp[i]);
    return 0;
}
