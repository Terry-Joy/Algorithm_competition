#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#define ll long long 
const int maxn=110;
using namespace std;
int head[maxn],ver[maxn<<1],next1[maxn<<1],tot,n,m,clo[maxn],vis[maxn];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
int dfs(int now,int fa,int li,int d)
{
   int ans=clo[now];
   if(li==d)return ans;
   for(int i=head[now];i;i=next1[i])
   {
      int y=ver[i];
      if(!vis[y]||y==fa)continue;
      ans+=dfs(y,now,li,d+1); 
   } 
   return ans;
}
bool check(int mid)
{
   memset(vis,0,sizeof(vis));
   queue<int>q;
   q.push(1);
   while(q.size())
   {
      int x=q.front();q.pop();
      vis[x]=1;
      if(dfs(x,0,mid,0)>=m)return true;
      for(int i=head[x];i;i=next1[i])
        {
           int y=ver[i];
           if(vis[y])continue;
           q.push(y); 
        } 
   } 
   return false;
}
int main()
{
   scanf("%d%d",&n,&m);
   tot=0;
   for(int i=1;i<=n;++i)
       scanf("%d",&clo[i]);
   int a,b;
   for(int i=1;i<n;++i)
   {
      scanf("%d%d",&a,&b);
      add(a,b);
      add(b,a); 
   }
   int l=0,r=n,mid;
   while(l<r)
   {
      int mid=l+r>>1;
      if(check(mid))
        r=mid;
      else l=mid+1; 
   }
   printf("%d\n",r);
   return 0; 
}
