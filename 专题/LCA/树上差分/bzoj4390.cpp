#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=5e4+5;
int f[maxn][20],t,n,m,d[maxn],lg[maxn],ans[maxn],fat[maxn],k,a,b;
vector<int>G[maxn];
void dfs1(int x,int fa){
    d[x]=d[fa]+1;
    f[x][0]=fa;
    for(int i=1;i<=lg[d[x]];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for(auto&v:G[x]){
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
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
void dfs2(int x,int fa){
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs2(v,x);
        ans[x]+=ans[v];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<n;++i){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs1(1,0);
    for(int i=1;i<=k;++i){
        cin>>a>>b;
        ans[a]++;ans[b]++;
        ans[lca(a,b)]--;
        ans[fat[lca(a,b)]]--;
    }
    dfs2(1,0);
    int mx=0;
    for(int i=1;i<=n;++i)mx=max(mx,ans[i]);
    cout<<mx<<"\n";
    return 0;
}