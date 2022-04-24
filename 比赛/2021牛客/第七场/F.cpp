#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define pb push_back
using namespace std;
const int maxn=3e5+5;
void read(int&x){ 
    char c=getchar();x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){ x=x*10+c-'0';c=getchar();}
}
vector<int>G1[maxn],G2[maxn];
int fa[maxn],son[maxn],dep[maxn],sz[maxn],top[maxn],in[maxn];
int dp[maxn],mx[maxn<<2],n,ans,ti;
void dfs1(int x,int f){ 
    fa[x]=f;sz[x]=1;
    dep[x]=dep[f]+1;
    int mxson=-1;
    for(auto&v:G2[x]){ 
        if(v==f)continue;
        dfs1(v,x);
        sz[x]+=sz[v];
        if(sz[v]>mxson)son[x]=v,mxson=sz[v];
    }
}
void dfs2(int x,int t){ 
    in[x]=++ti;
    top[x]=t;
    if(!son[x])return;
    dfs2(son[x],t);
    for(auto&v:G2[x]){
        if(v==fa[x]||v==son[x])continue;
        dfs2(v,v);
    }
}
void init(){ 
    ans=ti=0;
    for(int i=1;i<=n;++i)G1[i].clear(),G2[i].clear();
    for(int i=1;i<=n+2;++i)son[i]=fa[i]=top[i]=dp[i]=dep[i]=sz[i]=in[i]=0;
    for(int i=1;i<=4*n;++i)mx[i]=0;
}
int query(int p,int l,int r,int L,int R){ 
    if(L<=l&&r<=R)return mx[p];
    int mid=l+r>>1,res=0;
    if(L<=mid)res=max(res,query(lson,L,R));
    if(R>mid)res=max(res,query(rson,L,R));
    return res;
}
void update(int p,int l,int r,int x,int val){ 
    if(l==r){ 
        mx[p]=val;return;
    }
    int mid=l+r>>1;
    if(x<=mid)update(lson,x,val);
    else update(rson,x,val);
    mx[p]=max(mx[ls],mx[rs]);
}
int Pquery(int x,int y){ 
    int res=0;
    while(top[x]!=top[y]){ 
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        res=max(res,query(1,1,n,in[top[x]],in[x]));
        x=fa[top[x]];
    }    
    if(dep[x]<dep[y])swap(x,y);
    return max(res,query(1,1,n,in[y],in[x]));
}
void dfs(int x,int fa,int mxd){ 
    dp[x]=dp[fa]+1;
    mxd=max(mxd,Pquery(1,x));
    mxd=max(mxd,query(1,1,n,in[x],in[x]+sz[x]-1));
    ans=max(ans,dp[x]-mxd);
    update(1,1,n,in[x],dp[x]);
    for(auto&v:G1[x]){ 
        if(v==fa)continue;
        dfs(v,x,mxd);
    } 
    update(1,1,n,in[x],0);
}
int main(){ 
    int t;
    read(t);
    while(t--){
        read(n);
        init(); 
        int a,b;
        for(int i=1;i<n;++i){ 
            read(a);read(b);
            G1[a].pb(b);
            G1[b].pb(a);
        }
        for(int i=1;i<n;++i){ 
            read(a);read(b);
            G2[a].pb(b);
            G2[b].pb(a);
        }
        dfs1(1,0);dfs2(1,1);
        dfs(1,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}
