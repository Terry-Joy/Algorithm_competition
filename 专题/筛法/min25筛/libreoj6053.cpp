#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxm=2e5+5;
ll g1[maxm],g2[maxm],w[maxm],prime[maxn],sum1[maxn],sum2[maxn],n;
int m,cnt,sqr,id1[maxm],id2[maxm];
bool v[maxn];
void init(){
    v[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,sum1[cnt]=(sum1[cnt-1]+i)%mod,sum2[cnt]=(sum2[cnt-1]+1);
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
ll S(ll x,int j){
    if(prime[j]>=x)return 0;
    int t=((x<=sqr)?id1[x]:id2[n/x]);
    ll ans=((g1[t]-g2[t])+mod-(sum1[j]-sum2[j]))%mod;
    for(int i=j+1;i<=cnt&&prime[i]*prime[i]<=x;++i){
        ll sp=prime[i];
        for(int e=1;sp<=x;sp*=prime[i],++e){
            ans=(ans+(prime[i]^e)%mod*(S(x/sp,i)+(e>1)))%mod;
        }
    }
    return ans;
}
int main(){ 
    init();
    scanf("%lld",&n);
    if(n==1){puts("1");return 0;}
    sqr=sqrt(n+0.5);
    for(ll i=1,j;i<=n;i=j+1){
        j=n/(n/i);
        w[++m]=n/i;
        g1[m]=w[m]%mod;
        g2[m]=w[m]-1;
        g1[m]=g1[m]*(g1[m]+1)%mod*((mod+1)/2)%mod-1;
        if(w[m]<=sqr)id1[w[m]]=m;
        else id2[j]=m;
    }
    for(int i=1;i<=cnt;++i){
        ll pr=prime[i]*prime[i];
        for(int j=1;j<=m&&pr<=w[j];++j){
            ll x=w[j]/prime[i];
            x=((x<=sqr)?id1[x]:id2[n/x]);
            g1[j]=(g1[j]-prime[i]*(g1[x]-sum1[i-1])%mod+mod)%mod;
            g2[j]=(g2[j]-(g2[x]-sum2[i-1])%mod+mod)%mod;
        }
    }
    printf("%lld",(S(n,0)+3)%mod);
    return 0;
}
