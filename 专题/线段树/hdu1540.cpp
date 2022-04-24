#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define len(x) tr[x].r-tr[x].l+1
using namespace std;
const int maxn=5e4+5;
struct Node{ 
    int l,r,lmax,rmax,mx;
}tr[maxn<<2];
int st[maxn],cnt=0;
char s[3];
void pushUp(int p){ 
    tr[p].mx=max(tr[ls].mx,max(tr[rs].mx,tr[ls].rmax+tr[rs].lmax));
    tr[p].lmax=tr[ls].lmax;
    tr[p].rmax=tr[rs].rmax;
    if(tr[p].lmax==len(ls))tr[p].lmax+=tr[rs].lmax;
    if(tr[p].rmax==len(rs))tr[p].rmax+=tr[ls].rmax;
}
void build(int p,int l,int r){ 
    tr[p].l=l,tr[p].r=r;
    if(l==r){ tr[p].lmax=tr[p].rmax=tr[p].mx=1;return;}
    int mid=l+r>>1;
    build(lson);
    build(rson);
    pushUp(p);
}
int query(int p,int l,int r,int x){ 
    if(l==r||tr[p].mx==len(p)||tr[p].mx==0)return tr[p].mx;
    int mid=l+r>>1;
    if(x<=mid){ 
        if(x>=mid-tr[ls].rmax+1)return query(lson,x)+query(rson,mid+1);
        else return query(lson,x);
    }else{ 
        if(x<=mid+tr[rs].lmax)return query(lson,mid)+query(rson,x);
        else return query(rson,x);
    }
}
void change(int p,int l,int r,int x,int val){ 
    if(l==r){ tr[p].lmax=tr[p].rmax=tr[p].mx=val;return;}
    int mid=l+r>>1;
    if(x<=mid)change(lson,x,val);
    else change(rson,x,val);
    pushUp(p);
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a;
    while(cin>>n>>m){ 
        build(1,1,n);
        cnt=0;
        for(int i=1;i<=m;++i){ 
            cin>>s;
            if(s[0]=='D'){ 
                cin>>a;
                st[++cnt]=a;
                change(1,1,n,a,0);
            }else if(s[0]=='Q'){ 
                cin>>a;
                cout<<query(1,1,n,a)<<"\n";
            }else{ 
                a=st[cnt--];
                change(1,1,n,a,1);
            }
        }
    }
    return 0;
}
