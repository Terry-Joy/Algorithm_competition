#include<bits/stdc++.h>
#define pb push_back
#define fi first 
#define se second
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
ll *dp[maxn],tmp[maxn],*id=tmp,ans[maxn];
int sz[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],n,q,hson[maxn],md[maxn],dep[maxn],tot;
typedef pair<int,int>P;//dp[i][j]以i为根子树距离i>=j下,ab为c祖先，bc在a子树下的数量
vector<P>Q[maxn];
void dfs1(int x,int f){        
    dep[x]=dep[f]+1;sz[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs1(y,x);
        sz[x]+=sz[y];
        if(md[y]>md[hson[x]])hson[x]=y;
    }
    md[x]=md[hson[x]]+1;
}
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int f){
    dp[x][0]=sz[x]-1;
    if(hson[x]){//指针，长链直接赋值不用+=
        dp[hson[x]]=dp[x]+1;dfs(hson[x],x);dp[x][0]+=dp[hson[x]][0];//但>=0没统计
    }
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||y==hson[x])continue;
        dp[y]=id;id+=md[y];
        dfs(y,x);
        dp[x][0]+=dp[y][0];
        for(int j=0;j<md[y];++j)//后缀和维护
            dp[x][j+1]+=dp[y][j];
    }
    for(auto&v:Q[x]){//统计答案的时候减法获取需要答案即可
        ans[v.fi]+=1ll*(sz[x]-1)*min(dep[x]-1,v.se);
        if(v.se<md[x]-1)ans[v.fi]+=dp[x][0]-dp[x][v.se+1]-(sz[x]-1);
        else ans[v.fi]+=dp[x][0]-(sz[x]-1);
    }
}
int main(){
    scanf("%d%d",&n,&q);
    int u,v;
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    dfs1(1,0);
    dp[1]=id;id+=md[1];
    for(int i=1;i<=q;++i){
        scanf("%d%d",&u,&v);
        Q[u].pb({i,v});
    }
    dfs(1,0);
    for(int i=1;i<=q;++i)cout<<ans[i]<<"\n";
    return 0;
}