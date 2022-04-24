#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int n,L,w[maxn],fa[maxn][20],lg[maxn],d[maxn],ans[maxn],dp[maxn],len[maxn];
ll S,sum[maxn];
vector<int>G[maxn];
void dfs(int x,int f){
    sum[x]=w[x]+sum[f];
    d[x]=d[f]+1;
    for(int i=1;i<=lg[d[x]];++i)fa[x][i]=fa[fa[x][i-1]][i-1];
    for(auto&v:G[x]){
        dfs(v,x);
    }
}
void dfs2(int x){
    int mx=0;
    for(auto&v:G[x]){
        dfs2(v);
        ans[x]+=ans[v];
        mx=max(mx,dp[v]);    
    }
    if(!mx)ans[x]++,dp[x]=len[x];
    else dp[x]=mx-1;
}
int main(){
    scanf("%d%d%lld",&n,&L,&S);
    int mx=0;
    for(int i=1;i<=n;++i)scanf("%d",&w[i]),mx=max(mx,w[i]);
    if(mx>S){
        puts("-1");return 0;
    }
    for(int i=1;i<=n;++i)lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=2;i<=n;++i){
        scanf("%d",&fa[i][0]);
        G[fa[i][0]].pb(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i){
        int x=i;
        for(int j=lg[d[i]];j>=0;--j){
            if(!fa[x][j])continue;//是x!!
            if(d[i]-d[fa[x][j]]+1<=L&&sum[i]-sum[fa[fa[x][j]][0]]<=S)
                x=fa[x][j];
        }
        len[i]=d[i]-d[x];
    }
    dfs2(1);
    cout<<ans[1]<<"\n";
    return 0;
}