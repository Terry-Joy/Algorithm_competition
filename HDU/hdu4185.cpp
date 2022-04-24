#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
char map[610][610];
int n,head[610*300],ver[4*610*300],next1[4*610*300],match[610*300],tot;
bool vis[605*300];
int dx[]={1,-1,0,0 };
int dy[]={0,0,1,-1 };
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
    int t,i,j,k,f=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;++i)
            scanf("%s",map[i]+1);
        int k=n*n;
        tot=0;
        for(i=1;i<=k;++i)
            head[i]=match[i]=0;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
            {
               if(map[i][j]=='#'&&(i+j)%2==0)//以(i+j)的奇偶性判定
               {
                  for(k=0;k<4;++k)
                  {
                     int xx=i+dx[k];
                     int yy=j+dy[k];
                     if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&map[xx][yy]=='#')//直接顺延分配顶点序号就行了
                        add(n*(i-1)+j,n*(xx-1)+yy); 
                  } 
               } 
            }
         int ans=0;
       for(i=1;i<=n;++i)
         for(j=1;j<=n;++j)
         {
            if((i+j)%2==1)continue;
            memset(vis,0,sizeof(vis));
            if(dfs((i-1)*n+j))ans++; 
         }  
       printf("Case %d: %d\n",++f,ans);
    }
    return 0;
}
