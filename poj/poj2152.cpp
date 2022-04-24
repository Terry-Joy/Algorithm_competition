#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+5;
const int M=2e3+5;
const int inf=0x3f3f3f3f;
int tot,head[maxn],next1[M],ver[M],edge[M],dis[maxn],dp[maxn][maxn];
int best[maxn],n,d[maxn],w[maxn];
void add(int x,int y,int z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
void getdis(int now,int fa,int len)
{
   dis[now]=len;
   for(int i=head[now];i;i=next1[i])
   {
      int y=ver[i];
      if(y==fa)continue;
      getdis(y,now,len+edge[i]); 
   } 
}
void dfs(int now,int fa)
{
   for(int i=head[now];i;i=next1[i])
   {
        if(ver[i]!=fa)
           dfs(ver[i],now); 
   } 
   getdis(now,0,0);
   best[now]=inf;
   for(int i=1;i<=n;++i)
   {
      if(dis[i]>d[now])dp[now][i]=inf;
      else
      {
         dp[now][i]=w[i];
         for(int j=head[now];j;j=next1[j])
         {
            int y=ver[j];
            if(y==fa)continue;
            dp[now][i]+=min(best[y],dp[y][i]-w[i]); 
         } 
      } 
      best[now]=min(best[now],dp[now][i]);
   }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       tot=0;
       for(int i=1;i<=n;++i)
          head[i]=0;
       for(int i=1;i<=n;++i)
          scanf("%d",&w[i]);
       for(int i=1;i<=n;++i)
          scanf("%d",&d[i]);
       for(int i=1;i<n;++i)
       {
          int a,b,c;
          scanf("%d%d%d",&a,&b,&c);
          add(a,b,c);
          add(b,a,c); 
       } 
       dfs(1,0);
       printf("%d\n",best[1]);
    }
    return 0;
}
