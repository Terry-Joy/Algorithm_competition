#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct Node{ 
   ll sum;
   int add,l,r; 
   #define l(x) tr[x].l 
   #define r(x) tr[x].r
   #define sum(x) tr[x].sum
   #define add(x) tr[x].add
}tr[maxn<<2];
ll a[maxn];
char s[5];
void spread(int p)
{
    if(add(p))
    {
       sum(ls)+=1ll*add(p)*(r(ls)-l(ls)+1);
       sum(rs)+=1ll*add(p)*(r(rs)-l(rs)+1);
       add(ls)+=add(p);
       add(rs)+=add(p);
       add(p)=0;
    }
}
ll query(int p,int L,int R)
{
   if(L<=l(p)&&r(p)<=R)return sum(p);
   spread(p);//下传延迟标记
   int mid=l(p)+r(p)>>1;
   ll ans=0;
   if(L<=mid)ans+=query(ls,L,R);
   if(R>mid)ans+=query(rs,L,R);
   return ans;
}
void update(int p,int L,int R,int c)
{
    if(L<=l(p)&&r(p)<=R)
    {
       sum(p)+=(r(p)-l(p)+1)*c;
       add(p)+=c;
       return; 
    } 
    spread(p);
    int mid=l(p)+r(p)>>1;
    if(L<=mid)update(ls,L,R,c);
    if(R>mid)update(rs,L,R,c);
    sum(p)=sum(ls)+sum(rs);
}
void build(int p,int l,int r)
{
    l(p)=l,r(p)=r;
    if(l==r){sum(p)=a[l];return;}
    int mid=l(p)+r(p)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    sum(p)=sum(ls)+sum(rs);
}
int main()
{
   int n,q;
   scanf("%d%d",&n,&q);
   for(int i=1;i<=n;++i)
      scanf("%lld",&a[i]);
   build(1,1,n);
   for(int i=1;i<=q;++i)
   {
      scanf("%s",s);
      int a,b,c;
      scanf("%d%d",&a,&b);
      if(s[0]=='C')
      {
         scanf("%d",&c);
         update(1,a,b,c); 
      } 
      else printf("%lld\n",query(1,a,b));
   } 
   return 0; 
}
