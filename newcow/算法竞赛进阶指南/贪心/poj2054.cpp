#include<bits/stdc++.h>
#define pb push_back
using namespace std;
struct Node{ 
    int c1,sum,id;
    bool operator<(const Node&a)const{ 
        return sum>a.sum;
    }
};
const int maxn=1005;
vector<int>G[maxn];
int n,sum[maxn],c[maxn],rt,ans=0;
priority_queue<Node>q;
void bfs(int x){ 
    int cnt=0;
    q.push({c[x],sum[x],x});
    while(!q.empty()){ 
        Node ed=q.top();
        q.pop();
        if(cnt==0){ 
            ans+=ed.c1;cnt++;
        }else ans+=cnt*ed.c1;
        for(auto&v:G[ed.id]){ 
            q.push({c[v],sum[v],v});
        }
    }
}
void dfs(int x){ 
    for(auto&v:G[x]){ 
        dfs(v);
        sum[x]+=sum[v];
    }
}
int main(){ 
    int a,b;
    while(~scanf("%d%d",&n,&rt)){ 
        ans=0;
        while(!q.empty())q.pop();
        for(int i=1;i<=n;++i)G[i].clear();
        if(!n&&rt==0)break;
        for(int i=1;i<=n;++i)scanf("%d",&c[i]),sum[i]=c[i];
        ans+=c[rt];
        for(int i=1;i<=n-1;++i){ 
            scanf("%d%d",&a,&b);
            G[a].pb(b);
        }
        dfs(rt);
        bfs(rt);
        cout<<ans<<"\n";
    }
    return 0;
}
