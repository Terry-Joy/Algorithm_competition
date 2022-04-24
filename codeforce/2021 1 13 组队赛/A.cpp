#include<bits/stdc++.h>

using namespace std;
const int maxn=5005;
const int INF=0x3f3f3f3f;
int dp[maxn][maxn],g[maxn][maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],tot,n;
void add(int x,int y){ 
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int fa){
    for(int i=head[x];i;i=next1[i]){ 
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
        for(int j=1;j<=n;++j)g[x][j]+=g[y][j-1];
    }
    dp[x][n]=g[x][0]=INF;
    for(int i=n-1;i>=0;--i){ 
        if(!i)dp[x][i]=min(1+g[x][2],dp[x][i+1]);
        else 
        dp[x][i]=min(i+g[x][i+1],dp[x][i+1]);
        for(int j=head[x];j;j=next1[j]){ 
            int y=ver[j];
            if(y==fa)continue;
            dp[x][i]=min(dp[x][i],dp[y][i+1]-g[y][i]+g[x][i+1]);
        }
    }
    g[x][0]=dp[x][0];
    for(int i=1;i<=n;++i)g[x][i]=min(g[x][i],g[x][i-1]);
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>n;
    for(int i=1;i<=n-1;++i){ 
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1,-1);
    cout<<g[1][0];
    return 0;
}
