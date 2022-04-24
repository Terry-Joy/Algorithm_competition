#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const double PI=acos(-1.0);
const int maxn=1e4+10;
struct Node{ 
    double x,y,lazy;
}tr[maxn<<2];
double y[maxn];
double angle[maxn];
const double eps=1e-8;
int n,c,a;
void build(int p,int l,int r)
{
	tr[p].lazy=0;	
    if(l==r){ 
        tr[p].x=0;tr[p].y=y[l];return;
    }
    int mid=l+r>>1;
    build(lson);
    build(rson);
    tr[p].y=tr[ls].y+tr[rs].y;
    tr[p].x=tr[ls].x+tr[rs].x;	
}
void pushDown(int p)
{
    if(fabs(tr[p].lazy)>eps)
    {
       tr[ls].lazy+=tr[p].lazy;
       tr[rs].lazy+=tr[p].lazy;
       double x1=tr[ls].x,x2=tr[rs].x,y1=tr[ls].y,y2=tr[rs].y;
       tr[ls].x=x1*cos(tr[p].lazy)-y1*sin(tr[p].lazy);//因为是增量所以加的是根节点
       tr[ls].y=x1*sin(tr[p].lazy)+y1*cos(tr[p].lazy);
       tr[rs].x=x2*cos(tr[p].lazy)-y2*sin(tr[p].lazy);
       tr[rs].y=x2*sin(tr[p].lazy)+y2*cos(tr[p].lazy);
       tr[p].lazy=0;return; 
    }
}
void update(int p,int l,int r,int L,int R,double x)
{
   if(L<=l&&r<=R){ 
   		double x1=tr[p].x,y1=tr[p].y;
        tr[p].x=x1*cos(x)-y1*sin(x);
        tr[p].y=x1*sin(x)+y1*cos(x);
        tr[p].lazy+=x;
        return;
   } 
   pushDown(p);
   int mid=l+r>>1;
   if(L<=mid)update(lson,L,R,x);
   if(R>mid)update(rson,L,R,x);
   tr[p].x=tr[ls].x+tr[rs].x;
   tr[p].y=tr[ls].y+tr[rs].y; 
}

int main()
{
   bool flag=1;	 
   while(~scanf("%d%d",&n,&c))
   {
      for(int i=1;i<=n;++i)
         scanf("%lf",&y[i]),angle[i]=PI;
      build(1,1,n);
      double cas;
      if(flag)flag=0;
      else putchar('\n');
      for(int i=1;i<=c;++i)
      { 
         scanf("%d%lf",&a,&cas);
         update(1,1,n,a+1,n,cas*PI/180-angle[a]);
         angle[a]=cas*PI/180;
         printf("%.2lf %.2lf\n",tr[1].x,tr[1].y);
      }
   } 
   puts("");
   return 0; 
}
