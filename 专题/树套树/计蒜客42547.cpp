#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define lson lc[p],l,mid 
#define rson rc[p],mid+1,r
#define N maxn*150
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int n,q,a[maxn],rt[maxn],lp[23],rp[23],numL,numR,ld[23],rd[23];
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}//是符号
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}//是数字
    return x*s;
}
inline void in(int&x){
    x=read();
}
struct BitAndSegmentTree{
    int tot,lc[N],rc[N];
    ll sum[N];
    void update(int&p,int l,int r,int x,int val){
        if(!p)p=++tot;
        sum[p]+=val;
        if(l==r)return;
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
    }
    void add(int x,int pos,int val){
        for(int i=x;i<=n;i+=lowbit(i))
            update(rt[i],1,n,pos,val);
    }
    ll query(int l,int r,int L,int R){
        ll ans=0;
        if(L<=l&&r<=R){
            for(int i=1;i<=numL;++i)ans-=sum[lp[i]];
            for(int i=1;i<=numR;++i)ans+=sum[rp[i]];
            return ans;
        }
        int mid=l+r>>1;
        for(int i=1;i<=numL;++i)ld[i]=lp[i];
        for(int i=1;i<=numR;++i)rd[i]=rp[i];
        if(L<=mid){
            for(int i=1;i<=numL;++i)lp[i]=lc[lp[i]];
            for(int i=1;i<=numR;++i)rp[i]=lc[rp[i]];
            ans+=query(l,mid,L,R);  
            for(int i=1;i<=numL;++i)lp[i]=ld[i];
            for(int i=1;i<=numR;++i)rp[i]=rd[i];
        }
        if(R>mid){
            for(int i=1;i<=numL;++i)lp[i]=rc[lp[i]];
            for(int i=1;i<=numR;++i)rp[i]=rc[rp[i]];
            ans+=query(mid+1,r,L,R);  
            for(int i=1;i<=numL;++i)lp[i]=ld[i];
            for(int i=1;i<=numR;++i)rp[i]=rd[i];
        }
        return ans;
    }
    ll prequery(int l,int r,int L,int R){
        numL=numR=0;
        for(int i=l-1;i;i-=lowbit(i))lp[++numL]=rt[i];
        for(int i=r;i;i-=lowbit(i))rp[++numR]=rt[i];
        return query(1,n,L,R);
    }
}tr;
int main(){
    in(n);in(q);
    int x,y,op;
    for(int i=1;i<=n;++i)in(a[i]),tr.add(i,a[i],a[i]);
    for(int i=1;i<=q;++i){
        in(op);in(x);in(y);
        if(op==1){
            tr.add(x,a[x],-a[x]);
            a[x]=y;
            tr.add(x,y,y);
        }else{
            ll sum=tr.prequery(x,y,1,1);
            if(!sum){
                puts("1");continue;
            }
            ll pre=sum;
            while(1){
                sum=tr.prequery(x,y,1,min(pre+1,1ll*n));
                if(sum==pre)break;
                pre=sum;
            }
            cout<<pre+1<<"\n";
        }
    }
    return 0;
}