#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=210;
bool vis[N],v[N][N];
   int a,b,c,i,j,x,y,ans=0,tot;
   int match[N];
bool dfs(int x)
{
    for(int y=1;y<=b;++y)
    {
       if(vis[y]||v[x][y])continue;
       vis[y]=1;
       if(!match[y]||dfs(match[y]))
       {
          match[y]=x; 
          return true;
       } 
    }
    return false;
}
int main()
{
   tot=0;
   scanf("%d%d%d",&a,&b,&c);
   for(i=1;i<=c;++i)
   {
        scanf("%d%d",&x,&y);
        v[x][y]=1;
   } 
   for(i=1;i<=a;++i)
   {
      memset(vis,0,sizeof(vis));
      if(dfs(i))ans++; 
   }
   cout<<ans;
   return 0;
}
