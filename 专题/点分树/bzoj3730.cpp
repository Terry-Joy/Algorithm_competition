#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int head[maxn],ver[maxn<<1],next1[maxn<<1],tot,dfn[maxn],d[maxn],st[maxn<<1][21],lg[maxn<<1],ti,sz[maxn],mxson[maxn],rt,S,mxdep,maxdep[maxn],newS;
int n,m,val[maxn],fa[maxn];
bool v[maxn];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct BIT{
    #define lowb(x) (x&(-x))
    vector<int>c;
    int N;
    void init(int x){
        N=x-1;
        c.resize(x);
    }
    void add(int x,int val){
        for(int i=x;i<=N;i+=lowb(i))c[i]+=val;
    }
    int ask(int x){
        int ans=0;
        for(int i=x;i;i-=lowb(i))ans+=c[i];
        return ans;
    }
}bit1[maxn],bit2[maxn];
void dfs(int x,int f){
    dfn[x]=++ti;d[x]=d[f]+1;st[ti][0]=x;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs(y,x);
        st[++ti][0]=x;
    }
}
void RMQ(){
    for(int i=2;i<=ti;++i)lg[i]=lg[i>>1]+1;
    for(int j=1;j<=lg[n];++j)
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
void getRoot(int x,int f){
    sz[x]=1;mxson[x]=0;
    newS++;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        getRoot(y,x);
        sz[x]+=sz[y];
        mxson[x]=max(mxson[x],sz[y]);
    }
    mxson[x]=max(mxson[x],S-mxson[x]);
    if(mxson[x]<mxson[rt])rt=x;
}
void init(int x){
    mxson[rt=0]=maxn;
    S=sz[x];
    getRoot(x,0);
}
void getMxD(int x,int f,int d){
    mxdep=max(mxdep,d);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        getMxD(y,x,d+1);
    }
}
void dfz(int x){
    v[x]=1;
    sz[x]=newS+1;//更新之前分治节点的sz用于询问的时候防止越界（或者直接取.size()) 
    bit1[x].init(newS+2);
    bit2[x].init(newS+2);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        newS=0;//用于初始化树状数组 
        init(y);
        fa[rt]=x;
        dfz(rt);
    }
}
int Q(int x,int k,bool flag){
    k=min(k+1,sz[x]);                  //+1因为vector的偏移
    int ans=0;
    ans+=(flag)?bit1[x].ask(k):bit2[x].ask(k);
    return ans;
}
int getDis(int x,int y){
    int lca=LCA(x,y);
    return d[x]+d[y]-2*d[lca];
}
void update(int x,int y){
    for(int i=x;i;i=fa[i])bit1[i].add(getDis(x,i)+1,y);
    for(int i=x;fa[i];i=fa[i])bit2[i].add(getDis(x,fa[i])+1,y);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&val[i]);
    int x,y,op;
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs(1,0);//预处理LCA
    RMQ();
    mxson[rt=0]=maxn;
    S=n;
    getRoot(1,0);
    fa[rt]=0;
    dfz(rt);
    for(int i=1;i<=n;++i)update(i,val[i]);
    int ans=0;
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&op,&x,&y);
        x^=ans;y^=ans;
        if(!op){
            ans=0;
            ans+=Q(x,y,1);//x子树内距离x<=k的贡献
            for(int f=x;fa[f];f=fa[f]){
                int dd=getDis(x,fa[f]);
                if(y-dd>=0){
                    ans+=Q(fa[f],y-dd,1)-Q(f,y-dd,0);//减去对当前对父亲加上父亲对自己
                }
            }
            cout<<ans<<"\n";
        }else
            update(x,y-val[x]),val[x]=y;
    }
    return 0;
}
