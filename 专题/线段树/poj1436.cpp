#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=8005;
struct Node{ 
    int y1,y2,x;
    bool operator<(const Node&a)const
    {
       return x<a.x; 
    }
}node[maxn];
bool vis[maxn][maxn];
int lazy[maxn<<3],t,n;
void pushDown(int p)
{
   if(lazy[p])
   {
      lazy[ls]=lazy[rs]=lazy[p];
      lazy[p]=0; 
   } 
}
void query(int p,int l,int r,int L,int R,int x)
{
   if(lazy[p])
   {
      vis[lazy[p]][x]=vis[x][lazy[p]]=1;
      return; 
   } 
   if(l==r)return;
   pushDown(p);
   int mid=l+r>>1;
   if(L<=mid)query(lson,L,R,x);
   if(R>mid)query(rson,L,R,x);
}
void update(int p,int l,int r,int L,int R,int x)
{
   if(L<=l&&r<=R){ 
       lazy[p]=x;
       return;
   }
   pushDown(p);
   int mid=l+r>>1;
   if(L<=mid)update(lson,L,R,x);
   if(R>mid)update(rson,L,R,x);
}
int main()
{
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      for(int i=1;i<=n;++i)
         for(int j=1;j<=n;++j)
            vis[i][j]=0;
      int mx=-1;
      for(int i=1;i<=n;++i)
         scanf("%d%d%d",&node[i].y1,&node[i].y2,&node[i].x),mx=max(mx,node[i].y2);
      mx<<=1;
      for(int i=0;i<=4*mx;++i)
          lazy[i]=0;
      sort(node+1,node+1+n);
      for(int i=1;i<=n;++i)
      {
         query(1,0,mx,2*node[i].y1,2*node[i].y2,i);
         update(1,0,mx,2*node[i].y1,2*node[i].y2,i);
      } 
      ll ans=0;
      for(int i=1;i<=n;++i)
          for(int j=i+1;j<=n;++j)
          {
             if(!vis[i][j])continue;
             for(int k=i+1;k<j;++k)
                 if(vis[i][k]&&vis[j][k])
                     ans++;
          }
      printf("%lld\n",ans);
   } 
   return 0; 
}
