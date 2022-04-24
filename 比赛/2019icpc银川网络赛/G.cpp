#include<bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
using ll=long long;
typedef pair<int,int>Edge;
const int maxn=1e5+10;
int n,k,t,deg[maxn],sz[maxn];
ll dp[maxn][103];
vector<Edge>G[maxn];
void dfs(int x,int fa){ 
    dp[x][0]=0;
    for(auto [v,w]:G[x]){ 
        if(v==fa)continue;
        dfs(v,x);
        for(int i=min(sz[x],k);i>=0;--i){ 
            for(int j=min(k-i,sz[v]);j>=0;--j){ 
                dp[x][i+j]=min(dp[x][i+j],dp[x][i]+dp[v][j]+(ll)w*j*(k-j));
            }
        }
        sz[x]+=sz[v];
    }	
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    int T=0;
    while(t--){ 
        cin>>n>>k;
        int u,v,w;
        for(int i=1;i<n;++i){ 
            cin>>u>>v>>w;
            deg[u]++;
            deg[v]++;
            G[u].eb(make_pair(v,w));
            G[v].eb(make_pair(u,w));
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=k;++j)dp[i][j]=1e18;
        for(int i=1;i<=n;++i){ 
            sz[i]=0;
            if(deg[i]==1)
                sz[i]=1,dp[i][1]=0;
        }
        dfs(1,0);
        for(int i=1;i<=n;++i)deg[i]=0,G[i].clear();
        cout<<"Case #"<<++T<<": "<<dp[1][k]<<"\n";
    }
    return 0;
}
