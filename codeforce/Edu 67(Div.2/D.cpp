#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long 
#define ls rt<<1
#define rs rt<<1|1
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
using namespace std;
const int maxn=3e5+5;
int tr[maxn<<2];
queue<int>q[maxn];
int a[maxn],b[maxn];
const int inf=0x3f3f3f3f;
void build(int rt,int l,int r)
{
   if(l==r)
   {
      tr[rt]=a[l];
      q[a[l]].push(l);
      return; 
   } 
   int mid=l+r>>1;
   build(lson);
   build(rson);
   tr[rt]=min(tr[ls],tr[rs]);
}
void update(int rt,int l,int r,int x,int k)
{
   if(l==r)
   {
      tr[rt]=k;
      return; 
   } 
   int mid=l+r>>1;
   if(x<=mid)update(lson,x,k);
   else update(rson,x,k);
   tr[rt]=min(tr[ls],tr[rs]);
}
int query(int rt,int l,int r,int x,int y)
{
   if(x<=l&&r<=y)
   {
      return tr[rt]; 
   } 
   int mid=l+r>>1;
   int val=(1<<30);
   if(x<=mid)val=min(val,query(lson,x,y));
   if(y>mid)val=min(val,query(rson,x,y));
   return val;
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n;
      scanf("%d",&n);
      for(int i=1;i<=n;++i)
      {
         scanf("%d",&a[i]);
         while(!q[a[i]].empty())    
             q[a[i]].pop();
         
      } 
      build(1,1,n);
      for(int i=1;i<=n;++i)
          scanf("%d",&b[i]);
      int flag=1;
      for(int i=1;i<=n;++i)
        {
           int k;
           if(!q[b[i]].empty())
           {
              k=q[b[i]].front();
              q[b[i]].pop(); 
           } 
           else 
		   { 
                flag=0;
                break;
           }
           int minn=query(1,1,n,1,k);
           if(minn!=b[i])
           {
              flag=0;
              break; 
           }
           else update(1,1,n,k,inf);
        }
      if(flag)puts("YES");
      else puts("NO");
   }
   return 0; 
}
