#include<bits/stdc++.h>

using namespace std;
const int maxn=105;
int head[maxn],next1[maxn<<1],ver[maxn<<1],edge[maxn<<1],tot,sz[maxn];
int n,m,dp[maxn][maxn];
void add(int x,int y,int z){ 
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int fa){ 
    for(int i=head[x];i;i=next1[i]){ 
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
        sz[x]+=sz[y]+1;
        for(int j=min(sz[x],m);j>=0;--j)
            for(int k=0;k<=min(j-1,sz[y]);++k)
                dp[x][j]=max(dp[x][j],dp[x][j-k-1]+dp[y][k]+edge[i]);//dp[x][0]已经默认为0了,转移不到也没关系
    }
}
int main(){ 
    scanf("%d%d",&n,&m);
    int a,b,c;
    for(int i=1;i<=n-1;++i){ 
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,-1);
    cout<<dp[1][m]<<endl;
    return 0;
}
