#include<bits/stdc++.h>
#define N maxn*36
#define lson lc[p],l,mid 
#define rson rc[p],mid+1,r 
#define ls lc[p]
#define rs rc[p]
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int rt[maxn],dep[maxn],son[maxn],sz[maxn],a[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],tot,hs,n,k,mx=0,st[maxn],ti,dfn[maxn],ed[maxn];
ll ans=0;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs1(int x,int f){
    dep[x]=dep[f]+1;
    sz[x]=1;
    st[x]=++ti;dfn[ti]=x;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs1(y,x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]])son[x]=y;
    }
    ed[x]=ti;
}
struct SegmentTree{
    int tot,lc[N],rc[N],sum[N];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void update(int&p,int l,int r,int x,int val){
        if(!p)p=++tot;
        if(l==r){
            sum[p]+=val;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int query(int p,int l,int r,int L,int R){
        if(!p)return 0;
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
}tr;
inline int read(){
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';c=getchar();
    }
    return x;
}
inline void in(int&x){
    x=read();
}
void dsu(int x,int f,bool op){
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==son[x])continue;
        dsu(y,x,0);
    }
    if(son[x])dsu(son[x],x,1),hs=son[x];
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==hs||y==f)continue;
        for(int j=st[y];j<=ed[y];++j){
            int dd=min(2*dep[x]-dep[dfn[j]]+k,n),val=2*a[x]-a[dfn[j]];
            if(dd>=1&&val<=n&&val>=0)//深度>n不应该不询问
                ans+=tr.query(rt[val],1,n,1,dd);
        }
        for(int j=st[y];j<=ed[y];++j)
            tr.update(rt[a[dfn[j]]],1,n,dep[dfn[j]],1);
    }//统计完再更新当前的
    tr.update(rt[a[x]],1,n,dep[x],1);
    hs=0;
    if(!op)
        for(int i=st[x];i<=ed[x];++i)
            tr.update(rt[a[dfn[i]]],1,n,dep[dfn[i]],-1);
}
int main(){
    in(n);in(k);
    for(int i=1;i<=n;++i)in(a[i]),mx=max(a[i],mx);
    int u;
    for(int i=2;i<=n;++i){
        in(u);
        add(u,i);add(i,u);
    }
    dfs1(1,0);
    dsu(1,0,0);
    cout<<ans*2<<"\n";
    return 0;
}