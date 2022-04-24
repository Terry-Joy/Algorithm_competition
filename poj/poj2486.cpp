#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=110,M=210;
int head[N],next1[M],ver[M],tot,dp[N][M][2],n,k;
int a[N];
void add(int x,int y)
{
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa)
{
    for(int i=head[now];i;i=next1[i])
    {
        if(ver[i]!=fa)
        {
            dfs(ver[i],now);
            int y=ver[i];
            for(int j=k;j>=1;--j)
                for(int k=1;k<=j;++k)
                {
                    if(k>=2)dp[now][j][0]=max(dp[now][j][0],dp[now][j-k][0]+dp[y][k-2][0]);
                    if(k>=1)dp[now][j][1]=max(dp[now][j][1],dp[now][j-k][0]+dp[y][k-1][1]);
                    if(k>=2)dp[now][j][1]=max(dp[now][j][1],dp[now][j-k][1]+dp[y][k-2][0]); 
                }
        } 
    } 
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        tot=0;
        for(int i=1;i<=n;++i)
        {    
            scanf("%d",&a[i]);
            head[i]=0;
        }
        for(int i=1;i<=n;++i)
            for(int j=0;j<=k;++j)
                dp[i][j][0]=dp[i][j][1]=a[i];
        for(int i=1;i<n;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a); 
        }
        dfs(1,0);
        printf("%d\n",dp[1][k][1]);
    }
    return 0;
}
