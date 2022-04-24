#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdio>
using namespace std;
int a[110][110],head[5010],next1[41000],ver[41000],tot;
bool vis[5010],v[110][110];
int match[5010];

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
   int n,m,k,i,x,y,j;
   tot=0;
   scanf("%d%d%d",&n,&m,&k);
   for(i=1;i<=k;++i)
   {
       scanf("%d%d",&x,&y);
       a[x][y]=-1;
   } 
   int x1=0,x2=0;
   for(i=1;i<=n;++i)
       for(j=1;j<=m;++j)
       {
           if(a[i][j]!=-1)
           {
              if((i+j)%2==0)
              {   
                  a[i][j]=++x1;
                  v[i][j]=1;
              }
              else 
                 a[i][j]=++x2; 
           }
       }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
           if(v[i][j])
           {
              if((i-2)>=1&&(j-1)>=1&&a[i-2][j-1]!=-1)//八个方向
                 add(a[i][j],a[i-2][j-1]);
              if((i-1)>=1&&(j-2)>=1&&a[i-1][j-2]!=-1)
                 add(a[i][j],a[i-1][j-2]);
              if((i+1)<=n&&(j-2)>=1&&a[i+1][j-2]!=-1)
                 add(a[i][j],a[i+1][j-2]);
              if((i+2)<=n&&(j-1)>=1&&a[i+2][j-1]!=-1)
                 add(a[i][j],a[i+2][j-1]);
              if((i+2)<=n&&(j+1)<=m&&a[i+2][j+1]!=-1)
                 add(a[i][j],a[i+2][j+1]);
              if((i+1)<=n&&(j+2)<=m&&a[i+1][j+2]!=-1)
                 add(a[i][j],a[i+1][j+2]);
              if((i-1)>=1&&(j+2)<=m&&a[i-1][j+2]!=-1)
                 add(a[i][j],a[i-1][j+2]);
              if((i-2)>=1&&(j+1)<=m&&a[i-2][j+1]!=-1)
                 add(a[i][j],a[i-2][j+1]); 
           } 
        }
    }
    int ans=0;
    for(i=1;i<=x1;++i)
    {
       for(j=1;j<=x2;++j)
           vis[j]=0;
       if(dfs(i))ans++; 
    }
    printf("%d\n",x1+x2-ans);
    return 0;
}
