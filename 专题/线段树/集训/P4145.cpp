#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
using ll=long long;
const int maxn=1e5+5;
int n,m;
ll a[maxn];
struct SegmentTree{ 
    ll mx[maxn<<2],sum[maxn<<2];
    void pushUp(int p){ 
        mx[p]=max(mx[ls],mx[rs]);
        sum[p]=sum[ls]+sum[rs];
    }
    void build(int p,int l,int r){ 
        if(l==r){ 
            mx[p]=sum[p]=a[l];
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void update(int p,int l,int r,int L,int R){ 
        if(mx[p]<=1)return;
        if(l==r){ 
            sum[p]=sqrt(sum[p]);
            mx[p]=sqrt(mx[p]);
            return;
        }
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R);
        if(R>mid)update(rson,L,R);
        pushUp(p);
    }
    ll query(int p,int l,int r,int L,int R){ 
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
}tr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    tr.build(1,1,n);
    cin>>m;
    int op,l,r;
    for(int i=1;i<=m;++i){ 
        cin>>op>>l>>r;
        if(l>r)swap(l,r);
        if(!op){ 
            tr.update(1,1,n,l,r);
        }else{ 
            cout<<tr.query(1,1,n,l,r)<<"\n";
        }
    }
    return 0;
}

