#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int head[maxn],ver[maxn<<1],next1[maxn<<1],dp[maxn],edge[maxn<<1],tot,deg[maxn],a,b,c,n,m,now;
void add(int x,int y,int z){ 
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x,int fa){ 
    if(deg[x]==1&&x!=now){ 
        dp[x]=0x3f3f3f3f;return;
    }
    for(int i=head[x];i;i=next1[i]){ 
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
        dp[x]+=min(dp[y],edge[i]);       //要么当前删要么子树删
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>now;
    for(int i=1;i<=m;++i){ 
        cin>>a>>b>>c;
        add(a,b,c);
        deg[a]++;
        add(b,a,c);
        deg[b]++;
    }
    dfs(now,-1);
    cout<<dp[now]<<"\n";
}

