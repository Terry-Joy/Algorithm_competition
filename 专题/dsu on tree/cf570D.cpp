#include<bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int>P;
const int maxn=5e5+5;
vector<P>Q[maxn];
int son[maxn],sz[maxn],dep[maxn],ver[maxn<<1],next1[maxn<<1],head[maxn],tot,hs,cnt[maxn],n,m,a[maxn],ans[maxn];
char s[maxn];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int f){
    sz[x]=1;dep[x]=dep[f]+1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs(y,x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]])son[x]=y;
    }
}
void cal(int x,int f){
    cnt[dep[x]]^=(1<<a[x]);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==hs)continue;
        cal(y,x);
    }
}
bool ok(int x){
    return (x==(x&(-x)));
}
void dsu(int x,int f,bool op){
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==son[x])continue;
        dsu(y,x,0);
    }
    if(son[x])dsu(son[x],x,1),hs=son[x];
    cal(x,f);
    for(auto&v:Q[x]){
        if(ok(cnt[v.se]))ans[v.fi]=1;
    }
    hs=0;
    if(!op)cal(x,f);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int x,y;
    for(int i=2;i<=n;++i){
        cin>>x;
        add(i,x);add(x,i);
    }
    cin>>(s+1);
    for(int i=1;i<=n;++i){
        a[i]=s[i]-'a';
    }
    for(int i=1;i<=m;++i){
        cin>>x>>y;
        Q[x].pb({i,y});
    }
    dfs(1,0);
    dsu(1,0,0);
    for(int i=1;i<=m;++i){
        cout<<(ans[i]?"Yes":"No")<<"\n";
    }
    return 0;
}