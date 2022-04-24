#include<bits/stdc++.h>
#define N maxn*36
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=2e5+5;
int rt[maxn],a,n,m;
struct Persistable_SegmentTree{
    int tot,lc[N],rc[N],mn[N];
    void pushUp(int p){
        mn[p]=min(mn[ls],mn[rs]);
    }
    void update(int q,int&p,int l,int r,int x,int val){
        p=++tot;
        ls=lc[q];rs=rc[q];mn[p]=mn[q];
        if(l==r){
            mn[p]=val;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lc[q],lson,x,val);
        else update(rc[q],rson,x,val);
        pushUp(p);
    }
    int query(int p,int l,int r,int x){
        if(l==r)return l;
        int mid=l+r>>1;
        if(mn[lc[p]]>=x)return query(rson,x);
        else return query(lson,x);
    }
}tr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a;
        if(a>n)rt[i]=rt[i-1];
        else tr.update(rt[i-1],rt[i],0,n,a,i);
    }
    int L,R;
    for(int i=1;i<=m;++i){
        cin>>L>>R;
        cout<<tr.query(rt[R],0,n,L)<<"\n";
    }
    return 0;
}