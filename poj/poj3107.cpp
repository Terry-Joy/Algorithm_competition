#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5e4+10,M=1e5+10;
int tot,maxl=0x3f3f3f3f,sum[N],maxsum[N];
int head[N],next1[M],ver[M],n;
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa)
{
   for(int i=head[now];i;i=next1[i])
   {
      int y=ver[i];
      if(y==fa)continue;
      dfs(y,now);
      sum[now]+=sum[y];
      maxsum[now]=max(maxsum[now],sum[y]); 
   } 
   maxsum[now]=max(maxsum[now],n-sum[now]);
   maxl=min(maxl,maxsum[now]);
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
      sum[i]=1; 
   } 
   sum[n]=1;
   dfs(1,0);
   for(int i=1;i<=n;++i)
       if(maxsum[i]==maxl)
           printf("%d ",i);
   return 0; 
}
