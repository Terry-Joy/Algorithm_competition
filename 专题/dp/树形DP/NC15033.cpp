#include<bits/stdc++.h>

using namespace std;
const int maxn=1010;
const int INF=0x3f3f3f3f;
vector<int>G[maxn];
int sz[maxn],mx[maxn],ans=INF;
    int n,a,b;
void dfs(int x,int fa){ 
    sz[x]=1;
    for(auto&v:G[x]){ 
        if(v!=fa){ 
            dfs(v,x);
            sz[x]+=sz[v];
            mx[x]=max(mx[x],sz[v]);
        }
    }
    mx[x]=max(mx[x],n-sz[x]);
    ans=min(ans,mx[x]);
}
int main(){ 
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i){ 
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);    
    }
    dfs(1,-1);
    int i;
    for(i=1;i<=n;++i){ 
        if(mx[i]==ans)
            break;  
    }
    cout<<i<<" "<<ans<<endl;
    return 0;
}
