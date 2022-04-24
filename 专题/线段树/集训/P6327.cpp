#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
using db=double;
using ll=long long;
const int maxn=2e5+10;
int a[maxn];
struct SegmentTree{ 
    db sum1[maxn<<2],sum2[maxn<<2];
    ll add[maxn<<2];
    void pushUp(int p){ 
        sum1[p]=sum1[ls]+sum1[rs];
        sum2[p]=sum2[ls]+sum2[rs];
    }
    void pushDown(int p){ 
        db tmp1=sum1[ls],tmp2=sum1[rs];
        sum1[ls]=sum1[ls]*cos((db)add[p])+sin((db)add[p])*sum2[ls];
        sum2[ls]=cos((db)add[p])*sum2[ls]-sin((db)add[p])*tmp1;
        sum1[rs]=sum1[rs]*cos((db)add[p])+sin((db)add[p])*sum2[rs];
        sum2[rs]=cos((db)add[p])*sum2[rs]-sin((db)add[p])*tmp2;
        add[ls]+=add[p];
        add[rs]+=add[p];
        add[p]=0;
    }
    void build(int p,int l,int r){ 
        if(l==r){ 
            sum1[p]=sin(a[l]);
            sum2[p]=cos(a[l]);
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void update(int p,int l,int r,int L,int R,int val){ 
        if(L<=l&&r<=R){ 
            db tmp=sum1[p];
            sum1[p]=sum1[p]*cos(1.0*val)+sin(1.0*val)*sum2[p];
            sum2[p]=cos(1.0*val)*sum2[p]-sin(1.0*val)*tmp;
            add[p]+=val;
            return;
        }
        if(add[p])pushDown(p);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
    db query(int p,int l,int r,int L,int R){ 
        if(L<=l&&r<=R){ 
            return sum1[p];
        }
        if(add[p])pushDown(p);
        int mid=l+r>>1;
        db ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
}tr;
int main(){ 
    int n,m,l,r,v,op;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    tr.build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;++i){ 
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){ 
            cin>>v;
            tr.update(1,1,n,l,r,v);
        }else{ 
            printf("%.1f\n",tr.query(1,1,n,l,r));
        }
    }
    return 0;
}
