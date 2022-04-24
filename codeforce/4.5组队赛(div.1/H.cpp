#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define ls  rt<<1 
#define rs  rt<<1|1
using namespace std;
const int maxn=1e5+5;
int n,k,ans[maxn];
struct Node
{
   int l,r,val;
   bool operator<(const Node&a)const
   {
      if(r==a.r)return l<a.l;
      return r<a.r; 
   } 
}q[maxn];

struct node
{
   int l,r,sum; 
}tr[maxn<<2];
bool vis[maxn];

void build(int rt,int l,int r)
{ 
    tr[rt].l=l,tr[rt].r=r;
    if(l==r)
    {
       if(ans[l]==1)
          tr[rt].sum=1;
       else
          tr[rt].sum=-1;
       return; 
    }
    int mid=l+r>>1;
    build(lson);
    build(rson);
    tr[rt].sum=tr[ls].sum+tr[rs].sum;
}

void update(int rt,int l,int r,int x,int val)//单点更新
{
   if(l==r)
   {
      tr[rt].sum=val;
      return; 
   } 
   int mid=l+r>>1;
   if(x<=mid)update(lson,x,val);
   else update(rson,x,val);
   tr[rt].sum=tr[ls].sum+tr[rs].sum;
}

int query(int rt,int l,int r,int x,int y)
{
   if(x<=l&&r<=y)
      return tr[rt].sum;
   int mid=l+r>>1;
   int res=0;
   if(x<=mid)res+=query(lson,x,y);
   if(y>mid)res+=query(rson,x,y);
   return res;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
    {
       scanf("%d",&ans[i]);
       if(!ans[i])
       {
          ans[i]=-1;
          vis[i]=1; 
       } 
    }
    for(int i=1;i<=k;++i)
        scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].val);
    sort(q+1,q+1+k);
    build(1,1,n);
    bool f=1;
    for(int i=1;i<=k;++i)
    {
       int sum=query(1,1,n,q[i].l,q[i].r);
       if(sum>=q[i].val)continue;
       int cha=q[i].val-sum;
       int l=q[i].l,r=q[i].r;
       while(cha>0&&l<=r)
       {
          if(vis[r])
          {
             vis[r]=0;
             ans[r]=1;
             update(1,1,n,r,1);
             cha-=2; 
          } 
          r--;
       } 
       if(cha>0)
       {
          f=0;
          break; 
       }
    }
    if(!f)
        puts("Impossible");
    else 
        for(int i=1;i<=n;++i)
            printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}
