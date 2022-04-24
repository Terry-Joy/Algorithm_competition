#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=5e5+5;
const int INF=0x3f3f3f3f;
int n,m,op,a[maxn];
struct SegmentTree{ 
    struct Node{ 
        int mx,sum,pre,suf;   
    };
    int mx[maxn<<2],sum[maxn<<2],pre[maxn<<2],suf[maxn<<2];
    void pushUp(int p){ 
        mx[p]=max(max(mx[ls],mx[rs]),suf[ls]+pre[rs]);
        sum[p]=sum[ls]+sum[rs];
        pre[p]=max(pre[ls],sum[ls]+pre[rs]);
        suf[p]=max(suf[rs],sum[rs]+suf[ls]);
    }
    void build(int p,int l,int r){ 
        if(l==r){ 
            mx[p]=sum[p]=pre[p]=suf[p]=a[l];
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void update(int p,int l,int r,int x,int val){ 
        if(l==r){ 
            mx[p]=sum[p]=pre[p]=suf[p]=val;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    Node query(int p,int l,int r,int L,int R){ 
        if(L<=l&&r<=R)return {mx[p],sum[p],pre[p],suf[p]};
        int mid=l+r>>1;
        Node x1,x2,x;
        x1={-INF,0,-INF,-INF};x2={-INF,0,-INF,-INF};
        if(L<=mid)x1=query(lson,L,R);
        if(R>mid)x2=query(rson,L,R);
        x.sum=x1.sum+x2.sum;
        x.mx=max(max(x1.mx,x2.mx),x1.suf+x2.pre);
        x.pre=max(x1.pre,x1.sum+x2.pre);
        x.suf=max(x2.suf,x2.sum+x1.suf);
        return x;
    }
}tr;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    tr.build(1,1,n);
    for(int i=1;i<=m;++i){ 
        cin>>op;
        if(op==1){ 
            int l,r;
            cin>>l>>r;
            if(l>r)swap(l,r);
            auto it=tr.query(1,1,n,l,r);
            cout<<it.mx<<"\n";
        }else{ 
            int p,s;
            cin>>p>>s;
            tr.update(1,1,n,p,s);
        }
    }
}
