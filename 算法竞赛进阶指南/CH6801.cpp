#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=10010;
int match[N],a[N][N],head[N],next1[N<<2],ver[N<<2],tot;
bool vis[N],v[N][N];
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
    int n,t;
    scanf("%d%d",&n,&t);
    tot=0;
    int i,j;
    bool flag=1;
    for(i=1;i<=n;++i)
    { 
        if(i%2==1)flag=0;
        else flag=1;
        for(j=1;j<=n;++j)
        {
           if(flag==0)
               a[i][j]=0,flag=1; 
            else
                a[i][j]=1,flag=0;
        }
    }
    int x,y;
    for(i=1;i<=t;++i)
    {
       scanf("%d%d",&x,&y);
       a[x][y]=-1; 
    }
    int k=0,b=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            if(a[i][j]==0)
            {     
                a[i][j]=++k;
                v[i][j]=1;    
            }
            else if(a[i][j]==1)
                a[i][j]=++b;    
        }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
           if(v[i][j])
           {
              if(i-1>=1&&a[i-1][j]!=-1)
                   add(a[i][j],a[i-1][j]);
              if(j-1>=1&&a[i][j-1]!=-1)
                   add(a[i][j],a[i][j-1]);
              if(i+1<=n&&a[i+1][j]!=-1)
                   add(a[i][j],a[i+1][j]);
              if(j+1<=n&&a[i][j+1]!=-1)
                   add(a[i][j],a[i][j+1]); 
           } 
        }
    int ans=0;
    for(i=1;i<=k;++i)
    {
       memset(vis,0,sizeof(vis));
       if(dfs(i))ans++; 
    }
    printf("%d\n",ans);
    return 0;
}
