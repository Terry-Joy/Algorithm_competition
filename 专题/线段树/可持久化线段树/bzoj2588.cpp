#include<bits/stdc++.h>
#define N maxn*36
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define ls lc[p]
#define rs rc[p]
using namespace std;
const int maxn=1e5+5;
int rt[maxn],a[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1];
int cnt,f[maxn][20],d[maxn],lg[maxn],b[maxn],num,fat[maxn];
struct Persistable_SegmentTree{
    int tot,lc[N],rc[N],sum[N];
    void update(int q,int&p,int l,int r,int x){
        p=++tot;
        sum[p]=sum[q]+1;
        ls=lc[q];rs=rc[q];
        if(l==r)return;
        int mid=l+r>>1;
        if(x<=mid)update(lc[q],lson,x);
        else update(rc[q],rson,x);
    }
    int query(int p1,int p2,int p3,int p,int l,int r,int k){
        if(l==r)return b[l];
        int mid=l+r>>1;
        int tmp=sum[lc[p1]]+sum[lc[p2]]-sum[lc[p3]]-sum[lc[p]];
        if(tmp>=k)return query(lc[p1],lc[p2],lc[p3],lson,k);
        else return query(rc[p1],rc[p2],rc[p3],rson,k-tmp);
    }
}tr;
void add(int x,int y){
    ver[++cnt]=y,next1[cnt]=head[x],head[x]=cnt;
}
void dfs(int x,int fa){
    tr.update(rt[fa],rt[x],1,num,a[x]);
    d[x]=d[fa]+1;
    f[x][0]=fa;
    for(int i=1;i<=lg[d[x]];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=next1[i]){
    	int v=ver[i];
        if(v==fa)continue;
        fat[v]=x;
        dfs(v,x);
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
int n,m,x,y;   
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)		//预处理log2(n)+1 
    	lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    num=unique(b+1,b+1+n)-(b+1);
    for(int i=1;i<=n;++i){
        a[i]=lower_bound(b+1,b+1+num,a[i])-b;
    }
    for(int i=1;i<n;++i){
        cin>>x>>y;
        add(x,y);add(y,x);
    }
    dfs(1,0);
    fat[1]=0;
    int pre=0;
    for(int i=1;i<=m;++i){
        int u,v,k;
        cin>>u>>v>>k;
        u=u^pre;
        int LCA=lca(u,v),fatlca=fat[LCA];
        pre=tr.query(rt[u],rt[v],rt[LCA],rt[fatlca],1,num,k);
        cout<<pre<<"\n";
    }
    return 0;
}