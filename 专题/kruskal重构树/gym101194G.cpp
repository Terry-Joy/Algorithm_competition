#include<bits/stdc++.h>
#define N M*36
#define lson lc[p],l,mid 
#define rson rc[p],mid+1,r 
#define ls lc[p] 
#define rs rc[p]
#define pb push_back
using namespace std;
const int M=2e5+5;
struct Edge{
    int u,v,w;
    bool operator<(const Edge&a){
        return w<a.w;
    }
}edge[M];
vector<int>G[M];
int cnt,fa[M],f[M][22],col[M],Q,d[M],rt[M],ans[M],n,m,lg[M],val[M],t;
int find(int x){
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
struct SegmentTree{
    int tot,lc[N],rc[N],mx[N],sum[N];
    void pushUp(int p){
        mx[p]=max(mx[ls],mx[rs]);
        if(mx[ls]>=mx[rs])sum[p]=sum[ls];
        else sum[p]=sum[rs];
    }
    void update(int&p,int l,int r,int x){
        if(!p){p=++tot;ls=rs=0;mx[p]=sum[p]=0;}
        if(l==r){
            mx[p]=1;sum[p]=l;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x);
        else update(rson,x);
        pushUp(p);
    }
    int merge(int p,int q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){
            mx[p]+=mx[q];sum[p]=max(sum[p],sum[q]);return p;
        }
        int mid=l+r>>1;
        ls=merge(lc[p],lc[q],l,mid);
        rs=merge(rc[p],rc[q],mid+1,r);
        pushUp(p);
        return p;
    }
}tr;
void dfs(int x,int fat){
    d[x]=d[fat]+1;
    f[x][0]=fat;
    for(int i=1;i<=lg[d[x]];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for(auto&v:G[x]){
        if(v==fat)continue;
        dfs(v,x);
        rt[x]=tr.merge(rt[x],rt[v],1,n);
    }
    ans[x]=tr.sum[rt[x]];
}
void exKruskal(){
    cnt=n;
    for(int i=1;i<(n<<1);++i)fa[i]=i;
    sort(edge+1,edge+1+m);
    for(int i=1;i<=m;++i){
        int xx=find(edge[i].u),yy=find(edge[i].v);
        if(xx==yy)continue;
        val[++cnt]=edge[i].w;
        fa[xx]=fa[yy]=cnt;
        G[xx].pb(cnt);G[cnt].pb(xx);
        G[yy].pb(cnt);G[cnt].pb(yy);
    }
    dfs(cnt,0);
}
int main(){
    for(int i=1;i<=200000;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    scanf("%d",&t);
    int T=0;
    while(t--){
        scanf("%d%d",&n,&m);
        tr.tot=0;
        for(int i=1;i<2*n;++i)G[i].clear(),rt[i]=0,ans[i]=0;
        for(int i=1;i<=n;++i)scanf("%d",&col[i]),tr.update(rt[i],1,n,col[i]);
        for(int i=1;i<=m;++i){
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        }
        exKruskal();
        scanf("%d",&Q);
        int res=0;
        int u,v;
        cout<<"Case #"<<++T<<":\n";
        while(Q--){
            scanf("%d%d",&u,&v);
            u^=res;v^=res;
            for(int i=lg[cnt];i>=0;--i){
                if(f[u][i]&&val[f[u][i]]<=v)
                    u=f[u][i];
            }
            res=ans[u];
            cout<<res<<"\n";
        }
    }
    return 0;
}