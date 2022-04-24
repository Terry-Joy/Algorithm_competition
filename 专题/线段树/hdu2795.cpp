#include<iostream>
#include<cstdio>
#include<cstring>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;

const int maxn=2e5+5;
int tr[maxn<<2];
int h,w,n,a;
void build(int p,int l,int r)
{
   tr[p]=w;
   if(l==r)return; 
   int mid=l+r>>1;
   build(lson);
   build(rson);
}
int query(int p,int l,int r,int sum)
{
   if(l==r){ 
       tr[p]-=sum;
       return l; 
   } 
   int mid=l+r>>1;
   int ans;
   ans=((tr[ls]>=sum)?query(lson,sum):query(rson,sum));
   tr[p]=max(tr[ls],tr[rs]);
   return ans;
}
int main()
{
   while(~scanf("%d%d%d",&h,&w,&n))
   {
      if(h>n)
         h=n;
      build(1,1,h);
      for(int i=1;i<=n;++i)
      {
         scanf("%d",&a);
         if(a>tr[1]) 
             puts("-1");
         else
             printf("%d\n",query(1,1,h,a));
      } 
   } 
   return 0; 
}
