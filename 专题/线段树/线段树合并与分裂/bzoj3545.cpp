#include<bits/stdc++.h>
#define N maxn*35
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=1e5+5;
const int maxm=5e5+5;
int n,m,q,h[maxn],cnt,id[maxn],a,b,c,ans[maxm],val[maxn];
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}
    return x*s;
}
inline void in(int&x){
    x=read();
}
struct Edge{
    int u,v,c;
    bool operator<(const Edge&a){
        return c<a.c;
    }
}edge[maxm];
struct Q{
    int v,x,k,id;
    bool operator<(const Q&a){
        return x<a.x;
    }
}qs[maxm];
struct SegmentTree{
    int rt[maxn],lc[N],rc[N],tot,num[N];
    void pushUp(int p){
        num[p]=num[ls]+num[rs];
    }
    void update(int&p,int l,int r,int x){
        if(!p)p=++tot;
        if(l==r){
            num[p]++;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x);
        else update(rson,x);
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
        if(l==r)return l;
        int mid=l+r>>1;
        if(num[rs]>=k)return query(rson,k);
        else return query(lson,k-num[rs]);
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
            tr.rt[fy]=tr.merge(tr.rt[fy],tr.rt[fx],1,cnt); 
        }else{
            fa[fy]=fx;
            tr.rt[fx]=tr.merge(tr.rt[fx],tr.rt[fy],1,cnt);
            if(rank[fx]==rank[fy])
                rank[fx]++;
        }
    }
}ds;
int main(){
    in(n);in(m);in(q);
    for(int i=1;i<=n;++i)in(h[i]),val[i]=h[i];
    sort(val+1,val+1+n);
    cnt=unique(val+1,val+1+n)-(val+1);
    ds.init();
    for(int i=1;i<=n;++i){
        h[i]=lower_bound(val+1,val+1+cnt,h[i])-val;
        tr.update(tr.rt[i],1,cnt,h[i]);
    }
    for(int i=1;i<=m;++i){
        in(a);in(b);in(c);
        edge[i]={a,b,c};
    }
    sort(edge+1,edge+1+m);
    for(int i=1;i<=q;++i){
        in(a);in(b);in(c);
        qs[i]={a,b,c,i};
    }
    sort(qs+1,qs+1+q);
    int now=1;
    for(int i=1;i<=q;++i){
        while(edge[now].c<=qs[i].x&&now<=m){
            if(edge[now].u==edge[now].v)continue;
            ds.merge(edge[now].u,edge[now].v);
            now++;
        }
        int id=ds.find(qs[i].v);
        if(tr.num[tr.rt[id]]<qs[i].k)ans[qs[i].id]=-1;
        else ans[qs[i].id]=val[tr.query(tr.rt[id],1,cnt,qs[i].k)];
    }
    for(int i=1;i<=q;++i)
        cout<<ans[i]<<"\n";
    return 0;
}