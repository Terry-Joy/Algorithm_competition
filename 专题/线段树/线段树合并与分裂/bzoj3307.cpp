#include<bits/stdc++.h>
#define N maxn*50
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define pb push_back
using namespace std;
const int maxn=1e5+5;
vector<int>G[maxn];
int n,m,a,b,lg[maxn],f[maxn][18],d[maxn],L[maxn],R[maxn],val[maxn],mx=0,fat[maxn];
int ans1[maxn];
struct SegmentTree{
    int rt[maxn],tot,lc[N],rc[N],num[N],ans[N];
    void pushUp(int p){
        num[p]=max(num[ls],num[rs]);
        if(num[ls]>=num[rs])ans[p]=ans[ls];
        else ans[p]=ans[rs];
    }
    void update(int&p,int l,int r,int x,int val){
        if(!p)p=++tot;
        if(l==r){
            num[p]+=val;ans[p]=l;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int merge(int p,int q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){
            num[p]+=num[q];
            ans[p]=l;return p;
        }
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        pushUp(p);
        return p;
    }
}tr;
void dfs(int x,int fa){
    d[x]=d[fa]+1;
    f[x][0]=fa;
    for(int i=1;i<=lg[d[x]];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs(v,x);
        fat[v]=x;
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
void dfs1(int x,int fa){
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs1(v,x);
        tr.rt[x]=tr.merge(tr.rt[x],tr.rt[v],1,mx);
    }
    if(!tr.num[tr.rt[x]])ans1[x]=0;
    else ans1[x]=tr.ans[tr.rt[x]];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<n;++i){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1,0);
    for(int i=1;i<=m;++i){
        cin>>L[i]>>R[i]>>val[i];
        mx=max(val[i],mx);
    }
    for(int i=1;i<=m;++i){
        tr.update(tr.rt[L[i]],1,mx,val[i],1);
        tr.update(tr.rt[R[i]],1,mx,val[i],1);
        int k=lca(L[i],R[i]);
        tr.update(tr.rt[k],1,mx,val[i],-1);
        tr.update(tr.rt[fat[k]],1,mx,val[i],-1);//dfs父亲设为0，不然越界到-1了
    }
    dfs1(1,0);
    for(int i=1;i<=n;++i)
        cout<<ans1[i]<<"\n";
    return 0;
}