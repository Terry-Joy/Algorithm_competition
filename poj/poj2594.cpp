#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int N=510,M=5010;
bool dp[N][N],vis[N];
int n,m,match[N];

bool dfs(int x)
{
   for(int i=1;i<=n;++i)
   {
      if(dp[x][i]&&!vis[i])
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
    while(~scanf("%d%d",&n,&m)&&(n|m))
    {
        int i,j,a,b,k;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                dp[i][j]=0;
        for(i=1;i<=n;++i)
            match[i]=0;
        for(i=1;i<=m;++i)
        { 
            scanf("%d%d",&a,&b);
            dp[a][b]=1;
        }
        for(k=1;k<=n;++k)
            for(i=1;i<=n;++i)
                for(j=1;j<=n;++j)
                    dp[i][j]|=dp[i][k]&dp[k][j];
        //求DAG的有相交的最小路径点覆盖，邻接矩阵已经帮你拆点成二分图了
        int ans=0;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                vis[j]=0;
            if(dfs(i))ans++;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
