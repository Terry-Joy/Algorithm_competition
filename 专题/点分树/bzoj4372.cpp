#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid 
#define rson rc[p],mid+1,r
#define N maxn*172
using namespace std;
const int maxn=1e5+5;
bool v[maxn];
int sz[maxn],mxson[maxn],rt1[maxn],rt2[maxn],rt,S,fa[maxn],dfn[maxn],st[maxn<<1][21],lg[maxn<<1],ti,d[maxn],n,m;
int head[maxn],next1[maxn<<1],ver[maxn<<1],tot;
struct SegmentTree{
    int cnt,lc[N],rc[N],sum[N];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void update(int&p,int l,int r,int x,int val){
        if(!p)p=++cnt;
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
        if(R<l||L>r)return 0;
        if(L<=l&&r<=R)return sum[p];
        int ans=0,mid=l+r>>1;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
}tr;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void getRoot(int x,int fat){
    sz[x]=1;mxson[x]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fat||v[y])continue;
        getRoot(y,x);
        sz[x]+=sz[y];
        mxson[x]=max(mxson[x],sz[y]);
    }
    mxson[x]=max(mxson[x],S-sz[x]);
    if(mxson[x]<mxson[rt])rt=x;
}
void dfs(int x,int fat){
    dfn[x]=++ti;d[x]=d[fat]+1;st[ti][0]=x;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fat)continue;
        dfs(y,x);
        st[++ti][0]=x;
    }
}
void RMQ(){
    for(int i=2;i<=ti;++i)lg[i]=lg[i>>1]+1;
    for(int j=1;j<=lg[ti];++j)
        for(int i=1;(i+(1<<j)-1)<=ti;++i){
            int r=i+(1<<(j-1));
            st[i][j]=d[st[i][j-1]]<d[st[r][j-1]]?st[i][j-1]:st[r][j-1];
        }
}
int query(int l,int r){
    if(l>r)swap(l,r);
    int k=lg[r-l+1];
    return d[st[l][k]]<d[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}
int LCA(int x,int y){
    return query(dfn[x],dfn[y]);
}
void init(int x){
    S=sz[x];
    mxson[rt=0]=maxn;
    getRoot(x,0);
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
int dis(int x,int y){
    return d[x]+d[y]-2*d[LCA(x,y)];
}
void update(int x,int d,int w){
    for(int i=x;i;i=fa[i]){//???????????????
        int dd=dis(x,i);
        if(d-dd>=0)
            tr.update(rt1[i],0,n,d-dd,w);
    }
    for(int i=x;fa[i];i=fa[i]){
        int dd=dis(x,fa[i]);//???????????????
        if(d-dd>=0)
            tr.update(rt2[i],0,n,d-dd,w);
    }
}
int query(int x){
    int ans=0;
    for(int i=x;i;i=fa[i]){
        int dd=dis(x,i);
        ans+=tr.query(rt1[i],0,n,dd,n);
    }
    for(int i=x;fa[i];i=fa[i]){
        int dd=dis(x,fa[i]);
        ans-=tr.query(rt2[i],0,n,dd,n);
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    int u,v,w;
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs(1,0);
    RMQ();
    S=n;
    mxson[rt=0]=maxn;
    getRoot(1,0);
    fa[rt]=0;
    dfz(rt);
    char s[5];
    for(int i=1;i<=m;++i){
        scanf("%s",s);
        if(s[0]=='M'){
            scanf("%d%d%d",&u,&v,&w);
            update(u,v,w);
        }else{
            scanf("%d",&u);
            cout<<query(u)<<"\n";
        }   
    }
    return 0;
}
