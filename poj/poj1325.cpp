#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
const int maxn=110;
int head[maxn],ver[maxn*maxn],next1[maxn*maxn],tot,match[maxn];
bool vis[maxn],vis1[maxn],vis2[maxn];

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
              match[y]=x;
              return true; 
          }
      } 
   } 
   return false;
}
int main()
{
    int n,m,k,i;
    while(scanf("%d",&n)&&n)
    { 
        memset(head,0,sizeof(head));
        memset(match,-1,sizeof(match));
        tot=0;
        scanf("%d%d",&m,&k);
        int a,b,c,sum=0;
        for(i=1;i<=k;++i)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(b==0||c==0)continue;
            add(b,c);
        }
        int ans=0;
        for(i=1;i<=n;++i)
        { 
            memset(vis,0,sizeof(vis));
            if(dfs(i))ans++;
        }
        printf("%d\n",ans);        
    }
    return 0;
}
