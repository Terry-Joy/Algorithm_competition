#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;
const int maxn=60;
int r[maxn][maxn],c[maxn][maxn],tot,head[maxn*maxn],ver[maxn*maxn],next1[maxn*maxn],n,m,match[maxn*maxn];
bool vis[maxn*maxn];
char s[maxn][maxn];

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
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;++i)
        scanf("%s",s[i]+1);
    int k=0;
    for(i=1;i<=n;++i)
    { 
       for(j=1;j<=m;++j)
       {
          if(s[i][j]=='*')
          {
             k++;
             while(s[i][j]=='*'&&j<=m)
             {    
                 r[i][j]=k;
                 ++j;
             }
          } 
       }
    }
   /* cout<<k<<endl;*/
    k=0;
    for(j=1;j<=m;++j)
    {
       for(i=1;i<=n;++i)
       {
          if(s[i][j]=='*')
          {
             k++;
             while(s[i][j]=='*'&&i<=n)
             {
                c[i][j]=k;
                ++i; 
             } 
          } 
       } 
    }
    /*cout<<k<<endl;*/
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(s[i][j]=='*')
                add(c[i][j],r[i][j]);
    int ans=0;
    for(i=1;i<=k;++i)
    {
       memset(vis,0,sizeof(vis));
       if(dfs(i))ans++; 
    }
    cout<<ans<<endl;
}
