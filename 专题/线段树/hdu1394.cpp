#include<iostream>
#include<cstring>
#include<cstdio>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
int a[5010],sum[5010];//计算每个数的出现次数
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

void update(int p,int l,int r,int x)
{
   if(l==r){ sum[p]++;return;} 
   int mid=l+r>>1;
   if(x<=mid)update(lson,x);
   else update(rson,x);
   pushUp(p);
}
int query(int p,int l,int r,int ln,int rn)
{
   if(ln<=l&&r<=rn)return sum[p];
   int mid=l+r>>1;
   int ans=0;
   if(ln<=mid)ans+=query(lson,ln,rn);
   if(rn>mid)ans+=query(rson,ln,rn);
   return ans; 
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
       build(1,0,n-1);
       int res=0; 
       for(int i=1;i<=n;++i)
       {
           scanf("%d",&a[i]);
           res+=query(1,0,n-1,a[i]+1,n-1);  //计算初始逆序对
           update(1,0,n-1,a[i]);          
       } 
       int ans=res;
       for(int i=1;i<=n;++i)
       {
          ans+=(n-2*a[i]-1);
          res=min(ans,res);
       }
       printf("%d\n",res);
    }
    return 0;
}
