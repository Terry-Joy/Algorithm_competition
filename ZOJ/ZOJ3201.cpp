#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctype.h>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <queue>
#include <map>
#include <vector>
using namespace std;
const int maxn=105;
vector<int> tree[maxn];
int n,k;
int dp[maxn][maxn];
int vis[maxn];//标记是否被访问
int Maxn;
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(!vis[v])
        {
            dfs(v);
            for(int j=k;j>=1;j--)
                for(int m=1;m<j;m++)
                    dp[u][j]=max(dp[u][j],dp[u][m]+dp[v][j-m]);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        Maxn=0;
        for(int i=0;i<n;i++)
            tree[i].clear();
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            scanf("%d",&dp[i][1]);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(0);
        for(int i=0;i<n;i++)
        {
            if(dp[i][k]>Maxn)
                Maxn=dp[i][k];
        }
        printf("%d\n",Maxn);
    }
}
