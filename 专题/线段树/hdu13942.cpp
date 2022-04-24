#include<iostream>
#include<cstdio>
#include<cstring>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=5010;
int a[maxn],sum[maxn];
void pushUp(int p)
{
   sum[p]=sum[ls]+sum[rs]; 
}
void build(int p,int l,int r)
{
   if(l==r){ sum[p]=0;return;} 
   int mid=l+r>>1;
   build(lson);
   build(rson);
   pushUp(p); 
}
int query(int p,int l,int r,int L,int R)
{
   if(L<=l&&r<=R)return sum[p];
   int mid=l+r>>1;
   int ans=0;
   if(L<=mid)ans+=query(lson,L,R);
   if(r>mid)ans+=query(rson,L,R);
   return ans; 
}
void update(int p,int l,int r,int x)
{
   if(l==r){ sum[p]++;return;}
   int mid=l+r>>1;
   if(x<=mid)update(lson,x);
   else update(rson,x);
   pushUp(p); 
}
int main()
{
   int n;
   while(~scanf("%d",&n))
   { 
       int ans=0;
       build(1,0,n-1);
       for(int i=1;i<=n;++i)
       {
          scanf("%d",&a[i]);
          ans+=query(1,0,n-1,a[i]+1,n-1);
          update(1,0,n-1,a[i]);
       }
       int res=ans;
       for(int i=1;i<=n;++i)
       { 
           ans+=(n-2*a[i]-1);
           res=min(res,ans);
       }
       printf("%d\n",res);
   }
   return 0; 
}
