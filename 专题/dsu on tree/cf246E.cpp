#include<bits/stdc++.h>
#define pb push_back
#define fi first 
#define se second
using namespace std;
const int maxn=1e6+5;
unordered_map<string,int>mp[maxn];
int sum[maxn],n,m,head[maxn],next1[maxn<<1],ver[maxn<<1],tot,vi,ki,dep[maxn],sz[maxn],son[maxn],hs,ans[maxn],fa[maxn];
string s[maxn];
vector<pair<int,int> >Q[maxn];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int f){
    dep[x]=dep[f]+1,sz[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs(y,x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]])son[x]=y;
    }
}
void cal(int x,int f,int val){
    if(!mp[dep[x]][s[x]])sum[dep[x]]++;
    mp[dep[x]][s[x]]+=val;
    if(!mp[dep[x]][s[x]])sum[dep[x]]--;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==hs)continue;
        cal(y,x,val);
    }
}
void dsu(int x,int f,bool op){
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==son[x])continue;
        dsu(y,x,0);
    }
    if(son[x])dsu(son[x],x,1),hs=son[x];
    cal(x,f,1);
    for(auto&v:Q[x]){
        ans[v.fi]=sum[v.se];
    }
    hs=0;
    if(!op)cal(x,f,-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int a;
    for(int i=1;i<=n;++i){
        cin>>s[i]>>fa[i];
        if(fa[i])add(fa[i],i);
    }
    for(int i=1;i<=n;++i)
        if(!fa[i])
            dfs(i,0);
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>vi>>ki;
        Q[vi].pb({i,ki+dep[vi]});
    }
    for(int i=1;i<=n;++i)
        if(!fa[i])
        dsu(i,0,0);
    for(int i=1;i<=m;++i)cout<<ans[i]<<"\n";
    return 0;
}