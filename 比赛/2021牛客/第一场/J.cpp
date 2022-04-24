#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define fi first 
#define se second
using namespace std;
using ll=long long;
using P=pair<pair<ll,ll>,bool>;
const int maxn=1e6+5;
const ll INF=1e18;
int t,n,u[maxn],v[maxn],c[maxn],q,w,p;
ll pre[maxn];
bool res;
struct SegmentTree{ 
    ll mx[maxn<<2],mn[maxn<<2],add[maxn<<2];
    bool ok[maxn<<2];
    void pushUp(int p){ 
        mx[p]=max(mx[ls],mx[rs]);
        mn[p]=min(mn[ls],mn[rs]);
        ok[p]=(ok[ls]&&ok[rs]&&mx[ls]<=mn[rs]);
    }
    void build(int p,int l,int r){ 
        add[p]=ok[p]=0;
        if(l==r){ 
            mx[p]=1ll*u[l]-pre[l-1];
            mn[p]=1ll*v[l]-pre[l-1];
            ok[p]=1;
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void pushDown(int p){ 
        mx[ls]+=add[p],mn[ls]+=add[p],add[ls]+=add[p];
        mx[rs]+=add[p],mn[rs]+=add[p],add[rs]+=add[p];
        add[p]=0;
    }
    void update1(int p,int l,int r,int L,int R,int val){ 
        if(L<=l&&r<=R){ 
            mx[p]-=val;
            mn[p]-=val;
            add[p]-=val;
            return;
        }
        if(add[p])
            pushDown(p);
        int mid=l+r>>1;
        if(L<=mid)update1(lson,L,R,val);
        if(R>mid)update1(rson,L,R,val);
        pushUp(p);
    }
    void update2(int p,int l,int r,int x,int val1,int val2){ 
        if(l==r){ 
            mx[p]+=val1;mn[p]+=val2;
            return;
        }
        if(add[p])
            pushDown(p);
        int mid=l+r>>1;
        if(x<=mid)update2(lson,x,val1,val2);
        else update2(rson,x,val1,val2);
        pushUp(p);
    }
    P query(int p,int l,int r,int L,int R){ 
        if(L<=l&&r<=R){ 
            P a;
            a.fi={mx[p],mn[p]};a.se=ok[p];
            return a;
        }
        if(add[p])pushDown(p);
        int mid=l+r>>1;
        P x1,x2,ret;
        bool f1=0,f2=0;
        ret.fi={ -INF,INF},ret.se=1;
        if(L<=mid){ 
            x1=query(lson,L,R);
            ret.fi.fi=max(ret.fi.fi,x1.fi.fi);
            ret.fi.se=min(ret.fi.se,x1.fi.se);
            ret.se&=x1.se;
            f1=1;
        }
        if(R>mid){ 
            x2=query(rson,L,R);
            ret.fi.fi=max(ret.fi.fi,x2.fi.fi);
            ret.fi.se=min(ret.fi.se,x2.fi.se);
            ret.se&=x2.se;
            f2=1;
        }
        if(f1&&f2){ 
            ret.se&=(x1.fi.fi<=x2.fi.se);
        }
        return ret;
    }
}tr;
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&u[i]);
        for(int i=1;i<=n;++i)scanf("%d",&v[i]);
        for(int i=1;i<n;++i)scanf("%d",&c[i]);
        pre[1]=c[1];
        for(int i=2;i<n;++i)pre[i]=pre[i-1]+c[i];
        tr.build(1,1,n);
        int Q;
        scanf("%d",&Q);
        int op;
        for(int i=1;i<=Q;++i){ 
            scanf("%d",&op);
            int l,r;
            if(!op){ 
                scanf("%d%d",&l,&r);
                if(l==r)puts("Yes");
                else{ 
                    P x=tr.query(1,1,n,l,r);
                    puts(x.se?"Yes":"No");
                }
            }else if(op==1){
                int pos; 
                scanf("%d%d",&pos,&w);
                tr.update1(1,1,n,pos+1,n,w-c[pos]);
                c[pos]=w;
            }else if(op==2){ 
                int pos;
                scanf("%d%d%d",&pos,&p,&q);
                tr.update2(1,1,n,pos,p-u[pos],q-v[pos]);
                u[pos]=p,v[pos]=q;
            }
        }
    }
    return 0;
}
