#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define len(x) (tr[x].r-tr[x].l+1)
using namespace std;
const int maxn=1e5+5;
int a[maxn],n,m;
struct Node{ 
    int pre[2],suf[2],l,r,lazy,rev,sum1,longsum[2];//前缀01,后缀01,赋值，翻转，1个数，最长连续01
}tr[maxn<<2];
void pushUp(int p){ 
    for(int i=0;i<=1;++i){ //前后缀以及最大连续
        tr[p].pre[i]=tr[ls].pre[i];
        if(i==1&&tr[ls].sum1==len(ls))
            tr[p].pre[i]+=tr[rs].pre[i];
        else if(i==0&&tr[ls].sum1==0)
            tr[p].pre[i]+=tr[rs].pre[i];

        tr[p].suf[i]=tr[rs].suf[i];
        if(i==1&&tr[rs].sum1==len(rs))
            tr[p].suf[i]+=tr[ls].suf[i];
        else if(i==0&&tr[rs].sum1==0)
            tr[p].suf[i]+=tr[ls].suf[i];
        tr[p].longsum[i]=max(tr[ls].longsum[i],max(tr[ls].suf[i]+tr[rs].pre[i],tr[rs].longsum[i]));
    }
    tr[p].sum1=tr[ls].sum1+tr[rs].sum1;
}
void build(int p,int l,int r){ 
    tr[p].l=l,tr[p].r=r;tr[p].lazy=-1;tr[p].rev=0;
    if(l==r){ 
        tr[p].sum1=tr[p].pre[1]=tr[p].suf[1]=tr[p].longsum[1]=(a[l]==1);
        tr[p].pre[0]=tr[p].suf[0]=tr[p].longsum[0]=(a[l]==0);
        return;
    }
    int mid=l+r>>1;
    build(lson);
    build(rson);
    pushUp(p);
}
void pushDown(int p){ 
    if(tr[p].lazy!=-1){ 
        tr[p].rev=0;//lazy优先级更高
        tr[ls].rev=tr[rs].rev=0;
        tr[ls].lazy=tr[rs].lazy=tr[p].lazy;
        int op=tr[p].lazy;
        tr[ls].pre[op]=tr[ls].suf[op]=tr[ls].longsum[op]=len(ls);
        tr[rs].pre[op]=tr[rs].suf[op]=tr[rs].longsum[op]=len(rs);
        tr[ls].sum1=((op==0)?0:len(ls));
        tr[ls].pre[op^1]=tr[ls].suf[op^1]=tr[ls].longsum[op^1]=0;
        tr[rs].pre[op^1]=tr[rs].suf[op^1]=tr[rs].longsum[op^1]=0;
        tr[rs].sum1=((op==0)?0:len(rs));
        tr[p].lazy=-1;
    }
    if(tr[p].rev){ 
        if(tr[ls].lazy!=-1)tr[ls].lazy^=1;
        else tr[ls].rev^=1;
        if(tr[rs].lazy!=-1)tr[rs].lazy^=1;
        else tr[rs].rev^=1;
        swap(tr[ls].pre[0],tr[ls].pre[1]);
        swap(tr[ls].suf[0],tr[ls].suf[1]);
        swap(tr[ls].longsum[0],tr[ls].longsum[1]);
        tr[ls].sum1=len(ls)-tr[ls].sum1;
        swap(tr[rs].pre[0],tr[rs].pre[1]);
        swap(tr[rs].suf[0],tr[rs].suf[1]);
        swap(tr[rs].longsum[0],tr[rs].longsum[1]);
        tr[rs].sum1=len(rs)-tr[rs].sum1;
        tr[p].rev=0;
    }
}
void update(int p,int l,int r,int L,int R,int op){ 
pushDown(p);
    if(L<=l&&r<=R){ 
        if(op==0||op==1){ 
            tr[p].rev=0;   
            tr[p].pre[op]=tr[p].suf[op]=tr[p].longsum[op]=len(p);
            tr[p].lazy=op;
            tr[p].sum1=((op==0)?0:len(p));
            tr[p].pre[op^1]=tr[p].suf[op^1]=tr[p].longsum[op^1]=0;
        }else{ 
            tr[p].rev^=1;
            if(tr[p].lazy!=-1)tr[p].lazy^=1;
            swap(tr[p].pre[0],tr[p].pre[1]);
            swap(tr[p].suf[0],tr[p].suf[1]);
            swap(tr[p].longsum[0],tr[p].longsum[1]);
            tr[p].sum1=len(p)-tr[p].sum1;
        }
        return;
    }
    int mid=l+r>>1;
    if(L>mid)update(rson,L,R,op);
    else if(R<=mid)update(lson,L,R,op);
    else update(lson,L,mid,op),update(rson,mid+1,R,op);
    pushUp(p);
}
int query(int p,int l,int r,int L,int R){ 
    pushDown(p);
    if(L<=l&&r<=R){ 
        return tr[p].sum1;
    }
    int mid=l+r>>1;
    if(R<=mid)return query(lson,L,R);
    else if(L>mid)return query(rson,L,R);
    else return query(lson,L,mid)+query(rson,mid+1,R);
}
int query1(int p,int l,int r,int L,int R){ 
    if(L<=l&&r<=R){ 
        return tr[p].longsum[1];
    }
    int mid=l+r>>1;
    if(L>mid)return query1(rson,L,R);
    else if(R<=mid)return query1(lson,L,R);
    else return max(max(query1(lson,L,mid),query1(rson,mid+1,R)),min(tr[ls].suf[1],mid-L+1)+min(tr[rs].pre[1],R-mid));
}
int main(){ 
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    build(1,1,n);
    int l,r,op;
    for(int i=1;i<=m;++i){ 
        scanf("%d%d%d",&op,&l,&r);l++;r++;
        if(op==1||op==2||op==0)
            update(1,1,n,l,r,op);
        else if(op==3)
            cout<<query(1,1,n,l,r)<<"\n";
        else cout<<query1(1,1,n,l,r)<<"\n";
    }
    return 0;
}
