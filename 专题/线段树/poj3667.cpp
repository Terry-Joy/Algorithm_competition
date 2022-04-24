#include<iostream>
#include<cstdio>
#include<cstring>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=5e4+5;
int n,m,a,b,c;
struct Node{ 
    int lsum,rsum,sum,add;//0,1,-1 空 满 初始化不向下传递标记
}tr[maxn<<2];
void pushUp(int p,int l,int r,int mid){ 
    tr[p].sum=max(max(tr[ls].sum,tr[rs].sum),tr[ls].rsum+tr[rs].lsum);
    tr[p].lsum=tr[ls].lsum;
    tr[p].rsum=tr[rs].rsum;
    if(tr[p].lsum==mid-l+1)tr[p].lsum+=tr[rs].lsum;
    if(tr[p].rsum==r-mid)tr[p].rsum+=tr[ls].rsum;
}
void build(int p,int l,int r){ 
    tr[p].add=-1;
    tr[p].lsum=tr[p].rsum=tr[p].sum=r-l+1;
    if(l==r)return;
    int mid=l+r>>1;
    build(lson);
    build(rson);
}
void pushDown(int p,int l,int r,int mid){
    if(tr[p].add!=-1){ 
        tr[ls].add=tr[rs].add=tr[p].add;
        int flag=(tr[p].add?0:1);
        tr[ls].sum=tr[ls].lsum=tr[ls].rsum=(flag?mid-l+1:0);
        tr[rs].sum=tr[rs].lsum=tr[rs].rsum=(flag?r-mid:0);
        tr[p].add=-1;
    }
}
void change(int p,int l,int r,int L,int R,int val){ 
    if(L<=l&&r<=R){ 
        tr[p].lsum=tr[p].rsum=tr[p].sum=(val?0:(r-l+1));
        tr[p].add=val;
        return;
    }
    int mid=l+r>>1;
    pushDown(p,l,r,mid);
    if(L<=mid)change(lson,L,R,val);
    if(R>mid)change(rson,L,R,val);
    pushUp(p,l,r,mid);
}
int query(int p,int l,int r,int val){ 
    if(l==r&&val==1)return l;//特判只有一个
    int mid=l+r>>1;
    pushDown(p,l,r,mid);
    if(tr[ls].sum>=val)return query(lson,val);
    else if(tr[ls].rsum+tr[rs].lsum>=val)return mid-tr[ls].rsum+1;
    else if(tr[rs].sum>=val)return query(rson,val);
    else return 0;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    build(1,1,n);
    for(int i=1;i<=m;++i){ 
        cin>>a;
        if(a==2){ 
            cin>>b>>c;
            change(1,1,n,b,b+c-1,0);
        }else{ 
            cin>>b;
            int tmp=query(1,1,n,b);
            cout<<tmp<<"\n";
            if(tmp)change(1,1,n,tmp,tmp+b-1,1);    
        } 
    }
    return 0;
}
