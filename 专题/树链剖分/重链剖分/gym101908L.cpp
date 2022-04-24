#include<bits/stdc++.h>
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r  
#define ls p<<1 
#define rs p<<1|1
#define pb push_back
using namespace std;
const int maxn=1e5+5;
int ti,n,q,a,b,c,d;
vector<int>G[maxn];
struct SegmentTree{
    int add[maxn<<2],sum[maxn<<2];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void pushDown(int p,int l,int r){
        int mid=l+r>>1;
        sum[ls]+=(mid-l+1)*add[p];sum[rs]+=(r-mid)*add[p];
        add[ls]+=add[p];add[rs]+=add[p];
        add[p]=0;
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            sum[p]+=(r-l+1)*val;
            add[p]+=val;   return;
        }
        if(add[p])pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
    int query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        if(add[p])pushDown(p,l,r);
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
}tr;
struct HCD{
    int fa[maxn],son[maxn],dep[maxn],sz[maxn],top[maxn],in[maxn];
    void dfs1(int x,int f){
        fa[x]=f;sz[x]=1;
        dep[x]=dep[f]+1;
        int mxson=-1;
        for(auto&v:G[x]){
            if(v==f)continue;
            dfs1(v,x);
            sz[x]+=sz[v];
            if(sz[v]>mxson)mxson=sz[v],son[x]=v;
        }
    }
    void dfs2(int x,int t){
        in[x]=++ti;
        top[x]=t;
        if(!son[x])return;
        dfs2(son[x],t);
        for(auto&v:G[x]){
            if(v==fa[x]||v==son[x])continue;
            dfs2(v,v);
        }   
    }
    void init(int x){
        dfs1(x,0);dfs2(x,x);
    }
    int query(int x,int y){
        int ans=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            ans+=tr.query(1,1,ti,in[top[x]],in[x]);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        ans+=tr.query(1,1,ti,in[y],in[x]);
        return ans;
    }
    void update(int x,int y,int val){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            tr.update(1,1,ti,in[top[x]],in[x],val);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        tr.update(1,1,ti,in[y],in[x],val);
    }
}hcd;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        G[a].pb(b);G[b].pb(a);
    }
    hcd.init(1);
    for(int i=1;i<=q;++i){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        hcd.update(a,b,1);
        cout<<hcd.query(c,d)<<"\n";
        hcd.update(a,b,-1);
    }
    return 0;
}