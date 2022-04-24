#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
bool v[maxn];
int phi[maxn],prime[maxn],cnt=0,fac[maxn];
void init(){
    v[1]=phi[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
}
ll Phi(ll x){
    int ans=x;
    for(ll i=2;i*i<=x;++i){
        if(x%i==0){
            ans=ans*x/(x-1);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)ans=ans*(x-1)/x;
    return ans;
}
int main(){
    init();
    ll n;
    int m;
    while(~scanf("%lld",&n)){
        m=0;
        for(ll i=1;i*i<=n;++i){
            if(n%i==0){
                fac[++m]=i;
                if(i!=n/i)fac[++m]=n/i;
            }
        }
        ll ans=0;
        if(m==2){
            cout<<2*n-1<<"\n";
            continue;
        }
        for(int i=1;i<=m;++i){
            if(n/fac[i]<maxn)
                ans+=1ll*(phi[n/fac[i]])*fac[i];
            else
                ans+=1ll*Phi(n/fac[i])*fac[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}