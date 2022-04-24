#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e4+100,M=2e4+10;
int head[N],next1[M],ver[M],tot;
int n,vis[N],sum[N];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa)
{
   bool flag=1;
   for(int i=head[now];i;i=next1[i])
   {
      if(ver[i]!=fa)
      {
         dfs(ver[i],now);
         sum[now]+=sum[ver[i]];
         if(sum[ver[i]]>n/2)
            flag=0; 
      } 
   } 
   if(n-sum[now]>n/2)
       flag=0;
    if(flag)
        vis[now]=1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;++i)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       add(a,b);
       add(b,a); 
    }
    for(int i=1;i<=n;++i)
        sum[i]=1;

    dfs(1,0);
    bool flag=0;
    for(int i=1;i<=n;++i)
        if(vis[i])
            printf("%d\n",i),flag=1;
    if(!flag)
        puts("NONE");
    return 0;
}
