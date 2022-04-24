#include<bits/stdc++.h>
#define ls p<<1 
#define rs p<<1|1 
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r
using namespace std;
const int maxn=3e4+5;
const int INF=1e9;
int ti,dfn[maxn],n,u,v,a[maxn],q,head[maxn],ver[maxn<<1],next1[maxn<<1],tot;
char s[10];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct SegmentTree{
    int mx[maxn<<2],sum[maxn<<2];
    void pushUp(int p){
        mx[p]=max(mx[ls],mx[rs]);
        sum[p]=sum[ls]+sum[rs];
    }
    void update(int p,int l,int r,int x,int val){
        if(l==r){
            mx[p]=sum[p]=val;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int query1(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return mx[p];
        int mid=l+r>>1;
        int ans=-INF;
        if(L<=mid)ans=max(ans,query1(lson,L,R));
        if(R>mid)ans=max(ans,query1(rson,L,R));
        return ans;
    }
    int query2(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query2(lson,L,R);
        if(R>mid)ans+=query2(rson,L,R);
        return ans;
    }
    void build(int p,int l,int r){
        if(l==r){
            sum[p]=mx[p]=a[dfn[l]];return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
}tr;
struct HCD{
    int fa[maxn],son[maxn],top[maxn],dep[maxn],sz[maxn],in[maxn];
    void dfs1(int x,int f){
        dep[x]=dep[f]+1;
        fa[x]=f;
        sz[x]=1;
        int mxson=-1;
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==f)continue;
            dfs1(y,x);
            sz[x]+=sz[y];
            if(sz[y]>mxson)mxson=sz[y],son[x]=y;
        }
    }
    void dfs2(int x,int t){
        in[x]=++ti;
        dfn[ti]=x;
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
    void update(int x,int val){
        tr.update(1,1,ti,in[x],val);
    }
    int PqueryMX(int x,int y){
        int ans=-INF;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            ans=max(ans,tr.query1(1,1,ti,in[top[x]],in[x]));
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        ans=max(ans,tr.query1(1,1,ti,in[y],in[x]));
        return ans;
    }
    int PqueryS(int x,int y){
        int ans=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            ans+=tr.query2(1,1,ti,in[top[x]],in[x]);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        ans+=tr.query2(1,1,ti,in[y],in[x]);
        return ans;
    }
}hcd;
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    hcd.init(1);
    tr.build(1,1,ti);
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        scanf("%s%d%d",s,&u,&v);
        if(s[0]=='C'){
            hcd.update(u,v);
        }else if(s[1]=='M'){
            cout<<hcd.PqueryMX(u,v)<<"\n";
        }else if(s[1]=='S'){
            cout<<hcd.PqueryS(u,v)<<"\n";
        }
    }
    return 0;
}