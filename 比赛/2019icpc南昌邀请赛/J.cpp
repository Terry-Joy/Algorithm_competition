#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define N maxn*36
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=1e5+5;
int f[maxn][20],head[maxn],ver[maxn<<1],next1[maxn<<1],d[maxn],a[maxn],b[maxn],fat[maxn],rt[maxn],cnt;
int n,m,lg[maxn],tot;
struct Edge{
    int u,v,w;
}edge[maxn];
inline int read(){
    char c=getchar();int x=0;
    while(c<'0'||c>'9'){c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x;
}
inline void in(int&x){
    x=read();
}
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int fa){
    fat[x]=fa;
    d[x]=d[fa]+1;
    f[x][0]=fa;
    for(int i=1;i<=lg[d[x]];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
    }
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y])
        x=f[x][lg[d[x]-d[y]]-1];
    if(x==y)return x;
    for(int i=lg[d[y]]-1;i>=0;--i)
        if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
struct Persistable_SegmentTree{
    int tot,sum[N],lc[N],rc[N];
    void update(int q,int&p,int l,int r,int x){
        p=++tot;
        lc[p]=lc[q];rc[p]=rc[q];sum[p]=sum[q]+1;
        if(l==r)return;
        int mid=l+r>>1;
        if(x<=mid)update(lc[q],lson,x);
        else update(rc[q],rson,x);
    }
    int query(int q1,int q2,int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[q1]+sum[q2]-2*sum[p];
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lc[q1],lc[q2],lson,L,R);
        if(R>mid)ans+=query(rc[q1],rc[q2],rson,L,R);
        return ans;
    }
}tr;
void dfs1(int x,int f){
    tr.update(rt[f],rt[x],1,cnt,a[x]);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs1(y,x);
    }
}
int main(){
    in(n);in(m);
    for(int i=1;i<n;++i){
        in(edge[i].u);in(edge[i].v);in(edge[i].w);
        add(edge[i].u,edge[i].v);
        add(edge[i].v,edge[i].u);
    }
    for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    dfs(1,0);
    a[1]=b[1]=2e9;
    for(int i=1;i<n;++i){
        if(fat[edge[i].u]==edge[i].v)a[edge[i].u]=edge[i].w,b[edge[i].u]=a[edge[i].u];
        else a[edge[i].v]=edge[i].w,b[edge[i].v]=a[edge[i].v];
    }
    sort(b+1,b+1+n);
    cnt=unique(b+1,b+1+n)-(b+1);
    for(int i=1;i<=n;++i)
        a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
    dfs1(1,0);
    int u,v,k;
    for(int i=1;i<=m;++i){
        in(u);in(v);in(k);
        int id=upper_bound(b+1,b+1+cnt,k)-b-1;
        int LCA=lca(u,v);
        if(id<1)puts("0");
        else
            cout<<tr.query(rt[u],rt[v],rt[LCA],1,cnt,1,id)<<"\n";
    }
    return 0;
}