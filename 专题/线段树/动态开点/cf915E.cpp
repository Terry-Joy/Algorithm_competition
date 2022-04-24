#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=3e5+5;
struct SegmentTree{
    int rt,tot,sum[maxn*45],lc[maxn*45],rc[maxn*45],lazy[maxn*45];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void pushDown(int p,int l,int r){
        if(~lazy[p]){
            int mid=l+r>>1;
            if(!ls)ls=++tot;
            if(!rs)rs=++tot;
            sum[ls]=lazy[p]*(mid-l+1);lazy[ls]=lazy[p];
            sum[rs]=lazy[p]*(r-mid);lazy[rs]=lazy[p];
            lazy[p]=-1;
        }
    }
    void update(int&p,int l,int r,int L,int R,int val){
        if(!p)p=++tot;
        if(L<=l&&r<=R){
            sum[p]=(r-l+1)*val;
            lazy[p]=val;
            return;
        }
        pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
}tr;
int n,q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    int l,r,k;
    memset(tr.lazy,-1,sizeof(tr.lazy));
    tr.update(tr.rt,1,n,1,n,1);
    for(int i=1;i<=q;++i){
        cin>>l>>r>>k;
        tr.update(tr.rt,1,n,l,r,(k==2));
        cout<<tr.sum[1]<<"\n";
    }
    return 0;
}