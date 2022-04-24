#include<bits/stdc++.h>
#define N maxn*2*18*2
#define pb push_back
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=3e5+5;
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}//是符号
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}//是数字
    return x*s;
}
inline void in(int&x){
    x=read();
}
int n,m,w[maxn],a,b,f[maxn][21],d[maxn],lg[maxn],fat[maxn],ans[maxn];
int head[maxn],ver[maxn<<1],next1[maxn<<1],cnt;
void add(int x,int y){
	ver[++cnt]=y,next1[cnt]=head[x];head[x]=cnt;
} 
struct SegmentTree{
    int rt1[maxn],rt2[maxn],tot,sum[N],lc[N],rc[N];
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
    int query(int p,int l,int r,int x){
        if(!p)return 0;
        if(l==r)return sum[p];
        int mid=l+r>>1;
        if(x<=mid)return query(lson,x);
        else return query(rson,x);
    }
    int merge(int p,int q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){
            sum[p]+=sum[q];return p;
        }
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        pushUp(p);
        return p;
    }
}tr;
void dfs1(int x,int fa){
    d[x]=d[fa]+1;
    f[x][0]=fa;
    for(int i=1;i<=lg[d[x]];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=next1[i]){
        int v=ver[i];
        if(v==fa)continue;
        dfs1(v,x);
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
void dfs2(int x,int fa){
    for(int i=head[x];i;i=next1[i]){
    	int v=ver[i];
        if(v==fa)continue;
        dfs2(v,x);
        tr.rt1[x]=tr.merge(tr.rt1[x],tr.rt1[v],-n,n);
        tr.rt2[x]=tr.merge(tr.rt2[x],tr.rt2[v],-n,n);
    }
    ans[x]=tr.query(tr.rt1[x],0,2*n,d[x]+w[x])+tr.query(tr.rt2[x],-n,n,w[x]-d[x]);

}
int main(){
    in(n);in(m);
    for(int i=1;i<n;++i){
        in(a);in(b);
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;++i)in(w[i]);
    for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    dfs1(1,0);
    for(int i=1;i<=m;++i){
        in(a);in(b);
        int LCA=lca(a,b);
        tr.update(tr.rt1[a],0,2*n,d[a],1);//查找的位置会到2*n
        tr.update(tr.rt1[fat[LCA]],0,2*n,d[a],-1);
        tr.update(tr.rt2[b],-n,n,d[a]-2*d[LCA],1);
        tr.update(tr.rt2[LCA],-n,n,d[a]-2*d[LCA],-1);
    }
    dfs2(1,0);
    for(int i=1;i<=n;++i)printf("%d ",ans[i]);
    return 0;
}