#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=1e4+10;
int lazy[maxn<<5],al[maxn],ar[maxn],n,a[maxn<<3];
bool v[maxn];
void pushDown(int p)
{
   if(lazy[p]) 
   {
      lazy[ls]=lazy[p];
      lazy[rs]=lazy[p];
      lazy[p]=0;
      return; 
   }
}
int query(int p,int l,int r)
{
    if(lazy[p])
    {
       if(!v[lazy[p]]){ v[lazy[p]]=1;return 1;}
       else return 0; 
    }
    if(l==r)return 0;
    int mid=l+r>>1;
    int ans=0;
    ans+=query(lson);
    ans+=query(rson);
    return ans;
}
void update(int p,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R)
    {
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
   int t;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      int cnt=0;
      for(int i=1;i<=n;++i)
        scanf("%d%d",&al[i],&ar[i]),a[++cnt]=al[i],a[++cnt]=ar[i];
      sort(a+1,a+1+cnt);
      int m=unique(a+1,a+1+cnt)-(a+1);
      for(int i=m;i>=2;--i)                      //改变m的时候注意一下要倒序
          if(a[i]!=(1+a[i-1]))
              a[++m]=a[i-1]+1;
      sort(a+1,a+1+m);
      for(int i=1;i<=n;++i)
          v[i]=0;
      for(int i=1;i<=8*m;++i)
          lazy[i]=0;
      for(int i=1;i<=n;++i)
      {
          int l=lower_bound(a+1,a+1+m,al[i])-a;
          int r=lower_bound(a+1,a+1+m,ar[i])-a;
          update(1,1,m,l,r,i);  
      }
      printf("%d\n",query(1,1,m));
   } 
   return 0; 
}
