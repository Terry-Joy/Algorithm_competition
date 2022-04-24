//树剖模板点权链加、链和查询、子树加、子树和、lca、换根
#include<bits/stdc++.h>
#define ls p<<1 
#define rs p<<1|1 
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r 
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int head[maxn],next1[maxn<<1],ver[maxn<<1],tot,n,m,a[maxn],op,u,v,rt,nval[maxn],ti;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct SegmentTree{
    ll sum[maxn<<2],add[maxn<<2];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void pushDown(int p,int l,int r){
        int mid=l+r>>1;
        sum[ls]+=1ll*(mid-l+1)*add[p];
        sum[rs]+=1ll*(r-mid)*add[p];
        add[ls]+=add[p];add[rs]+=add[p];
        add[p]=0;
    }
    void build(int p,int l,int r){
        add[p]=0;
        if(l==r){
            sum[p]=nval[l];
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    ll query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        if(add[p])
            pushDown(p,l,r);
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            sum[p]+=1ll*(r-l+1)*val;
            add[p]+=val;return;
        }
        if(add[p])
            pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
}tr;
struct HCD{
    int fa[maxn],son[maxn],dep[maxn],sz[maxn],top[maxn],in[maxn];
    //树剖部分
    void dfs1(int x,int f){//第一遍处理父亲、深度、重儿子、子树大小
        fa[x]=f;sz[x]=1;
        dep[x]=dep[f]+1;
        int mxson=-1;
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==f)continue;
            dfs1(y,x);
            sz[x]+=sz[y];
            if(sz[y]>mxson)son[x]=y,mxson=sz[y];//记录重儿子
        }
    }
    
    void dfs2(int x,int t){//重新标号赋值、记录链顶端
        in[x]=++ti;
        nval[ti]=a[x];
        top[x]=t;
        if(!son[x])return;//叶子
        dfs2(son[x],t);//先重后轻
        for(int i=head[x];i;i=next1[i]){
            int y=ver[i];
            if(y==fa[x]||y==son[x])continue;
            dfs2(y,y);//轻边自己开始
        }
    }

    void init(int x){
        dfs1(x,0);dfs2(x,x);
    }

    //求lca
    int lca(int x,int y){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        return x;
    }
    //链查询
    ll Pquery(int x,int y){//顶端深度深的跳，直到相同，修改同理
        ll ans=0;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            ans+=tr.query(1,1,ti,in[top[x]],in[x]);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        ans+=tr.query(1,1,ti,in[y],in[x]);
        return ans;
    }
    //链修改
    void Pupdate(int x,int y,int val){
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            tr.update(1,1,ti,in[top[x]],in[x],val);
            x=fa[top[x]];
        }
        if(dep[x]<dep[y])swap(x,y);
        tr.update(1,1,ti,in[y],in[x],val);
    }
    //找y的祖先中x的儿子
    int findson(int x,int y){
        while(top[x]!=top[y]){
            if(fa[top[y]]==x)
                return top[y];
            y=fa[top[y]];
        }
        return son[x];
    }
    //可判断换根子树修改
    void Sonupdate(int x,int val){
        if(lca(x,rt)!=x)//新根在x子树外，无影响
            tr.update(1,1,ti,in[x],in[x]+sz[x]-1,val);
        else if(x==rt)//本身一颗
            tr.update(1,1,ti,1,ti,val);
        else{//整颗减去新根的祖先中x为根的子树
            int s=findson(x,rt);
            tr.update(1,1,ti,1,in[s]-1,val);
            if(in[s]+sz[s]<=n)
                tr.update(1,1,ti,in[s]+sz[s],ti,val);
        }
    }   
    //可判断换根子树查询
    ll Sonquery(int x){
        if(lca(x,rt)!=x)
            return tr.query(1,1,ti,in[x],in[x]+sz[x]-1);
        else if(x==rt)
            return tr.sum[1];
        else{
            int s=findson(x,rt);
            ll ans=0;
            ans+=tr.query(1,1,ti,1,in[s]-1);
            if(in[s]+sz[s]<=n)
                ans+=tr.query(1,1,ti,in[s]+sz[s],ti);
            return ans;
        }
    }
}hcd;
int main(){
    rt=1;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    int x;
    for(int i=1;i<=n-1;++i){
        scanf("%d",&x);
        add(i+1,x);
        add(x,i+1);
    }
    hcd.init(1);
    tr.build(1,1,ti);
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        scanf("%d",&op);
        if(op==1){//换根
            scanf("%d",&rt);
        }else if(op==2){//链修改
            scanf("%d%d%d",&u,&v,&x);
            hcd.Pupdate(u,v,x);
        }else if(op==3){//子树修改
            scanf("%d%d",&u,&x);
            hcd.Sonupdate(u,x);
        }else if(op==4){//链查询
            scanf("%d%d",&u,&v);
            cout<<hcd.Pquery(u,v)<<"\n";
        }else{//子树查询
            scanf("%d",&u);
            cout<<hcd.Sonquery(u)<<"\n";
        }
    }
    return 0;
}
