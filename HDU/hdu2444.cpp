#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int N=210,M=80010;
int match[N],head[N],next1[M],tot,ver[M],v[N],flag=1;
bool vis[N];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
bool dfs2(int x)
{
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(!vis[y])
      {
         vis[y]=1;
         if(!match[y]||dfs2(match[y]))
         {
            match[y]=x;return true; 
         } 
      } 
   } 
   return false;
}
void dfs(int x,int clo)
{
   if(!flag)return;
   v[x]=clo;
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(!v[y])
         dfs(y,3-clo);
      else
      { 
          if(v[y]==clo)
            {
               flag=0;
               return; 
            }  
      }
   } 
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
       int i,j,a,b;
       flag=1;
       memset(v,0,sizeof(v));
       memset(head,0,sizeof(head));
       memset(match,0,sizeof(match));
       tot=0;
       for(i=1;i<=m;++i)
       {
          scanf("%d%d",&a,&b);
          add(a,b);
          add(b,a); 
       }
       for(i=1;i<=n;++i)
       {
          if(!v[i])dfs(i,1); 
          if(!flag)break;
       }
       if(!flag)
       {  
           puts("No");
           continue;
       }
       int ans=0;
       for(i=1;i<=n;++i)
       {
          memset(vis,0,sizeof(vis));
          if(v[i]==1)
             if(dfs2(i))ans++; 
       }
       printf("%d\n",ans);
    }
    return 0;
}
