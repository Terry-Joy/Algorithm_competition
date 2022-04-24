#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=1005;
int dp[1005][1026],head[maxn],ver[maxn<<1],next1[maxn<<1],tot,ans[1026],a[maxn],sz1[maxn],sz2[maxn],mxson[maxn],S,rt,ti=0,dfn[maxn],m,n;
bool v[maxn];
void add_edge(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void add(int&x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
void init1(){
    tot=0;
    for(int i=1;i<=n;++i)head[i]=0;
    for(int i=0;i<m;++i)ans[i]=0;
}
void getRoot(int x,int f){
    sz1[x]=1;mxson[x]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        getRoot(y,x);
        sz1[x]+=sz1[y];
        mxson[x]=max(mxson[x],sz1[y]);
    }
    mxson[x]=max(mxson[x],S-mxson[x]);
    if(mxson[x]<mxson[rt])rt=x;
}
void init(int x){
    S=sz1[x];
    mxson[rt=0]=maxn;
    getRoot(x,0);
}
void dfs(int x,int f){
    sz2[x]=1;dfn[++ti]=x;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        dfs(y,x);
        sz2[x]+=sz2[y];
    }
}
void cal(int x){//重心必选
    ti=0;
    dfs(x,0);
    for(int i=1;i<=ti;++i)
        for(int j=0;j<m;++j)dp[i][j]=0;
    dp[1][a[x]]=1;
    for(int i=1;i<ti;++i)
        for(int j=0;j<m;++j){
            add(dp[i+1][j^a[dfn[i+1]]],dp[i][j]);
            add(dp[i+sz2[dfn[i+1]]][j],dp[i][j]);
        }
    for(int i=0;i<m;++i)add(ans[i],dp[ti][i]);
}
void dfz(int x){
    v[x]=1;
    cal(x);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        init(y);
        dfz(rt);
    }
    v[x]=0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i)cin>>a[i];
        init1();
        int x,y;
        for(int i=1;i<n;++i){
            cin>>x>>y;
            add_edge(x,y);add_edge(y,x);
        }
        mxson[rt=0]=maxn;
        S=n;
        getRoot(1,0);
        dfz(rt);
        for(int i=0;i<m-1;++i){
            cout<<ans[i]<<" ";
        }
        cout<<ans[m-1]<<"\n";
    }
    return 0;
}