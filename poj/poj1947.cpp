#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=160,M=320;
int n,p,dp[160][160],next1[M],head[N],ver[M],tot,d[N];
void add(int x,int y)
{
   ver[++tot]=y, next1[tot]=head[x],head[x]=tot;
}
void dfs(int now,int fa)
{

   for(int i=head[now];i;i=next1[i])
    {
       int y=ver[i];
       if(y==fa)continue;
       dfs(y,now);
       d[now]+=d[y];
       for(int j=d[now];j>=1;--j)
          for(int k=1;k<j;++k)
            dp[now][j]=min(dp[now][j],dp[now][j-k]+dp[y][k]-1);
    }
    if(d[now]==1)
       dp[now][1]=0; 
}
int main()
{
    scanf("%d%d",&n,&p);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<n;++i)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       add(a,b);
       add(b,a);
       d[a]++; 
    }
    for(int i=1;i<=n;++i)
        dp[i][1]=d[i];
    for(int i=1;i<=n;++i)
        d[i]=1;
    dfs(1,0);
    int ans=dp[1][p];
    for(int i=2;i<=n;++i)
        ans=min(ans,dp[i][p]+1);
    printf("%d\n",ans);
    return 0;
}
