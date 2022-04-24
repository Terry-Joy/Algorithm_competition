#include<bits/stdc++.h>
#define ls p<<1 
#define rs p<<1|1 
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r
using namespace std;
const int maxn=1e5+5;
int n,w,head[maxn],ver[maxn<<1],next1[maxn<<1],tot,ti,ww[maxn];
char s[10];
struct Edge{
    int u,v,w;
}edge[maxn];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct SegmentTree{
    int mx[maxn<<2],add[maxn<<2],tag[maxn<<2];
    void pushUp(int p){
        mx[p]=max(mx[ls],mx[rs]);
    }
    void build(int p,int l,int r){
        add[p]=0;
        tag[p]=-1;
        if(l==r){mx[p]=ww[l];return;}
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void pushDown(int p){
        if(tag[p]!=-1){
            mx[ls]=mx[rs]=tag[p];
            tag[ls]=tag[rs]=tag[p];
            add[ls]=add[rs]=0;
            tag[p]=-1;
        }
        if(add[p]){
            mx[ls]+=add[p];mx[rs]+=add[p];
            add[ls]+=add[p];add[rs]+=add[p];
            add[p]=0;
        }
    }
    void update1(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            mx[p]+=val;
            add[p]+=val;return;
        }
        pushDown(p);
        int mid=l+r>>1;
        if(L<=mid)update1(lson,L,R,val);
        if(R>mid)update1(rson,L,R,val);
        pushUp(p);
    }
    void update2(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            mx[p]=val;
            add[p]=0;tag[p]=val;return;
        }
        pushDown(p);
        int mid=l+r>>1;
        if(L<=mid)update2(lson,L,R,val);
        if(R>mid)update2(rson,L,R,val);
        pushUp(p);
    }
    int query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return mx[p];
        pushDown(p);
        int ans=0;
        int mid=l+r>>1;
        if(L<=mid)ans=max(ans,query(lson,L,R));
        if(R>mid)ans=max(ans,query(rson,L,R));
        return ans;
    }
}tr;
struct HCD{
    int fa[maxn],son[maxn],dep[maxn],top[maxn],in[maxn],sz[maxn];
    void dfs1(int x,int f){
        fa[x]=f;
        sz[x]=1;
        dep[x]=dep[f]+1;
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
        dfs1(x,0);dfs2(x,x);
    }
    void update1(int x,int y,int val){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            tr.update1(1,1,ti,in[top[x]],in[x],val);
            x=fa[top[x]];
        }
        if(x==y)return;
        if(dep[x]<dep[y])swap(x,y);
        tr.update1(1,1,ti,in[y]+1,in[x],val);
    }
    void update2(int x,int y,int val){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            tr.update2(1,1,ti,in[top[x]],in[x],val);
            x=fa[top[x]];
        }
        if(x==y)return;
        if(dep[x]<dep[y])swap(x,y);
        tr.update2(1,1,ti,in[y]+1,in[x],val);
    }
    int query(int x,int y){
        int ans=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            ans=max(ans,tr.query(1,1,ti,in[top[x]],in[x]));
            x=fa[top[x]];
        }
        if(x==y)return ans;
        if(dep[x]<dep[y])swap(x,y);
        ans=max(ans,tr.query(1,1,ti,in[y]+1,in[x]));
        return ans;
    }
}hcd;
int main(){
    scanf("%d",&n);
    int u,v,w;
    for(int i=1;i<n;++i){
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        add(edge[i].u,edge[i].v);
        add(edge[i].v,edge[i].u);
    }
    hcd.init(1);
    for(int i=1;i<n;++i){
        int u=edge[i].u,v=edge[i].v;
        if(hcd.fa[u]==v)ww[hcd.in[u]]=edge[i].w;
        else ww[hcd.in[v]]=edge[i].w;
    }
    tr.build(1,1,ti);
    while(~scanf("%s",s)&&s[0]!='S'){
        if(s[0]=='M'){
            scanf("%d%d",&u,&v);
            cout<<hcd.query(u,v)<<'\n';
        }else if(s[1]=='o'){
            scanf("%d%d%d",&u,&v,&w);
            hcd.update2(u,v,w);
        }else if(s[1]=='h'){
            scanf("%d%d",&u,&w);
            int a=edge[u].u,b=edge[u].v;
            hcd.update2(a,b,w);
        }else if(s[0]=='A'){
            scanf("%d%d%d",&u,&v,&w);
            hcd.update1(u,v,w);
        }
    }
    return 0;
}