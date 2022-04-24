#include<bits/stdc++.h>
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r 
#define ls p<<1 
#define rs p<<1|1
using namespace std;
const int maxn=1e5+5;
int ti,head[maxn],ver[maxn<<1],tot,next1[maxn<<1],n,q;
char s[12];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct SegmentTree{
    int sum[maxn<<2],add[maxn<<2];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void pushDown(int p,int l,int r){
        int mid=l+r>>1;
        sum[ls]=add[p]*(mid-l+1);
        sum[rs]=add[p]*(r-mid);
        add[ls]=add[rs]=add[p];
        add[p]=-1;
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            sum[p]=(r-l+1)*val;
            add[p]=val;return;
        }
        if(add[p]!=-1)pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
    void build(int p,int l,int r){
        add[p]=-1;
        sum[p]=0;
        if(l==r)return;
        int mid=l+r>>1;
        build(lson);
        build(rson);
    }
    int query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        if(add[p]!=-1)pushDown(p,l,r);
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
}tr;
struct HCD{
    int fa[maxn],son[maxn],dep[maxn],top[maxn],sz[maxn],in[maxn];
    void dfs1(int x,int f){
        dep[x]=dep[f]+1;
        sz[x]=1;fa[x]=f;
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
        top[x]=t;
        in[x]=++ti;
        if(!son[x])return;
        dfs2(son[x],t);
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==fa[x]||y==son[x])continue;
            dfs2(y,y);
        }
    }
    void init(int x){
        dfs1(x,-1);dfs2(x,x);
    }
    int Pquery(int x,int y){
        int ans=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            ans+=(in[x]-in[top[x]]+1)-tr.query(1,1,ti,in[top[x]],in[x]);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        ans+=(in[x]-in[y]+1)-tr.query(1,1,ti,in[y],in[x]);
        return ans;
    }
    int Sonquery(int x){
        return tr.query(1,1,ti,in[x],in[x]+sz[x]-1);
    }
    void Pupdate(int x,int y){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            tr.update(1,1,ti,in[top[x]],in[x],1);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        tr.update(1,1,ti,in[y],in[x],1);
    }
    void Supdate(int x){
        tr.update(1,1,ti,in[x],in[x]+sz[x]-1,0);
    }
}hcd;
int main(){
    scanf("%d",&n);
    int u;
    for(int i=1;i<=n-1;++i){
        scanf("%d",&u);
        add(i,u);
        add(u,i);
    }
    hcd.init(0);
    tr.build(1,1,ti);
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        scanf("%s%d",s,&u);
        if(s[0]=='i'){
            cout<<hcd.Pquery(0,u)<<'\n';
            hcd.Pupdate(0,u);
        }else{
            cout<<hcd.Sonquery(u)<<"\n";
            hcd.Supdate(u);
        }
    }
    return 0;
}