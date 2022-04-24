#include<bits/stdc++.h>
#define ls p<<1 
#define rs p<<1|1
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r
using namespace std;
const int maxn=1e5+5;
int ti,head[maxn],ver[maxn<<1],next1[maxn<<1],tot,op,u,v,w,a[maxn],nval[maxn],m,n;
char s[2];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct SegmentTree{
    int sum[maxn<<2],lc[maxn<<2],rc[maxn<<2],lazy[maxn<<2];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
        if(rc[ls]==lc[rs])sum[p]--;
        lc[p]=lc[ls];rc[p]=rc[rs];
    }
    void build(int p,int l,int r){
        if(l==r){
            sum[p]=1;lc[p]=rc[p]=nval[l];return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void pushDown(int p){
        sum[ls]=sum[rs]=1;
        lc[ls]=lc[rs]=rc[rs]=rc[ls]=rc[p];//整个区间都一样
        lazy[ls]=lazy[rs]=lazy[p];
        lazy[p]=0;
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            sum[p]=1;lc[p]=rc[p]=val;
            lazy[p]=val;return;
        }
        if(lazy[p])pushDown(p);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
    int query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        if(lazy[p])pushDown(p);
        int mid=l+r>>1;
        int ans=0;
        if(R<=mid)ans+=query(lson,L,R);
        else if(L>mid)ans+=query(rson,L,R);
        else{
            ans+=query(lson,L,R)+query(rson,L,R);
            if(rc[ls]==lc[rs])ans--;
        }
        return ans;
    }
    int query2(int p,int l,int r,int x){
        if(l==r)return rc[p];
        if(lazy[p])pushDown(p);
        int mid=l+r>>1;
        if(x<=mid)return query2(lson,x);
        else return query2(rson,x);
    }
}tr;
struct HCD{
    int fa[maxn],son[maxn],top[maxn],sz[maxn],in[maxn],dep[maxn];
    void dfs1(int x,int f){
        fa[x]=f;
        dep[x]=dep[f]+1;
        sz[x]=1;
        int mxson=-1;
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==f)continue;
            dfs1(y,x);
            sz[x]+=sz[y];
            if(mxson<sz[y])mxson=sz[y],son[x]=y;
        }
    }
    void dfs2(int x,int t){
        in[x]=++ti;
        nval[ti]=a[x];
        top[x]=t;
        if(!son[x])return;
        dfs2(son[x],t);
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==fa[x]||y==son[x])continue;
            dfs2(y,y);
        }
    }
    void init(int x){
        dfs1(x,0);dfs2(x,x);
    }
    void Pupdate(int x,int y,int val){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            tr.update(1,1,ti,in[top[x]],in[x],val);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        tr.update(1,1,ti,in[y],in[x],val);
    }
    int query(int x,int y){
        int p1=0,p2=0,ans=0,lc=0,rc=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y),swap(p1,p2);
            rc=tr.query2(1,1,ti,in[x]);
            ans+=tr.query(1,1,ti,in[top[x]],in[x]);
            if(rc==p1)ans--;
            p1=tr.query2(1,1,ti,in[top[x]]);
            x=fa[top[x]];
        } 
        if(dep[x]<dep[y])swap(x,y),swap(p1,p2);
        rc=tr.query2(1,1,ti,in[x]);
        lc=tr.query2(1,1,ti,in[y]);
        ans+=tr.query(1,1,ti,in[y],in[x]);
        if(rc==p1)ans--;//两端最后都得判一下
        if(lc==p2)ans--;
        return ans;
    }
}hcd;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<n;++i){
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    hcd.init(1);
    tr.build(1,1,ti);
    for(int i=1;i<=m;++i){
        cin>>s;
        if(s[0]=='C'){
            cin>>u>>v>>w;
            hcd.Pupdate(u,v,w);
        }else{
            cin>>u>>v;
            cout<<hcd.query(u,v)<<"\n";
        }
    }
    return 0;
}