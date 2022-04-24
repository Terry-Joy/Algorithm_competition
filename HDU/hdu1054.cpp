#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1510,M=3010;
int head[N],ver[M],next1[M],tot,match[N];
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
         if(match[y]==-1||dfs(match[y]))
         {
            match[y]=x;return true; 
         } 
      } 
   } 
   return false;
}
int main()
{
    int n,i,a,b,j,c;
    while(~scanf("%d",&n))
    {
        tot=0;
        for(i=0;i<=n;++i)
            head[i]=0;
        memset(match,-1,sizeof(match));
       for(i=1;i<=n;++i)
       {
         scanf("%d:(%d)",&a,&b);
         for(j=1;j<=b;++j)
         {
            scanf("%d",&c);
            add(a,c);
            add(c,a); 
         }
       } 
       int ans=0;
       for(i=0;i<n;++i)
       {
          memset(vis,0,sizeof(vis));
          if(dfs(i)) ans++;
       }
       printf("%d\n",ans/2);
    }
    return 0;
}
