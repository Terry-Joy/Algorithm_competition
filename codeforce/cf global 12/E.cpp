#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=205;
const int INF=0x3f3f3f3f;
vector<int>G[maxn];
int dis[maxn][maxn],n,m,a,b,op,val[maxn];
bool flag=0;
bool floyd(){ 
    for(int k=1;k<=n;++k){ 
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    for(int i=1;i<=n;++i)
        if(dis[i][i]<0)return 0;
    return 1;
}
void dfs(int x,int clo){ 
    val[x]=clo;
    for(auto&v:G[x]){ 
        if(!val[v]){ 
            dfs(v,3-clo);
        }else{ 
            if(val[v]==val[x])flag=1;
        }
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){ 
            if(i!=j)dis[i][j]=INF;
        }
    for(int i=1;i<=m;++i){ 
        cin>>a>>b>>op;
        G[a].pb(b);
        G[b].pb(a);
        if(op){ 
            dis[a][b]=1;
            dis[b][a]=-1;
        }else{ 
            dis[a][b]=1;
            dis[b][a]=1;
        }
    }
    dfs(1,1);
    if(!floyd()||flag)
        cout<<"NO"<<"\n";
    else{ 
        int mx=-1;
        int pos=-1;
        for(int i=1;i<=n;++i){ 
            for(int j=1;j<=n;++j){ 
                if(mx<dis[i][j]){ 
                    mx=dis[i][j];
                    pos=i;
                }
            }
        }
        cout<<"YES"<<"\n";
        cout<<mx<<"\n";
        for(int i=1;i<=n;++i)
            cout<<dis[pos][i]<<" ";
    }
    return 0;
}
