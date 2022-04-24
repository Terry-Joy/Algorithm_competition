#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
const int INF=0x3f3f3f3f;
int dp[maxn][maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],edge[maxn<<1],tot,sz[maxn],val[maxn],n,m;
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
void dfs(int x,int f){
    if(x>n-m){
        sz[x]=1;
        dp[x][1]=val[x];return;
    }
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs(y,x);
        for(int j=sz[x];j>=0;--j)
            for(int k=sz[y];k>=0;--k){
                dp[x][j+k]=max(dp[x][j+k],dp[x][j]+dp[y][k]-edge[i]);
            }
        sz[x]+=sz[y];
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int k,a,b;
    for(int i=1;i<=n-m;++i){
        scanf("%d",&k);
        for(int j=1;j<=k;++j){
            scanf("%d%d",&a,&b);
            add(i,a,b);
            add(a,i,b);
        }
    }
    for(int i=n-m+1;i<=n;++i){
        scanf("%d",&val[i]);
    }
    for(int i=1;i<=n;++i)
        for(int j=0;j<=m;++j)dp[i][j]=-INF; 
    for(int i=1;i<=n;++i)dp[i][0]=0;
    dfs(1,0);
    for(int i=m;i>=0;--i){
        if(dp[1][i]>=0){
            cout<<i<<"\n";
            break;
        }
    }       
    return 0;
}