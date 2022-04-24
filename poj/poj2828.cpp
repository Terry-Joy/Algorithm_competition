#include<iostream>
#include<cstdio>
#include<cstring>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=2e5+5;
int sum[maxn<<2];
int pos[maxn],val[maxn],n,ans[maxn];
void pushUp(int p)
{
   sum[p]=sum[ls]+sum[rs]; 
}
void build(int p,int l,int r)
{
   if(l==r){ sum[p]=1;return;}
   int mid=l+r>>1;
   build(lson);
   build(rson);
   pushUp(p); 
}
void update(int p,int l,int r,int num,int x)
{
   if(l==r&&sum[p]==1)
   { 
      ans[l]=val[x],sum[p]=0;
      return;
   }
   int mid=l+r>>1;
   if(num>sum[ls])
      update(rson,num-sum[ls],x);
   else 
      update(lson,num,x);
   pushUp(p); 
}
int main()
{
    while(~scanf("%d",&n))
    { 
       for(int i=1;i<=n;++i)
           scanf("%d%d",&pos[i],&val[i]);
       build(1,0,n-1);
       for(int i=n;i;--i)
          update(1,0,n-1,pos[i]+1,i); 
       for(int i=0;i<=n-1;++i)
           printf("%d ",ans[i]);
       puts("");
    }
   return 0;
}
