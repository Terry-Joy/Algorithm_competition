#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2005;
ll dp[maxn][maxn];
int head[maxn],ver[maxn<<1],next1[maxn<<1],edge[maxn<<1],tot,n,k,sz[maxn];
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
void dfs(int x,int f){
    sz[x]=1;
    dp[x][0]=dp[x][1]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs(y,x);
        for(int j=min(sz[x],k);j>=0;--j)
            for(int d=min(sz[y],k-j);d>=0;--d){//d==0的时候取最大值直接更新了
                    if(dp[x][j]==-1||dp[y][d]==-1)continue;
                    dp[x][j+d]=max(dp[x][j+d],dp[x][j]+dp[y][d]+1ll*(d*(k-d)+(n-k-(sz[y]-d))*(sz[y]-d))*edge[i]);
            }
        sz[x]+=sz[y];
    }
}
int main(){
    scanf("%d%d",&n,&k);
    int u,v,w;
    for(int i=1;i<n;++i)scanf("%d%d%d",&u,&v,&w),add(u,v,w),add(v,u,w);
    for(int i=1;i<=n;++i)
        for(int j=0;j<=k;++j)
            dp[i][j]=-1;
    dfs(1,0);
    cout<<dp[1][k]<<"\n";
    return 0;
}