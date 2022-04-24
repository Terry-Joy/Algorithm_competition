#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int N=510;
int head[N],ver[N*N],next1[N*N],tot,match[N],n,m,p,i,j;
bool vis[N];
char like[510][5],dislike[510][5];
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
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        tot=0;
        memset(match,0,sizeof(match));
        memset(head,0,sizeof(head));
        for(i=1;i<=p;++i)
        {
           scanf("%s%s",like[i],dislike[i]); 
        }
        for(i=1;i<=p;++i)
            for(j=i+1;j<=p;++j)
            {
               if(strcmp(like[i],dislike[j])==0||strcmp(dislike[i],like[j])==0)
                  {
                     add(i,j);
                     add(j,i);
                  }
            }
        int ans=0;
        for(i=1;i<=p;++i)
        {
           memset(vis,0,sizeof(vis)); 
           if(dfs(i))ans++;
        }
        printf("%d\n",p-ans/2);
    }
    return 0;
}
