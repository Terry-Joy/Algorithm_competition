#include<bits/stdc++.h>
#define pb push_back 
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r 
#define ls lc[p]
#define rs rc[p]
#define N maxn*36
using namespace std;
const int maxn=2e5+5;
int n,q,rt[maxn],st,x,ti[maxn],f[maxn][21],d[maxn],lg[maxn],fat[maxn];
vector<int>G[maxn];
struct Q{
    int op,x,y,c;
}qs[maxn];
struct Persistable_SegmentTree{
    int tot,lc[N],rc[N],num[N];
    void update(int q,int&p,int l,int r,int x){
        p=++tot;
        lc[p]=lc[q];rc[p]=rc[q];num[p]=num[q]+1;
        if(l==r)return;
        int mid=l+r>>1;
        if(x<=mid)update(lc[q],lson,x);
        else update(rc[q],rson,x);
    }
    int query(int p1,int p2,int p3,int p,int l,int r,int L,int R){
        if(R<l||L>r||L>R)return 0;
        if(L<=l&&r<=R)  return num[p1]+num[p2]-num[p3]-num[p];
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lc[p1],lc[p2],lc[p3],lson,L,R);
        if(R>mid) ans+=query(rc[p1],rc[p2],rc[p3],rson,L,R);
        return ans;
    }
}tr;
void dfs1(int x,int fa){
    fat[x]=fa;
    d[x]=d[fa]+1;
    f[x][0]=fa;
    for(int i=1;i<=lg[d[x]];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    rt[x]=rt[fa];
    if(ti[x])tr.update(rt[fa],rt[x],1,q,ti[x]);
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs1(v,x);
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<=n;++i){
        cin>>x;
        if(!x)st=i;
        else{
            G[i].pb(x);
            G[x].pb(i);
        }
    }
    cin>>q;
    for(int i=1;i<=q;++i){
        cin>>qs[i].op;
        if(qs[i].op==1)cin>>qs[i].x>>qs[i].y>>qs[i].c;
        else cin>>qs[i].x,ti[qs[i].x]=i;
    }
    dfs1(st,0);
    for(int i=1;i<=q;++i){
        if(qs[i].op==1){
            int LCA=lca(qs[i].x,qs[i].y);
            cout<<d[qs[i].x]+d[qs[i].y]-2*d[LCA]+1<<" "
            <<tr.query(rt[qs[i].x],rt[qs[i].y],rt[LCA],rt[fat[LCA]],1,q,1,i-qs[i].c-1)<<"\n";
        }
        else continue;
    }
    return 0;
}