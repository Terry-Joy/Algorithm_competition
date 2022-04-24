#include<bits/stdc++.h>
#define N maxn*50
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=1e5+5;
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}//是符号
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}//是数字
    return x*s;
}
inline void in(int&x){
    x=read();
}
int n,m,a,b,Q,id[maxn];
char s[2];
struct SegmentTree{
    int rt[maxn],lc[N],rc[N],num[N],tot;
    void pushUp(int p){
        num[p]=num[ls]+num[rs];
    }
    void update(int&p,int l,int r,int x,int val){
        if(!p)p=++tot;
        if(l==r){
            num[p]+=val;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int merge(int p,int q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){
            num[p]+=num[q];return p;
        }
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        pushUp(p);
        return p;
    }
    int query(int p,int l,int r,int k){
        if(!p)return 0;
        if(l==r)return l;
        int mid=l+r>>1;
        if(num[ls]>=k)return query(lson,k);
        else return query(rson,k-num[ls]);
    }
}tr;
struct DS{
    int fa[maxn],rank[maxn];
    void init(){
        for(int i=1;i<=n;++i)fa[i]=i,rank[i]=0;
    }
    int find(int x){
        if(x==fa[x])return x;
        return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx==fy)return;
        if(rank[fx]<rank[fy]){
            fa[fx]=fy;
            tr.rt[fy]=tr.merge(tr.rt[fy],tr.rt[fx],1,n);
        }else{
            fa[fy]=fx;
            tr.rt[fx]=tr.merge(tr.rt[fx],tr.rt[fy],1,n);
            if(rank[fy]==rank[fx])
                rank[fx]++;
        }
    }
}ds;
int main(){
    in(n);in(m);
    for(int i=1;i<=n;++i){
        in(a);id[a]=i;
        tr.update(tr.rt[i],1,n,a,1);
    }
    ds.init();
    for(int i=1;i<=m;++i){
        in(a);in(b);
        ds.merge(a,b);
    }
    in(Q);
    for(int i=1;i<=Q;++i){
        scanf("%s",s);
        in(a);in(b);
        if(s[0]=='Q'){
            int xx=ds.find(a);
            if(tr.num[tr.rt[xx]]<b){
                puts("-1");
            }else  
                cout<<id[tr.query(tr.rt[xx],1,n,b)]<<"\n";
        }else
            ds.merge(a,b);
        
    }
    return 0;
}
