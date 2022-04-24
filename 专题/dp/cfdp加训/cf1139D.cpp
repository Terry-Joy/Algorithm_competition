#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
int mu[maxn],prime[maxn],cnt;
vector<int>fac[maxn];
ll inv[maxn],dp[maxn];
bool v[maxn];
void init(){
    mu[1]=1;
    inv[0]=inv[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
            mu[i*prime[j]]=-mu[i];
        }
    }
    for(int i=1;i<maxn;++i){
        for(int j=i;j<maxn;j+=i)
            fac[j].pb(i);
    }
    for(int i=2;i<maxn;++i){
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
        mu[i]=(mu[i]+mod)%mod;
    }
}
int main(){
    init();
    int m;
    scanf("%d",&m);
    ll ans=m;
    for(int i=2;i<=m;++i){
        dp[i]=m;
        for(auto d:fac[i]){
            if(d==i)continue;
            ll s=0;
            for(auto t:fac[i/d]){
                s=(s+1ll*mu[t]*(m/(d*t)))%mod;
            }
            dp[i]=(dp[i]+dp[d]*s%mod)%mod;
        }
        dp[i]=dp[i]*inv[m-(m/i)]%mod;
        ans=(ans+dp[i])%mod;
    }
    cout<<ans*inv[m]%mod<<"\n";
    return 0;
}