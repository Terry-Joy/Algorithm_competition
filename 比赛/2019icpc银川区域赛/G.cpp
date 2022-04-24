#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
struct SegmentTree{ 
    int add[4],mx[4];
}tr[maxn<<2];
int f[11][4]={ 
   {0,0,0,0},
   { 0,0,0,0},
   { 1,0,0,0},
   { 0,1,0,0},
   {2,0,0,0},
   { 0,0,1,0},
   {1,1,0,0},
   { 0,0,0,1},
   { 3,0,0,0},
   { 0,2,0,0},
   { 1,0,1,0}, 
};
void pushDown(int p)
{
   for(int i=0;i<4;++i)
   {
      if(tr[p].add[i])
      {
         tr[ls].mx[i]+=tr[p].add[i];
         tr[rs].mx[i]+=tr[p].add[i];
         tr[ls].add[i]+=tr[p].add[i];
         tr[rs].add[i]+=tr[p].add[i];
         tr[p].add[i]=0; 
      } 
   } 
}
void pushUp(int p)
{
   for(int i=0;i<4;++i)
      tr[p].mx[i]=max(tr[ls].mx[i],tr[rs].mx[i]);
}
void update(int p,int l,int r,int L,int R,int val)
{
   if(L<=l&&r<=R){ 
       for(int i=0;i<4;++i)
       { 
          tr[p].mx[i]+=f[val][i];
          tr[p].add[i]+=f[val][i]; 
       }
       return;
   } 
   pushDown(p);
   int mid=l+r>>1;
   if(L<=mid)update(lson,L,R,val);
   if(R>mid)update(rson,L,R,val);
   pushUp(p);
}
int query(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R){ 
        return max(max(tr[p].mx[0],tr[p].mx[1]),max(tr[p].mx[2],tr[p].mx[3]));
    }
    pushDown(p);
    int mid=l+r>>1;
    int ans=-1;
    if(L<=mid)ans=max(ans,query(lson,L,R));
    if(R>mid)ans=max(ans,query(rson,L,R));
    return ans;
}
int main()
{
   int n,q;
   scanf("%d%d",&n,&q);
   char s[10];
   int l,r,x;
   for(int i=1;i<=q;++i)
   {
      scanf("%s%d%d",s,&l,&r);
      if(s[1]=='U'){ 
           scanf("%d",&x);
           update(1,1,n,l,r,x); 
      }  
      else printf("ANSWER %d\n",query(1,1,n,l,r));
   } 
   return 0; 
}
