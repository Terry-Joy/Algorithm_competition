#include<iostream>
#include<cstdio>
#include<cstring>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=1e5+10;
struct Node
{
   int l,r,sum,add; 
}tr[maxn<<2];
void spread(int p)
{
   if(tr[p].add)
   {
      tr[ls].sum=(tr[ls].r-tr[ls].l+1)*tr[p].add;
      tr[rs].sum=(tr[rs].r-tr[rs].l+1)*tr[p].add;
      tr[ls].add=tr[rs].add=tr[p].add;
      tr[p].add=0;
   } 
}
void build(int p,int l,int r)
{
   tr[p].l=l;tr[p].r=r;
   if(l==r){tr[p].sum=1;return; } 
   int mid=l+r>>1;
   build(lson);
   build(rson);
   tr[p].sum=tr[ls].sum+tr[rs].sum;
}
void change(int p,int l,int r,int L,int R,int x)
{
   if(L<=l&&r<=R){tr[p].sum=(tr[p].r-tr[p].l+1)*x;tr[p].add=x;return; } 
   spread(p);
   int mid=l+r>>1;
   if(L<=mid)change(lson,L,R,x);
   if(R>mid)change(rson,L,R,x);
   tr[p].sum=tr[ls].sum+tr[rs].sum;
}
int main()
{
   int t,f=0;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      build(1,1,n);
      for(int i=1;i<=n;++i)
          tr[i].add=0;
      int q;
      scanf("%d",&q);
      int l,r,x;
      while(q--)
      {
         scanf("%d%d%d",&l,&r,&x);
         change(1,1,n,l,r,x);
      }
      printf("Case %d: The total value of the hook is %d.\n",++f,tr[1].sum);
   } 
   return 0; 
}
