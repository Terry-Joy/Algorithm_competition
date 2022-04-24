#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
using ll=long long;
const int maxn=1e5+5;
int n,m,a[maxn];
struct SegmentTree{ 
    int mx[maxn<<2];
    ll sum[maxn<<2];
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
    void update(int p,int l,int r,int L,int R,int mod){ 
        if(mx[p]<mod)return;
        if(l==r){ 
            sum[p]%=mod;
            mx[p]%=mod;
            return;
        }
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,mod);
        if(R>mid)update(rson,L,R,mod);
        pushUp(p);
    }
    void update2(int p,int l,int r,int x,int val){ 
        if(l==r){ 
            sum[p]=mx[p]=val;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)update2(lson,x,val);
        else update2(rson,x,val);
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
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    tr.build(1,1,n);
    for(int i=1;i<=m;++i){ 
        int l,r,x,k,op;
        cin>>op;
        if(op==1){ 
            cin>>l>>r;
            cout<<tr.query(1,1,n,l,r)<<"\n";
        }else if(op==2){ 
            cin>>l>>r>>x;
            tr.update(1,1,n,l,r,x);
        }else if(op==3){ 
            cin>>k>>x;
            tr.update2(1,1,n,k,x);
        }
    }
    return 0;
}
