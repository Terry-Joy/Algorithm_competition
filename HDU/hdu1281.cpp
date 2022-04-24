#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
const int N=110;
int match[N],n,m,k,a[N*N],b[N*N];
bool map[N][N],vis[N];
bool dfs(int x)
{
   for(int i=1;i<=n;++i)
   {
      if(map[x][i]&&!vis[i])
      {
         vis[i]=1;
         if(!match[i]||dfs(match[i]))
         {
            match[i]=x;return true; 
         } 
      } 
   } 
   return false;
}
int main()
{
    int t=0;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int i,j;
        memset(map,0,sizeof(map));
        for(i=1;i<=k;++i)
        {
           scanf("%d%d",&a[i],&b[i]);
           map[a[i]][b[i]]=1; 
        }
        int ans=0,num=0,sum=0;
        for(i=1;i<=n;++i)
        {
           memset(vis,0,sizeof(vis));
           if(dfs(i))ans++; 
        }     
        for(i=1;i<=k;++i)
        {
           sum=0;
           memset(match,0,sizeof(match));
           map[a[i]][b[i]]=0;
           for(j=1;j<=n;++j)
           {
              memset(vis,0,sizeof(vis));
              if(dfs(j))sum++; 
           } 
           map[a[i]][b[i]]=1;
           if(sum!=ans)
               num++;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",++t,num,ans);
        memset(match,0,sizeof(match));
    }
    return 0;
}
