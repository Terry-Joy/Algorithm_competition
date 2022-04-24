#include<bits/stdc++.h>
#define fi first 
#define se second  
#define pb push_back
using namespace std;
const int maxn=1e5+5;
int f[maxn][20],lg[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],tot,sz[maxn],son[maxn],fat[maxn],vi,pi,cnt[maxn<<1],hs,dep[maxn],m,ans[maxn],n,rt[maxn],num;
typedef pair<int,int>P;
vector<P>Q[maxn];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int fa){
    sz[x]=1;dep[x]=dep[fa]+1;
    f[x][0]=fa;
    for(int i=1;i<=lg[dep[x]];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]])son[x]=y;
    }
}
int kth(int x,int k){
    for(int i=lg[dep[x]];i>=0;--i)
        if(dep[x]-dep[f[x][i]]<=k)k-=dep[x]-dep[f[x][i]],x=f[x][i];
    return x;
}
void cal(int x,int fa,int val){
    cnt[dep[x]]+=val;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa||y==hs)continue;
        cal(y,x,val);
    }
}
void dsu(int x,int fa,bool op){
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa||y==son[x])continue;
        dsu(y,x,0);
    }
    if(son[x])dsu(son[x],x,1),hs=son[x];
    cal(x,fa,1);
    hs=0;
    for(auto&v:Q[x]){
        ans[v.fi]=((cnt[v.se+dep[x]]==0)?0:cnt[v.se+dep[x]]-1);
    }
    if(!op)cal(x,fa,-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    int a;
    for(int i=1;i<=n;++i){
        cin>>fat[i];
        if(fat[i])add(fat[i],i);
        else rt[++num]=i;
    }
    for(int i=1;i<=num;++i)
        dfs(rt[i],0);
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>vi>>pi;
        if(dep[vi]-1<pi)continue;
        int rt=kth(vi,pi);
        Q[rt].pb({i,pi});
    }
    for(int i=1;i<=num;++i) 
        dsu(rt[i],0,0);
    for(int i=1;i<=m;++i)cout<<ans[i]<<"\n";
    return 0;
}