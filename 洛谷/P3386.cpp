//o(VE+N) V、N分别为左右端点
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=5e4+10;
int head[510],ver[maxn],next1[maxn],tot,vis[510],match[510];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
bool dfs(int x)
{
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(!vis[y])
      {
         vis[y]=1;
         if(!match[y]||dfs(match[y]))        //已经匹配的还能找到一条形成增广路 
         {
            match[y]=x;return true; 
         }
      } 
   } 
   return false;
}
int main()
{
    int n,m,u,v,e,i;
    scanf("%d%d%d",&n,&m,&e);
    for(i=1;i<=e;++i)
    { 
       scanf("%d%d",&u,&v);
       add(u,v); 
    }
    int ans=0;
    int j;
    for(i=1;i<=n;++i)
    {
       if(dfs(i))ans++;
       for(j=1;j<=m;++j)
           vis[j]=0;        //右端点清空
    }
    printf("%d\n",ans);
    return 0;
}
