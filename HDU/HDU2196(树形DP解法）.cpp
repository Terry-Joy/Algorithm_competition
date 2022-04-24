#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e4+5,M=2e4+10;
int head[N],next1[M],ver[M],edge[M],tot,n,dp[N][3],id[N];
void dfs(int now,int fa)
{
    for(int i=head[now];i;i=next1[i])
    {
        if(ver[i]!=fa)
        { 
            dfs(ver[i],now);
            if(dp[now][0]<dp[ver[i]][0]+edge[i])
            {
                dp[now][0]=dp[ver[i]][0]+edge[i];
                id[now]=ver[i]; 
            }
        }
    }
    for(int i=head[now];i;i=next1[i])
    {
        int y=ver[i],z=edge[i];
        if(y==fa)continue;
        if(id[now]==y)continue;
        dp[now][1]=max(dp[now][1],dp[y][0]+z); 
    } 
}
void dfs2(int now,int fa)
{
    for(int i=head[now];i;i=next1[i])
    {
        int y=ver[i],z=edge[i];
        if(fa==y)continue;
        if(y==id[now])
        {
            dp[y][2]=max(dp[now][2],dp[now][1])+z;
        } 
        else
        {
            dp[y][2]=max(dp[now][2],dp[now][0])+z; 
        }
        dfs2(y,now);
    } 
}
void add(int x,int y,int z)
{
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        tot=0;
        for(int i=0;i<=n;++i)
            head[i]=0;
        for(int i=2;i<=n;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(i,a,b);
            add(a,i,b); 
        } 
        dfs(1,0);
        dfs2(1,0);
        for(int i=1;i<=n;++i)
            printf("%d\n",max(dp[i][0],dp[i][2]));
    }
    return 0;
}
