#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=1e5+5,maxm=2e5+10;
int head[maxn],tr,ver[maxm],edge[maxm],next1[maxm],tot,fa[maxn][21],Root[maxn],ans[maxn];
int n,m,d[maxn],num,mx=1e5;
struct Node{ 
    int ls,rs,ans,times;
}t[maxn*80];
void add(int x,int y)
{
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int now,int pre)
{
    fa[now][0]=pre,d[now]=d[pre]+1;
    for(int i=head[now];i;i=next1[i])
    {
       if(ver[i]!=pre) 
          dfs(ver[i],now);
    }
}
void init()
{
   for(int i=1;i<=tr;++i)
      for(int j=1;j<=n;++j)
         fa[j][i]=fa[fa[j][i-1]][i-1]; 
}
int lca(int x,int y)
{ 
    if(d[x]>d[y])swap(x,y);
    for(int i=tr;i>=0;--i)
        if(d[fa[y][i]]>=d[x])y=fa[y][i];
    if(x==y)return x;
    for(int i=tr;i>=0;--i)
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
void pushup(int x)
{
   int ls=t[x].ls,rs=t[x].rs;
   if(t[ls].times>t[rs].times)
   {
      t[x].ans=t[ls].ans;
      t[x].times=t[ls].times; 
   } 
   else if(t[ls].times<t[rs].times)
   {
      t[x].ans=t[rs].ans;
      t[x].times=t[rs].times; 
   }
   else
   {
      if(t[ls].ans==0)t[x].ans=t[rs].ans;
      else if(t[rs].ans==0)t[x].ans=t[ls].ans;
      else t[x].ans=min(t[ls].ans,t[rs].ans);
      t[x].times=t[ls].times; 
   }
}
void Update(int &rt,int l,int r,int x,int c)
{
   if(!rt)rt=++num;
   if(l==r)
   {
       t[rt].ans=l;
       t[rt].times+=c;
       return;
   } 
   int mid=l+r>>1;
   if(x<=mid)Update(t[rt].ls,l,mid,x,c);
   else Update(t[rt].rs,mid+1,r,x,c);
   pushup(rt);
}
int merge(int x,int y,int l,int r)
{
   if(!x)return y;
   if(!y)return x;
   if(l==r)
   {
      t[x].times+=t[y].times;
      if(t[x].times>0)t[x].ans=l;
      else t[x].ans=0;
     return x; 
   }
   int mid=l+r>>1;
   t[x].ls=merge(t[x].ls,t[y].ls,l,mid);
   t[x].rs=merge(t[x].rs,t[y].rs,mid+1,r);
   pushup(x);
   return x;
}
void solve(int x)
{
   for(int i=head[x];i;i=next1[i])
   {
      if(ver[i]!=fa[x][0])
      {
         solve(ver[i]);
         Root[x]=merge(Root[x],Root[ver[i]],1,mx);
      } 
   } 
   ans[x]=t[Root[x]].ans;
}
int main()
{
   scanf("%d%d",&n,&m);
   tr=(int)log(n)/log(2)+1;
   for(int i=1;i<n;++i)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      add(a,b);
      add(b,a); 
   } 
   dfs(1,0);
   for(int i=1;i<=m;++i)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      int z=lca(a,b);
      Update(Root[a],1,mx,c,1);
      Update(Root[b],1,mx,c,1);
      Update(Root[z],1,mx,c,-1);
      Update(Root[fa[z][0]],1,mx,c,-1);
   }
   solve(1);
   for(int i=1;i<=n;++i)
       printf("%d\n",ans[i]);
   return 0; 
}
