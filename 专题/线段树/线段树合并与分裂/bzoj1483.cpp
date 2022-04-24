#include<bits/stdc++.h>
#define N maxn*36
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=1e5+5;
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}
    return x*s;
}
inline void in(int&x){
    x=read();
}
int n,a,m,ans,x,y;
struct SegmentTree{
    int rt[maxn*10],lc[N],rc[N],tot,sum[N],lps[N],rps[N];
    void pushUp(int p){
        lps[p]=lps[ls]?lps[ls]:lps[rs];//动态开点防一手0
        rps[p]=rps[rs]?rps[rs]:rps[ls];//动态开点防一手0
        sum[p]=sum[ls]+sum[rs];
        if(rps[ls]+1==lps[rs])sum[p]--;
    }
    void update(int &p,int l,int r,int x){
        if(!p)p=++tot;
        if(l==r){
            lps[p]=rps[p]=l;sum[p]=1;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x);
        else update(rson,x);
        pushUp(p);
    }
    int merge(int p,int q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){
            lps[p]=rps[p]=l;sum[p]=l;return p;
        }
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        pushUp(p);
        return p;
    }
}tr;
int main(){
    in(n);in(m);
    for(int i=1;i<=n;++i){
        in(a);
        ans-=tr.sum[tr.rt[a]];
        tr.update(tr.rt[a],1,n,i);
        ans+=tr.sum[tr.rt[a]];
    }
    for(int i=1;i<=m;++i){
        in(a);
        if(a==2)cout<<ans<<"\n";
        else{
            in(x);in(y);
            if(x==y)continue;
            ans-=(tr.sum[tr.rt[x]]+tr.sum[tr.rt[y]]);
            tr.rt[y]=tr.merge(tr.rt[y],tr.rt[x],1,n);
            tr.rt[x]=0;//删根
            ans+=tr.sum[tr.rt[y]];
        }
    }
    return 0;
}