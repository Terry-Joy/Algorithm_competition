
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int maxm=6e4+5;
const int mod=1e9+7;
vector<int>G[maxn];
ll sz[maxn],p[maxm];
int n;
ll a[maxn],cnt;
void dfs(int now,int fa){
    sz[now]=1;
    for(auto&v:G[now]){
        if(v==fa)continue;
        dfs(v,now);
        sz[now]+=sz[v];
        a[++cnt]=1ll*(n-sz[v])*sz[v];
    }
}
int main(){
    int t,as,b,m;
    scanf("%d",&t);
    while(t--){
        cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)G[i].clear();
        for(int i=1;i<n;++i){
            scanf("%d%d",&as,&b);
            G[as].push_back(b);
            G[b].push_back(as);
        }
        dfs(1,0);
        sort(a+1,a+n);
        scanf("%d",&m);
        for(int i=1;i<=m;++i)scanf("%lld",&p[i]);
        sort(p+1,p+1+m);
        ll ans=0;
        if(m<n-1){
            for(int i=m,j=n-1;i>=1;--i,--j){
                ans=(ans+1ll*a[j]%mod*p[i]%mod)%mod;
            }
            for(int i=n-m-1;i>=1;--i)
                ans=(ans+a[i])%mod;
        }
        else{
            for(int i=m;i>=n;--i)
                p[n-1]=(1ll*p[n-1]%mod*p[i]%mod)%mod;
            for(int i=n-1,j=n-1;i>=1;--i,--j)
                ans=(ans+1ll*a[i]%mod*p[j]%mod)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}