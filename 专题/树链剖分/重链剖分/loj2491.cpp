#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;   
const int mod=998244353;
int f[maxn][22],dp[maxn][52],head[maxn],ver[maxn<<1],next1[maxn<<1],tot,lg[maxn],d[maxn],fat[maxn],n,m;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
int mypow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return ans;
}
void dfs(int x,int fa){
    d[x]=d[fa]+1;
    f[x][0]=fa;
    fat[x]=fa;
    for(int i=1;i<=50;++i)
        dp[x][i]=(dp[fa][i]+mypow(d[x]-1,i))%mod;
    for(int i=1;i<=lg[d[x]];++i)
        f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
    }
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y])
        x=f[x][lg[d[x]-d[y]]-1];
    if(x==y)return x;
    for(int i=lg[d[y]]-1;i>=0;--i)
        if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main(){
    scanf("%d",&n);
    int a,b,k;
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;++i)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    dfs(1,0);
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&a,&b,&k);
        int LCA=lca(a,b);
        cout<<((dp[a][k]+dp[b][k]-dp[LCA][k]-dp[fat[LCA]][k])%mod+mod)%mod<<"\n";
    }
    return 0;
}