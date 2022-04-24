#include<iostream>
#include<cstdio>
#include<cstring>
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r
#define ls  p<<1
#define rs  p<<1|1
using namespace std;
const int N=5e4+10;
char s[6];
int a[N];
struct Node{ 
    int l,r,sum;
}tr[N<<2];

void pushUp(int p)
{ 
    tr[p].sum=tr[ls].sum+tr[rs].sum;
}
void build(int p,int l,int r)
{
    tr[p].l=l,tr[p].r=r;
    if(l==r){ tr[p].sum=a[l];return;}
    int mid=l+r>>1;
    build(lson);
    build(rson);
    pushUp(p);
}

void update(int p,int l,int r,int x,int val)
{ 
    if(l==r){tr[p].sum+=val;return;}
    int mid=l+r>>1;
    if(x<=mid)update(lson,x,val);
    else update(rson,x,val);
    pushUp(p);
}

int ans(int p,int l,int r,int lq,int rq)
{
    if(lq<=l&&r<=rq)return tr[p].sum;
    int mid=l+r>>1;
    int x=0;
    if(lq<=mid)x+=ans(lson,lq,rq);
    if(rq>mid)x+=ans(rson,lq,rq); 
    return x;
}

int main()
{
    int t;
    scanf("%d",&t);
    int k=0;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        build(1,1,n);
        printf("Case %d:\n",++k);
        while(~scanf("%s",s)&&s[0]!='E')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(s[0]=='A') 
                update(1,1,n,x,y);
            else if(s[0]=='S')
                update(1,1,n,x,-y);
            else 
                printf("%d\n",ans(1,1,n,x,y));
        }
    }
    return 0; 
}
