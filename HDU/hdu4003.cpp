#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10010,M=20010;
const int inf=0x3f3f3f3f;
int n,s,k,head[N],ver[M],edge[M],next1[M],tot;
int dp[10010][11];
inline void add(int x,int y,int z)
{
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa)
{
    for(int i=head[now];i;i=next1[i])
    {
        int y=ver[i];
        if(y!=fa)
        {
            dfs(y,now);
            for(int K=k;K>=0;--K)
            {
                dp[now][K]+=(dp[y][0]+2*edge[i]);
                for(int j=1;j<=K;++j)
                    dp[now][K]=min(dp[now][K],dp[now][K-j]+dp[y][j]+j*edge[i]); 
            } 
        }
    } 
}
int main()
{
    while(~scanf("%d%d%d",&n,&s,&k))
    {
        tot=0;
        for(int i=0;i<=n;++i)
            head[i]=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        dfs(s,0); 
        int ans=0x7fffffff;
        for(int i=0;i<=k;++i)
            ans=min(ans,dp[s][i]);
        printf("%d\n",ans);
    }
    return 0;
}
