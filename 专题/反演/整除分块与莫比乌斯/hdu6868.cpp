#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
int prime[maxn/10],f[maxn],g[maxn],cnt,t,n,m,ans[10005];
const int mod=1e9+7;
bool vis[maxn];
struct Node{
    int id,K,M,val;
    bool operator<(const Node&a){
        if(K==a.K)return M<a.M;
        else return K<a.K;
    }
};
vector<Node>G;
void init(){
    f[1]=g[1]=1;
    for(int i=2;i<=maxn-5;++i){
        if(!vis[i])prime[++cnt]=i,f[i]=2,g[i]=mod-(mod+1)/2;
        for(int j=1;j<=cnt&&prime[j]*i<=maxn-5;++j){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                f[i*prime[j]]=f[i];
                break;
            }
            f[i*prime[j]]=2*f[i]%mod;
            g[i*prime[j]]=1ll*g[prime[j]]*g[i]%mod;
        }
    }
}
int main(){
    init();
    scanf("%d",&t);
    for(int i=1;i<=t;++i){
        scanf("%d%d",&n,&m);
        vector<int>pri;
        int x1=n;
        for(int j=1;prime[j]*prime[j]<=n;++j){
            if(x1%prime[j]==0){
                pri.push_back(prime[j]);
                while(x1%prime[j]==0)x1/=prime[j];
            }
        }
        if(x1>1)pri.push_back(x1);
        int sz=(1<<pri.size());
        for(int k=0;k<sz;++k){
            int sum=1;
            for(int j=0;j<pri.size();++j){
                if(k&(1<<j))
                    sum*=pri[j];
            }
            if(sum>m||(g[sum]==0))continue;
            G.push_back({i,sum,(m/sum)*sum,int(1ll*f[n]*g[sum]%mod)});
        }
    }
    sort(G.begin(),G.end());
    ll val,K=0,M,i=0;
    for(auto&v:G){
        if(K!=v.K)
            K=i=v.K,val=0;
        for(;i<=v.M;i+=K)
            val+=f[i];
        ans[v.id]=(ans[v.id]+1ll*(v.val)%mod*val%mod)%mod;
    }
    for(int i=1;i<=t;++i)
        printf("%d\n",ans[i]);
    return 0;
}