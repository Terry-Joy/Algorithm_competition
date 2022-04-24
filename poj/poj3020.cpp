#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
char map[500][500];
int mp[500][500],g[500][500],t,n,m,match[500],i,j,k,tot,f;
bool vis[500];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool dfs(int x)
{
   int y;
   for(y=1;y<=tot;++y)
   {
        if(!vis[y]&&g[x][y])
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
    for(i=1;i<=t;++i)
    {
        tot=0;
        memset(match,0,sizeof(match));
        memset(mp,0,sizeof(mp));
        memset(g,0,sizeof(g));
       scanf("%d%d",&n,&m);
       for(j=1;j<=n;++j)
           for(k=1;k<=m;++k)
           {
              cin>>map[j][k];
              if(map[j][k]=='*')
                mp[j][k]=++tot;
           }
        for(j=1;j<=n;++j)
            for(k=1;k<=m;++k)
            {   
                if(mp[j][k])
                {
                   for(f=0;f<4;++f)
                   {
                      int xx=j+dx[f],yy=k+dy[f];
                      if(map[xx][yy]=='*')
                      {
                          g[mp[j][k]][mp[xx][yy]]=1;
                      } 
                   } 
                }
            }
        int ans=0;
        for(k=1;k<=tot;++k)
        { 
            memset(vis,0,sizeof(vis));
            if(dfs(k))
                ans++;
        }
        printf("%d\n",tot-ans/2);
    }
    return 0;
}
