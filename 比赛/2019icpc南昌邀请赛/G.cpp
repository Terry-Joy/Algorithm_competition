#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
ll f[maxn];
int sum[maxn],sum1,sum2;
int prime[maxn],num[maxn],low[maxn],cnt,n,t;
bool v[maxn];
const ll mod=(1ll<<30);
ll mypow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
ll phi(ll p,ll k){
    if(!k)return 1;
    return mypow(p,k-1)*(p-1)%mod;
}
void init(){
    ll sum1=0,sum2=0;
    for(int i=1;i<maxn;++i){
        sum1=(sum1+i)%mod;
        sum2=(sum2+1ll*i*i%mod)%mod;
        sum[i]=sum1*sum2%mod*i%mod;
    }
    f[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i]){
            prime[++cnt]=i,low[i]=i,num[i]=1;
            f[i]=1ll*i*i%mod*i%mod*(i-2)%mod;
        }
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            low[i*prime[j]]=prime[j];
            if(low[i]==prime[j])num[i*prime[j]]=num[i]+1;
            else num[i*prime[j]]=1;
            if(i%prime[j]==0){
                ll tmp=mypow(prime[j],num[i*prime[j]]);
                f[tmp]=(phi(prime[j],num[i*prime[j]])-phi(prime[j],num[i*prime[j]]-1))*tmp%mod*tmp%mod*tmp%mod;
                f[i*prime[j]]=f[i*prime[j]/tmp]*f[tmp]%mod;
                break;
            }else f[i*prime[j]]=f[i]*f[prime[j]]%mod;
        }
    }
    for(int i=1;i<maxn;++i)f[i]=(f[i-1]+f[i])%mod;
}
int main(){
    init();
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll ans=0;
        for(int i=1,j;i<=n;i=j+1){
            j=(n/(n/i));
            ans+=((f[j]-f[i-1])%mod+mod)%mod*sum[n/i]%mod;
        }
        cout<<(ans+mod)%mod<<"\n";
    }
    return 0;
}