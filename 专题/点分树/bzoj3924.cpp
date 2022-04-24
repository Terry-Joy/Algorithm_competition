#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int head1[maxn],head2[maxn],next1[maxn<<1],next2[maxn<<1],ver1[maxn<<1],ver2[maxn<<1],edge1[maxn<<1],edge2[maxn<<1];
int tot1,tot2,sz[maxn],mxson[maxn],S,rt,dfn[maxn],d[maxn],st[maxn<<1][21],lg[maxn<<1],ti,fa[maxn],n,q;
ll sumd[maxn],sumf[maxn],sum[maxn];//点分树上自己对自己的答案贡献，自己对父亲的答案贡献，自己对自己的点数贡献
ll dep[maxn];
bool v[maxn];
void add1(int x,int y,int z){
    ver1[++tot1]=y,next1[tot1]=head1[x],edge1[tot1]=z,head1[x]=tot1;
}
void add2(int x,int y,int z){
    ver2[++tot2]=y,next2[tot2]=head2[x],edge2[tot2]=z,head2[x]=tot2;
}
void dfs(int x,int f,int dd){
    dfn[x]=++ti;d[x]=d[f]+1;st[ti][0]=x;
    dep[x]=dd;
    for(int i=head1[x];i;i=next1[i]){
        int y=ver1[i];
        if(y==f)continue;
        dfs(y,x,dd+edge1[i]);   
        st[++ti][0]=x;
    }
}
void RMQ(){
    lg[0]=-1;
    for(int i=1;i<=ti;++i)lg[i]=lg[i>>1]+1;
    for(int j=1;j<=20;++j)
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
void getRoot(int x,int f){
    sz[x]=1;mxson[x]=0;
    for(int i=head1[x];i;i=next1[i]){
        int y=ver1[i];
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
void dfz(int x){
    v[x]=1;
    for(int i=head1[x];i;i=next1[i]){
        int y=ver1[i];
        if(v[y])continue;
        init(y);
        add2(x,rt,y);
        fa[rt]=x;
        dfz(rt);   
    }
}
int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[LCA(dfn[x],dfn[y])];
}
void update(int x,int val){
    sum[x]+=val;
    for(int i=x;fa[i];i=fa[i]){
        int len=dis(x,fa[i]);
        sum[fa[i]]+=val;
        sumd[fa[i]]+=1ll*val*len;
        sumf[i]+=1ll*val*len;
    }
}
ll cal(int x){
    // dbg(x,sumd[x]);
    ll ans=sumd[x];
    for(int i=x;fa[i];i=fa[i]){
        int len=dis(x,fa[i]);
        ans+=1ll*(sum[fa[i]]-sum[i])*len;
        ans+=(sumd[fa[i]]-sumf[i]);
    }
    return ans;
}
ll query(int x){
    ll ans=cal(x);
    for(int i=head2[x];i;i=next2[i]){
        int y=ver2[i];
        if(cal(edge2[i])<ans)return query(y);
    }   
    return ans;
}
signed main(){
    scanf("%lld%lld",&n,&q);
    // dbg(1);
    int u,v,w;
    for(int i=1;i<n;++i){
        scanf("%lld%lld%lld",&u,&v,&w);
        add1(u,v,w);add1(v,u,w);
        // dbg(head1,ver1,next1,tot1);
    }
    dfs(1,0,0);
    RMQ();
    S=n;
    mxson[rt=0]=maxn;
    getRoot(1,0);
    int root=rt;
    dfz(rt);
    for(int i=1;i<=q;++i){
        scanf("%lld%lld",&u,&w);
        update(u,w);
        cout<<(query(root))<<"\n";
    }
    return 0;
}