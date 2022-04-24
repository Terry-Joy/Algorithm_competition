#include<iostream>
#include<cstdio>
#include<cstring>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=4e5+20;
const int base=2e5+5;
int sum[maxn<<2],lazy[maxn<<2],add=0,ans=0;
void pushDown(int p)
{
   if(lazy[p]) 
   {
      sum[ls]=sum[rs]=0;
      lazy[ls]=lazy[rs]=1;
      lazy[p]=0; 
   }
}
void insert(int p,int l,int r,int pos)
{
   if(l==r){ 
       if(l==pos)++sum[p];
       return;
   } 
   pushDown(p);
   int mid=l+r>>1;
   if(pos<=mid)insert(lson,pos);
   else insert(rson,pos);
   sum[p]=sum[ls]+sum[rs];
}
void update(int p,int l,int r,int L,int R)
{
   if(L<=l&&r<=R) {
       sum[p]=0;
       lazy[p]=1;
       return; 
   }
   pushDown(p);
   int mid=l+r>>1;
   if(L<=mid)update(lson,L,R);
   if(R>mid)update(rson,L,R);
   sum[p]=sum[ls]+sum[rs];
}
int Kth(int p,int l,int r,int k)//查询第k小
{
   if(l==r)return l;
   pushDown(p);
   int mid=l+r>>1;
   if(sum[rs]>=k)return Kth(rson,k);
   else return Kth(lson,k-sum[rs]);
}
int main()
{
   int n,mn;
   scanf("%d%d",&n,&mn); 
   memset(sum,0,sizeof(sum));
   memset(lazy,0,sizeof(lazy));
   while(n--)
   {
      char c;int k;
      scanf(" %c%d",&c,&k);
      if(c=='I'){ 
         if(k>=mn)
         {
            ans++;
            insert(1,1,maxn-1,k-add+base);
         }
      } 
      else if(c=='A')add+=k;
      else if(c=='S'){ 
           add-=k;
           update(1,1,maxn-1,1,mn-add+base-1);//x+add<mn 则 x+1<=mn-add 
      }
      else{ 
          if(sum[1]<k)puts("-1");
          else printf("%d\n",Kth(1,1,maxn-1,k)+add-base);
      }
   }
   printf("%d\n",ans-sum[1]);
   return 0; 
}
