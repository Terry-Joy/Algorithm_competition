#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=1e6+5;
const int maxn=1e5+5;
ll ans=0;
int cnt[maxm+maxn][20][2],head[maxn],ver[maxn<<1],next1[maxn<<1],sz[maxn],tot,son[maxn],a[maxn],n,hs;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int f){
    sz[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs(y,x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]])son[x]=y;
    }
}
void solve(int x,int f,int rt){
    int now=a[rt]^a[x];
    for(int i=0;i<=19;++i)ans+=1ll*cnt[now][i][!((x>>i)&1)]*(1<<i);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        solve(y,x,rt);
    }
}
void update(int x,int f,int val){
    for(int i=0;i<=19;++i)
        cnt[a[x]][i][(x>>i)&1]+=val;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        update(y,x,val);
    }
}
void cal(int x,int f,int val){
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==hs)continue;
        if(val==1)solve(y,x,x);//子树间贡献得先算答案再更新
        update(y,x,val);
    }
    for(int i=0;i<=19;++i)
        cnt[a[x]][i][(x>>i)&1]+=val;
}
void dsu(int x,int f,bool op){
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==son[x])continue;
        dsu(y,x,0);
    }
    if(son[x])dsu(son[x],x,1),hs=son[x];
    cal(x,f,1);
    hs=0;
    if(!op)cal(x,f,-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    int x,y;
    for(int i=1;i<n;++i){
        cin>>x>>y;
        add(x,y);add(y,x);
    }
    dfs(1,0);
    dsu(1,0,0);
    cout<<ans<<"\n";
    return 0;
}