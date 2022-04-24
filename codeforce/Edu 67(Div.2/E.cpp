#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long 
const int maxn=2e5+10;
using namespace std;
int head[maxn],next1[maxn<<1],ver[maxn<<1],tot=0;
int size[maxn],n;
ll ans;
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa)
{ 
    size[now]=1;
    for(int i=head[now];i;i=next1[i])
    {
        int y=ver[i];
        if(y==fa)continue;
          dfs(ver[i],now);
          size[now]+=size[y]; 
    }
    ans+=size[now];
}
void dfs2(int now,int fa,ll num)
{
   ans=max(ans,num);
   for(int i=head[now];i;i=next1[i])
   {
       if(ver[i]==fa)continue;
       dfs2(ver[i],now,num+n-2*size[ver[i]]); 
   } 
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
   ans=0;
   dfs(1,-1);
   dfs2(1,-1,ans);
   printf("%lld\n",ans);
   return 0; 
}
