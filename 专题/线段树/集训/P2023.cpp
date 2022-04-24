#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
using ll=long long;
const int maxn=1e5+5;
int a[maxn],mod,n,m;
struct SegmentTree{ 
    inline int Add(int x,int y){ 
        x+=y;
        if(x>=mod)x-=mod;
        return x;
    }
    inline int MUL(int x,int y){ 
        return (ll)x*y%mod;
    }
    int mul[maxn<<2],add[maxn<<2],sum[maxn<<2];
    void pushUp(int p){ 
        sum[p]=Add(sum[ls],sum[rs]);
    }
    void build(int p,int l,int r){ 
        add[p]=0;
        mul[p]=1;
        if(l==r){ 
            sum[p]=a[l];return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void pushDown(int p,int l,int r){ //先乘再加 乘对加有影响
        int mid=l+r>>1;
        sum[ls]=Add(MUL(sum[ls],mul[p]),MUL(mid-l+1,add[p]));
        sum[rs]=Add(MUL(sum[rs],mul[p]),MUL(r-mid,add[p]));
        mul[ls]=MUL(mul[ls],mul[p]);
        mul[rs]=MUL(mul[rs],mul[p]);
        add[ls]=Add(MUL(add[ls],mul[p]),add[p]);
        add[rs]=Add(MUL(add[rs],mul[p]),add[p]);
        add[p]=0;mul[p]=1;
    }
    void update1(int p,int l,int r,int L,int R,int val){ 
        if(L<=l&&r<=R){ 
            sum[p]=MUL(sum[p],val);
            mul[p]=MUL(mul[p],val);
            add[p]=MUL(add[p],val);
            return;
        }
        if(add[p]||mul[p]!=1)
            pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update1(lson,L,R,val);
        if(R>mid)update1(rson,L,R,val);
        pushUp(p);
    }
    void update2(int p,int l,int r,int L,int R,int val){ 
        if(L<=l&&r<=R){ 
            sum[p]=Add(sum[p],MUL(r-l+1,val));
            add[p]=Add(add[p],val);
            return;
        }
        if(add[p]||mul[p]!=1)
            pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update2(lson,L,R,val);
        if(R>mid)update2(rson,L,R,val);
        pushUp(p);
    }
    int query(int p,int l,int r,int L,int R){ 
        if(L<=l&&r<=R)return sum[p];
        pushDown(p,l,r);
        int mid=l+r>>1,ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans%mod;
    }
}tr;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>mod;
    for(int i=1;i<=n;++i)cin>>a[i];
    tr.build(1,1,n);
    cin>>m;
    int t,g,c,op;
    for(int i=1;i<=m;++i){ 
        cin>>op>>t>>g;
        if(op==1){ 
            cin>>c;
            tr.update1(1,1,n,t,g,c);
        }else if(op==2){ 
            cin>>c;
            tr.update2(1,1,n,t,g,c);
        }else{ 
            cout<<tr.query(1,1,n,t,g)<<"\n";
        }
    }
    return 0;
}
