#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
bool vis[210];
int match[110],head[110],ver[110*110],next1[110*110],tot;

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

void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}

int main()
{
    int m,n,i,a,b;
    scanf("%d%d",&m,&n);
    while(~scanf("%d%d",&a,&b))
    {
       if(a==-1&&b==-1)break;
       add(a,b); 
    }
    int ans=0;
    for(i=1;i<=m;++i)
    {
        memset(vis,0,sizeof(vis)); 
        if(dfs(i))ans++;
    }
    printf("%d\n",ans);
    for(i=m+1;i<=n+m;++i)
    {
       if(match[i])
          printf("%d %d\n",match[i],i); 
    }
}
