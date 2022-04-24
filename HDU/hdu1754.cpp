#include<iostream>
#include<cstdio>
#include<cstring>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int N=2e5+10;
const int INF=0x3f3f3f3f;
int n,m,a[N];
struct SegmentTree
{
   int l,r,sum; 
}tr[N<<2];
void pushUp(int p)
{
   tr[p].sum=max(tr[ls].sum,tr[rs].sum); 
}
void build(int p,int l,int r)
{
   tr[p].l=l,tr[p].r=r;
   if(l==r){ tr[p].sum=a[l];return;}
   int mid=l+r>>1;
   build(lson);
   build(rson);
   pushUp(p); 
}
void update(int p,int l,int r,int x,int val)
{
   if(l==r){ tr[p].sum=val;return;}
   int mid=l+r>>1;
   if(x<=mid)update(lson,x,val);
   else update(rson,x,val);
   pushUp(p); 
}
int ask(int p,int l,int r,int lq,int rq)
{
   if(lq<=l&&r<=rq)return tr[p].sum;
   int mid=l+r>>1;
   int val=-INF;
   if(lq<=mid)val=max(val,ask(lson,lq,rq));
   if(rq>mid) val=max(val,ask(rson,lq,rq));
   return val;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        build(1,1,n);
        char s[6];
        for(int i=1;i<=m;++i)
        {
           scanf("%s",s);
           int x,y;
           scanf("%d%d",&x,&y);
           if(s[0]=='Q')
               printf("%d\n",ask(1,1,n,x,y));
           else
               update(1,1,n,x,y);
        }
    }
    return 0;
}
