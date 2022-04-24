#include<bits/stdc++.h>
#define lson lc[p],l,mid 
#define rson rc[p],mid+1,r 
#define ls lc[p]
#define rs rc[p]
#define N maxn*180
using namespace std;
const int INF=2e9;
const int maxn=1e5+5;
int n,sz[maxn],mxson[maxn],rt,S,head[maxn],ver[maxn<<1],next1[maxn<<1],edge[maxn<<1],tot,fa[maxn],m,rt1[maxn];
int d[maxn],st[maxn<<1][21],lg[maxn<<1],dfn[maxn],ti,dep[maxn];
bool v[maxn];
void getRoot(int x,int f){
    sz[x]=1;mxson[x]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y]||y==f)continue;
        getRoot(y,x);
        sz[x]+=sz[y];
        mxson[x]=max(mxson[x],sz[y]);
    }
    mxson[x]=max(mxson[x],S-sz[x]);
    if(mxson[x]<mxson[rt])rt=x;
}
void init(int x){
    S=sz[x];
    mxson[rt=0]=maxn;
    getRoot(x,0);
}
void dfs(int x,int f,int dd){
    dfn[x]=++ti;d[x]=d[f]+1;st[ti][0]=x;
    dep[x]=dd;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs(y,x,dd+edge[i]);   
        st[++ti][0]=x;
    }
}
void RMQ(){
    lg[0]=-1;
    for(int i=1;i<=ti;++i)lg[i]=lg[i>>1]+1;
    for(int j=1;j<=lg[ti];++j)
        for(int i=1;(i+(1<<j)-1)<=ti;++i){
            int r=i+(1<<(j-1));
            st[i][j]=d[st[i][j-1]]<d[st[r][j-1]]?st[i][j-1]:st[r][j-1];
        }
}
int LCA(int l,int r){
    if(l>r)swap(l,r);
    int k=lg[r-l+1];
    return d[st[l][k]]<d[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}
void dfz(int x){
    v[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        init(y);
        fa[rt]=x;
        dfz(rt);
    }
}
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
struct SegmentTree{
    int tot,lc[N],rc[N],mn[N]={INF};
    void pushUp(int p){
        mn[p]=min(mn[ls],mn[rs]);
    }
    void update(int&p,int l,int r,int x,int val){
        if(!p){p=++tot;mn[p]=INF;}
        if(l==r){
            mn[p]=min(val,mn[p]);return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int query(int p,int l,int r,int L,int R){
        if(!p)return INF;
        if(L<=l&&r<=R)return mn[p];
        int mid=l+r>>1;
        int ans=INF;
        if(L<=mid)ans=min(ans,query(lson,L,R));
        if(R>mid)ans=min(ans,query(rson,L,R));
        return ans;
    }
}tr;
int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[LCA(dfn[x],dfn[y])];
}
void update(int x){
    for(int i=x;i;i=fa[i]){
        int dd=dis(x,i);
        tr.update(rt1[i],1,n,x,dd);
    }
}
int query(int x,int L,int R){
    int ans=INF;
    for(int i=x;i;i=fa[i])
        ans=min(ans,dis(i,x)+tr.query(rt1[i],1,n,L,R));
    return ans;
}
int main(){
    scanf("%d",&n);
    int u,v,w;
    for(int i=1;i<n;++i){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    dfs(1,0,0);
    RMQ();
    S=n;
    mxson[rt=0]=maxn;
    getRoot(1,0);
    dfz(rt);
    for(int i=1;i<=n;++i)
        update(i);
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d%d",&u,&v,&w);
        cout<<query(w,u,v)<<"\n";
    }
    return 0;
}