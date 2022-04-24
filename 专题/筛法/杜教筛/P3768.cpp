#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=2175;
const int maxn=5e6+5;
ll phi[maxn],phiS2[maxm],inv4,inv6,inv2;
bool v[maxn],visphi[maxm];
int prime[maxn],cnt;
ll N,mod;
void init(){
    phi[1]=1;
    for(int i=2;i<=maxn-5;++i){
        if(!v[i])prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&prime[j]*i<=maxn-5;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;   
            }
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    for(int i=2;i<=maxn-5;++i)
        phi[i]=(phi[i-1]+phi[i]*i%mod*i%mod)%mod;
}
ll mypow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
ll S1(ll n){//i^2
    n%=mod;
    return n*(n+1)%mod*(2*n+1)%mod*inv6%mod;
}   
ll S2(ll n){//i^3
    n%=mod;
    return n*n%mod*(n+1)%mod*(n+1)%mod*inv4%mod;
}
ll S3(ll n){//i^2
    n%=mod;
    return n*(n+1)%mod*inv2%mod;
}
ll phiS(ll n){
    if(n<=maxn-5)return phi[n];
    int x=N/n;
    if(visphi[x])return phiS2[x];
    visphi[x]=1;
    ll&ans=phiS2[x]; 
    ll sum=0;
    for(ll i=2,j;i<=n;i=j+1){
        j=n/(n/i);
        sum+=(((S1(j)-S1(i-1))+mod)%mod*phiS(n/i)%mod);
        sum%=mod;
    }
    return ans=(S2(n)-sum+mod)%mod;
}
int main(){
    cnt=0;
    scanf("%lld%lld",&mod,&N);
    init();
    inv2=mypow(2,mod-2);
    inv4=mypow(4,mod-2);
    inv6=mypow(6,mod-2);
    ll sum=0;
    for(ll i=1,j;i<=N;i=j+1){
        j=(N/(N/i));
        sum=(sum+S2(N/i)%mod*(phiS(j)-phiS(i-1)+mod)%mod+mod)%mod;
    }
    printf("%lld\n",sum);
    return 0;
}
