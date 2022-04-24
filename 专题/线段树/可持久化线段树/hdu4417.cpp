#include<bits/stdc++.h>
#define N maxn*26
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define ls lc[p]
#define rs rc[p]
using namespace std;
const int maxn=1e5+5;
int n,m,a[maxn],t,b[maxn],T,cnt,rt[maxn],L,R,H;
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}//是符号
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}//是数字
    return x*s;
}
inline void in(int&x){
    x=read();
}
struct Persistable_SegmentTree{
    int tot,lc[N],rc[N],sum[N];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void update(int q,int&p,int l,int r,int x){
        p=++tot;
        ls=lc[q],rs=rc[q],sum[p]=sum[q];
        if(l==r){
            sum[p]++;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lc[q],lson,x);
        else update(rc[q],rson,x);
        pushUp(p);
    }
    int query(int q,int p,int l,int r,int L,int R){
        if(R<l||L>r)return 0;
        if(L<=l&&r<=R){
            return sum[p]-sum[q];
        }
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lc[q],lson,L,R);
        if(R>mid)ans+=query(rc[q],rson,L,R);
        return ans;
    }
}tr;
int main(){
    in(t);
    while(t--){
        in(n);in(m);
        for(int i=1;i<=n;++i)in(a[i]),b[i]=a[i];
        sort(b+1,b+1+n);
        cnt=unique(b+1,b+1+n)-(b+1);
        for(int i=1;i<=n;++i){
            a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
        }
        cout<<"Case "<<++T<<":\n";
        for(int i=1;i<=n;++i)tr.update(rt[i-1],rt[i],1,n,a[i]);
        for(int i=1;i<=m;++i){
            in(L);in(R);in(H);
            H=upper_bound(b+1,b+1+cnt,H)-b;
            cout<<tr.query(rt[L],rt[R+1],1,n,1,H-1)<<"\n";
        }    
    }
}
