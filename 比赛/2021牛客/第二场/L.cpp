#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=2e5+5;
const int INF=2e9;
vector<int>G[maxn],B[maxn];
vector<pair<int,int>>W[maxn/10];
int big,n,m,q,a[maxn],ans[maxn];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    big=sqrt(1.4*m);
    int x,y;
    for(int i=1;i<=m;++i){ 
        scanf("%d%d",&x,&y);
        G[x].pb(y);G[y].pb(x);
    }
    for(int i=1;i<=n;++i){ 
        if(G[i].size()>=big){ 
            for(auto&v:G[i]){ 
                B[v].pb(i);
            }
        }
    }
    for(int i=1;i<=q;++i){ 
        scanf("%d%d",&x,&y);
        a[x]+=y;
        W[a[x]].pb({x,i});
    }
    vector<int>now(n+5,q),pre(n+5,q),mn(n+5,q);
    for(int w=1e4;w>=1;--w){ 
        for(auto&[u,t]:W[w]){ 
            for(auto&v:B[u]){ 
                mn[v]=min(mn[v],t);
            }
            pre[u]=now[u];now[u]=t;
        }
        for(auto&[u,t]:W[w]){ 
            if(G[u].size()<big){ 
                int mx=INF;
                for(auto&v:G[u]){ 
                    mx=min(now[v],mx);
                }
                ans[u]+=max(0,min(mx,pre[u])-t);
            }else
                ans[u]+=max(0,min(mn[u],pre[u])-t);
        }
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<"\n";
    return 0;
}
