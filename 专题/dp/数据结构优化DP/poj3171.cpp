#include<iostream>
#include<cstdio>
#include<algorithm>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=87000;
const int INF=0x3f3f3f3f;
int tr[maxn<<2];
struct Node{
    int l,r,cost;
    bool operator<(const Node&a)const{
        return r<a.r;
    }
}a[10005];
void pushUp(int p){
    tr[p]=min(tr[ls],tr[rs]);
}
void build(int p,int l,int r){
    if(l==r){
        tr[p]=INF;return;
    }
    int mid=l+r>>1;
    build(lson);
    build(rson);
    pushUp(p);
}
void change(int p,int l,int r,int x,int val){
    if(l==r){
        tr[p]=val;return;
    }
    int mid=l+r>>1;
    if(x<=mid)change(lson,x,val);
    else change(rson,x,val);
    pushUp(p);
}
int query(int p,int l,int r,int L,int R){
    if(L<=l&&r<=R){return tr[p];}
    int mid=l+r>>1;
    int ans=INF;
    if(L<=mid)ans=min(ans,query(lson,L,R));
    if(R>mid)ans=min(ans,query(rson,L,R));
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,e;
    cin>>n>>m>>e;
    e-=m-2;
    for(int i=1;i<=n;++i){
        cin>>a[i].l>>a[i].r>>a[i].cost;
        a[i].l-=m-2;a[i].r-=m-2;
    }
    sort(a+1,a+1+n);
    m=2;
    build(1,1,e);
    change(1,1,e,1,0);
    for(int i=1;i<=n;++i){
        int tmp=query(1,1,e,a[i].l-1,a[i].r-1);
        int tmp2=query(1,1,e,a[i].r,a[i].r);
        if(tmp+a[i].cost<tmp2)
            change(1,1,e,a[i].r,tmp+a[i].cost);
    }
    int ans=query(1,1,e,e,e);
    if(ans==INF)puts("-1");
    else cout<<ans<<"\n";
    return 0;
}