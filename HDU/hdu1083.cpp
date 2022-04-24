#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
const int N=310,M=30010;
int head[N],ver[M],next1[M],tot,match[N],t;
bool vis[N];
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
         if(!match[y]||dfs(match[y]))
         {
            match[y]=x;return true; 
         } 
      } 
   } 
   return false;
}
int main()
{
    scanf("%d",&t);
    int n,m,i,j,a,k,b;
    for(i=1;i<=t;++i)
    {
       memset(match,0,sizeof(match));
       tot=0;
       memset(head,0,sizeof(head));
       scanf("%d%d",&n,&m);
       for(j=1;j<=n;++j)
       {
           scanf("%d",&a);
           for(k=1;k<=a;++k)
           {
              scanf("%d",&b);
              add(j,b); 
           } 
       } 
       int ans=0;
       for(j=1;j<=n;++j)
       {
          memset(vis,0,sizeof(vis));
          if(dfs(j))ans++; 
       }
       if(ans==n)
           puts("YES");
       else
           puts("NO");
    }
    return 0;
}
