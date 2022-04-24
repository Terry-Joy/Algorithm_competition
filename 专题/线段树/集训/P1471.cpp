#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=1e5+10;
using ll=long long;
using db=double;
db a[maxn];
db pow2(db x){     
    return x*x;
}
struct SegmentTree{
	db sum[maxn<<2],sum2[maxn<<2],add[maxn<<2];
    void pushUp(int p){ 
        sum[p]=sum[ls]+sum[rs];
        sum2[p]=sum2[ls]+sum2[rs];
    }
    void pushDown(int p,int l,int r){
        int mid=l+r>>1; 
        sum2[ls]=sum2[ls]+2*add[p]*sum[ls]+pow2(add[p])*(mid-l+1);
        sum[ls]+=add[p]*(mid-l+1);
        sum2[rs]=sum2[rs]+2*add[p]*sum[rs]+pow2(add[p])*(r-mid);
        sum[rs]+=add[p]*(r-mid);
        add[ls]+=add[p];
        add[rs]+=add[p];
        add[p]=0;
    }
    void build(int p,int l,int r){ 
        if(l==r){ 
            sum[p]=a[l];sum2[p]=pow2(a[l]);
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void update(int p,int l,int r,int L,int R,db val){ 
        if(L<=l&&r<=R){ 
            sum2[p]=sum2[p]+2*val*sum[p]+pow2(val)*(r-l+1);
            sum[p]+=val*(r-l+1);
            add[p]+=val;
            return;
        }
        if(add[p])pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
    db query(int p,int l,int r,int L,int R,bool f){ 
        if(L<=l&&r<=R){ 
            return f?sum[p]:sum2[p];
        }
        if(add[p])pushDown(p,l,r);
        int mid=l+r>>1;
        db ans=0;
        if(L<=mid)ans+=query(lson,L,R,f);
        if(R>mid)ans+=query(rson,L,R,f);
        return ans;
    }
}tr;
int main(){
    int n,m,op,x,y;
    db k;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%lf",&a[i]);
    tr.build(1,1,n);
    for(int i=1;i<=m;++i){ 
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){ 
            cin>>k;
            tr.update(1,1,n,x,y,k);        
        }else if(op==2){ 
            printf("%.4f\n",tr.query(1,1,n,x,y,1)/(y-x+1));
        }else if(op==3){ 
            db x1=-pow2(tr.query(1,1,n,x,y,1)/(y-x+1));
            db x2=tr.query(1,1,n,x,y,0)/(y-x+1);
            printf("%.4f\n",x1+x2);
        }
    }
	return 0;
}
