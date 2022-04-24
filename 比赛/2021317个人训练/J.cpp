#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=3e5+5;
int n,m,col[maxn],sum1,sum2,ans;
bool f;
vector<int>G[maxn];
void dfs(int x,int co){
    if(col[x]==1)sum1++;
    else sum2++;
    for(auto&v:G[x]){
        if(!col[v]){
            col[v]=3-co;
            dfs(v,col[v]);
        }else{
            if(col[v]==co){
                f=0;return;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;++i){
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i=1;i<=n;++i){
        sum1=0,sum2=0;
        f=1;
        if(!col[i]){
            col[i]=1;
            dfs(i,1);
        }
        if(!f)break;
        ans+=min(sum1,sum2);
    }
    if(!f)cout<<"-1"<<"\n";
    else cout<<ans<<"\n";
    return 0;
}