#include<bits/stdc++.h>
#define N maxn*30
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=6005;
const int INF=0x3f3f3f3f;
int a[maxn],len,ans,cnt,head[maxn],ver[maxn<<1],next1[maxn<<1],n,val[maxn],mxlis,mxlds,m;
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}
    return x*s;
}
inline void in(int&x){
    x=read();
}
void add(int x,int y){
    ver[++cnt]=y,next1[cnt]=head[x],head[x]=cnt;
}
struct SegmentTree{
    int tot,rt[maxn],lc[N],rc[N],lis[N],lds[N];
    int query(int p,int l,int r,int L,int R,bool f){
        if(L>r||R<l)return 0;
        if(L<=l&&r<=R)return f?lis[p]:lds[p];
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans=max(ans,query(lson,L,R,f));
        if(R>mid)ans=max(ans,query(rson,L,R,f));
        return ans;
    }
    int merge(int p,int q,int l,int r){//不包含当前点lis
        if(!p||!q)return p+q;
        lis[p]=max(lis[p],lis[q]);lds[p]=max(lds[p],lds[q]);
        if(l==r)return p;
        ans=max(ans,max(lis[ls]+lds[rc[q]],lds[rs]+lis[lc[q]]));
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        return p;
    }
    void pushUp(int p,bool f){
        if(f)lis[p]=max(lis[ls],lis[rs]);
        else lds[p]=max(lds[ls],lds[rs]);
    }
    void update(int&p,int l,int r,int x,int val,bool f){
        if(!p)p=++tot;
        if(l==r){
            if(f)lis[p]=max(lis[p],val);
            else lds[p]=max(lds[p],val);
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val,f);
        else update(rson,x,val,f);
        pushUp(p,f);
    }
}tr;
void dfs(int x,int fa){
    int mxlis=0,mxlds=0;
    for(int i=head[x];i;i=next1[i]){
        int v=ver[i];
        if(v==fa)continue;
        dfs(v,x);
        int nowlis=tr.query(tr.rt[v],1,m,1,a[x]-1,1);
        int nowlds=tr.query(tr.rt[v],1,m,a[x]+1,m,0);
        ans=max(ans,max(nowlis+mxlds,nowlds+mxlis)+1);//包含当前点的lis
        mxlis=max(mxlis,nowlis);mxlds=max(mxlds,nowlds);
        tr.rt[x]=tr.merge(tr.rt[x],tr.rt[v],1,m);
    }
    tr.update(tr.rt[x],1,m,a[x],mxlis+1,1);
    tr.update(tr.rt[x],1,m,a[x],mxlds+1,0);
}
int main(){
    in(n);
    int x,y;
    for(int i=1;i<=n;++i)in(a[i]),val[i]=a[i];
    for(int i=1;i<n;++i){
        in(x);in(y);
        add(x,y);
        add(y,x);
    }
    sort(val+1,val+1+n);
    m=unique(val+1,val+1+n)-(val+1);
    for(int i=1;i<=n;++i){
        a[i]=lower_bound(val+1,val+1+m,a[i])-val;
    }
    dfs(1,0);
    cout<<ans<<"\n";
    return 0;
}