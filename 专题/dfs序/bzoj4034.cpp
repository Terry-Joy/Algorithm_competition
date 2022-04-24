#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r 
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int a[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],tot,ti,in[maxn],out[maxn],val[maxn<<1],f[maxn<<1];
struct SegmentTree{
    ll sum[maxn<<3],add[maxn<<3];
    void pushDown(int p,int l,int r){
        int mid=l+r>>1;
        sum[ls]+=1ll*(f[mid]-f[l-1])*add[p];
        sum[rs]+=1ll*(f[r]-f[mid])*add[p];
        add[ls]+=add[p];add[rs]+=add[p];
        add[p]=0;   
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            sum[p]+=1ll*(f[r]-f[l-1])*val;
            add[p]+=val;
            return;
        }
        if(add[p])pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void build(int p,int l,int r){
        add[p]=0;
        if(l==r){
            sum[p]=val[l];return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    ll query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        if(add[p])pushDown(p,l,r);
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
}tr;
void dfs(int x,int fa){
    in[x]=++ti;
    val[ti]=a[x];f[ti]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
    }
    out[x]=++ti;
    val[ti]=-a[x];f[ti]=-1;
}
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;    
}
int main(){
    int n,m,q,op;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    int x,y;
    for(int i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    for(int i=1;i<=ti;++i)f[i]+=f[i-1];
    tr.build(1,1,ti);
    for(int i=1;i<=q;++i){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&x,&y);
            tr.update(1,1,ti,in[x],in[x],y);
            tr.update(1,1,ti,out[x],out[x],y);
        }else if(op==2){
            scanf("%d%d",&x,&y);
            tr.update(1,1,ti,in[x],out[x],y);      
        }else if(op==3){
            scanf("%d",&x);
            cout<<tr.query(1,1,ti,1,in[x])<<"\n";
        }
    }
    return 0;
}