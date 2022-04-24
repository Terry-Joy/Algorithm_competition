#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=5010,M=2e4+10;
int dfn[N],low[N],c[N],tot,head[N],next1[M],ver[M],dcc,num,deg[N];
bool bridge[M];

void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}

void tarjan(int x,int in_edge)
{
   low[x]=dfn[x]=++num;
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

void dfs(int x)
{
   c[x]=dcc;
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(c[y]||bridge[i])continue;
      dfs(y); 
   } 
}

int main()
{
    int f,r;
    scanf("%d%d",&f,&r);
    tot=1;
    for(int i=1;i<=r;++i)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       add(a,b);
       add(b,a); 
    }
    for(int i=1;i<=f;++i)
        if(!dfn[i])tarjan(i,0);
    for(int i=1;i<=f;++i)
    {
       if(!c[i])
       {
          ++dcc;
          dfs(i); 
       } 
    }
    for(int i=2;i<=tot;++i)
    {
        int x=ver[i^1],y=ver[i];
        if(c[x]!=c[y])
            deg[c[x]]++;
    }
    int ans=0;
    for(int i=1;i<=dcc;++i)
        if(deg[i]==1)ans++;
    printf("%d\n",(ans+1)/2);
}
