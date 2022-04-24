#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
int n,q;
const int maxn=1e6+5;
const int INF=1e9;
struct Line{ 
    int ymn,ymx,id,x1,x2;
    bool operator<(const Line&a)const{ 
        if(ymn==a.ymn)return id<a.id;//等y的要先加入圆
        return ymn<a.ymn;
    }
}line[maxn<<1];
int cnt=0,px,py,qx,qy,ymn,ymx,X[maxn],cntx=0,m;
struct SegmentTree{ 
    int mx[maxn<<2];
    void pushUp(int p){ 
        mx[p]=max(mx[ls],mx[rs]);
    }
    void update(int p,int l,int r,int x,int val){ 
        if(l==r){ 
            mx[p]=max(mx[p],val);
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int query(int p,int l,int r,int L,int R){ 
        if(L<=l&&r<=R)return mx[p];
        int mid=l+r>>1;
        int ans1=-INF-1,ans2=-INF-1;
        if(L<=mid)ans1=query(lson,L,R);
        if(R>mid)ans2=query(rson,L,R);
        return max(ans1,ans2);
    }
}tr;
bool ans[maxn];
int ask(int x){ 
    return lower_bound(X+1,X+1+m,x)-X;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    int x,y,r;
    for(int i=1;i<=n;++i){ 
        cin>>x>>y>>r;
        line[++cnt]={y-r,y+r,0,x,0};
        X[++cntx]=x;
    }
    for(int i=1;i<=q;++i){ 
        cin>>px>>py>>qx>>qy>>ymn>>ymx;
        line[++cnt]={ymn,ymx,i,px,qx};
    }
    sort(line+1,line+1+cnt);
    sort(X+1,X+1+cntx);
    m=unique(X+1,X+1+cntx)-(X+1);
    for(int i=1;i<=4*m;++i)tr.mx[i]=-INF-1;
    for(int i=1;i<=cnt;++i){ 
        if(!line[i].id)tr.update(1,1,m,ask(line[i].x1),line[i].ymx);
        else{ 
            int l1=ask(min(line[i].x2,line[i].x1)),r1=upper_bound(X+1,X+1+m,max(line[i].x1,line[i].x2))-X-1;
            int num;
            if(r1<l1)num=-INF-5;
            else num=tr.query(1,1,m,l1,r1);
            ans[line[i].id]=(num>=line[i].ymx)?1:0;
        }
    }
    for(int i=1;i<=q;++i){ 
        puts(ans[i]?"NO":"YES");
    }
}
