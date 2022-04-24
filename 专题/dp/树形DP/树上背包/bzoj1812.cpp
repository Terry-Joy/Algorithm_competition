#include<bits/stdc++.h>
using namespace std;
const int INF=2e9+1;
const int maxn=105;
int dp[maxn][maxn][maxn][2],d[maxn],val[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],edge[maxn<<1],sz[maxn],st[maxn],tot,n,k,cnt;
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
void dfs(int x){
    st[++cnt]=x;
    sz[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        d[y]=d[x]+edge[i];
        dfs(y);
        sz[x]+=sz[y];
        for(int f=1;f<=cnt;++f){
            int fa=st[f];
            for(int j=min(sz[x],k);j>=0;--j){
                for(int e=0;e<=min(sz[y],j);++e){
                    if(!e){
                        dp[x][fa][j][0]+=dp[y][fa][e][0];
                        if(j)
                           dp[x][fa][j][1]+=dp[y][x][e][0];
                    }else{
                        dp[x][fa][j][0]=min(dp[x][fa][j][0],dp[x][fa][j-e][0]+dp[y][fa][e][0]);//此时子节点0/1已经合并
                        if(j&&(j-e))
                        dp[x][fa][j][1]=min(dp[x][fa][j][1],dp[x][fa][j-e][1]+dp[y][x][e][0]);
                    }
                }
            }
        }
    }
    for(int f=1;f<=cnt;++f){
        int fa=st[f];
        for(int j=min(sz[x],k);j>=0;--j){
                dp[x][fa][j][0]=dp[x][fa][j][0]+val[x]*(d[x]-d[fa]);
                if(j)
                    dp[x][fa][j][0]=min(dp[x][fa][j][0],dp[x][fa][j][1]);
        }
    }
    cnt--;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        int fa,z;
        scanf("%d%d%d",&val[i],&fa,&z);
        add(fa,i,z);
    }
    dfs(0);
    cout<<dp[0][0][k][0]<<'\n';
    return 0;
}