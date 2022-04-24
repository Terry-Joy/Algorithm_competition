#include<iostream>
#include<cstdio>
#include<algorithm>
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r 
#define ls p<<1  
#define rs p<<1|1
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int t,n,m,x,y,head[maxn],ver[maxn<<1],next1[maxn<<1],ti,in[maxn],out[maxn],op,a[maxn],tot;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct SegmentTree{
    ll mx[maxn<<2],add[maxn<<2];
    void pushDown(int p,int l,int r){
        int mid=l+r>>1;
        mx[ls]+=(mid-l+1)*add[p];
        mx[rs]+=(r-mid)*add[p];
        add[ls]+=add[p];add[rs]+=add[p];
        add[p]=0;   
    }
    void pushUp(int p){
        mx[p]=max(mx[ls],mx[rs]);
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            mx[p]+=1ll*(r-l+1)*val;
            add[p]+=val;return;
        }
        if(add[p])
            pushDown(p,l,r);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
    void build(int p,int l,int r){
        add[p]=0;
        if(l==r){
            mx[p]=0;return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    ll query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return mx[p];
        int mid=l+r>>1;
        if(add[p])
            pushDown(p,l,r);
        ll ans=0;
        if(L<=mid)ans=max(ans,query(lson,L,R));
        if(R>mid)ans=max(ans,query(rson,L,R));
        return ans;
    }
}tr;
void dfs(int x,int fa){
    in[x]=++ti;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
    }
    out[x]=ti;
}
int main(){
    scanf("%d",&t);
    int T=0;
    while(t--){
        scanf("%d%d",&n,&m);
        tot=0;//清空
        for(int i=0;i<=n;++i)head[i]=0;
        for(int i=1;i<n;++i){
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        cout<<"Case #"<<++T<<":\n";
        dfs(0,-1);
        tr.build(1,1,n);
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            tr.update(1,1,n,in[i],out[i],a[i]);
        }
        for(int i=1;i<=m;++i){
            scanf("%d",&op);
            if(!op){
                scanf("%d%d",&x,&y);
                tr.update(1,1,n,in[x],out[x],y-a[x]);
                a[x]=y;
            }else{
                scanf("%d",&x);
                cout<<tr.query(1,1,n,in[x],out[x])<<"\n";
            }
        }
    }
    return 0;
}