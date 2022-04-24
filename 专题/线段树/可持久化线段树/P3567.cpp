#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r 
#define N maxn*36
using namespace std;
const int maxn=5e5+5;
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
    int tot,lc[N],rc[N],rt[maxn],sum[N];
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
    int query(int q,int p,int l,int r,int num){
        if(l==r)return l;
        int dir1=sum[ls]-sum[lc[q]],dir2=sum[rs]-sum[rc[q]];
        int mid=l+r>>1;
        if(dir1>num)return query(lc[q],lson,num);
        else if(dir2>num)return query(rc[q],rson,num);
        else return 0;
    }
}tr;
int n,m,a[maxn],L,R;
int main(){
    in(n);in(m);
    for(int i=1;i<=n;++i)in(a[i]);
    for(int i=1;i<=n;++i)tr.update(tr.rt[i-1],tr.rt[i],1,n,a[i]);
    for(int i=1;i<=m;++i){
        in(L);in(R);
        int val=(tr.sum[tr.rt[R]]-tr.sum[tr.rt[L-1]])/2;
        cout<<tr.query(tr.rt[L-1],tr.rt[R],1,n,val)<<"\n";
    }
    return 0;
}