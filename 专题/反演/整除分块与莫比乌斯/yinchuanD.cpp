#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=59964251;
const int phi=59870352;
int t,prime[maxn],cnt,mu[maxn];
ll m,d,k,sum[maxn];
char s[maxn];
bool v[maxn];
void init(){
    mu[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[prime[j]*i]=1;
            if(i%prime[j]==0)break;
            mu[i*prime[j]]=-mu[i];
        }
    }
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
int main(){
    init();
    scanf("%d",&t);
    while(t--){
        scanf("%s%lld%lld%lld",s,&m,&d,&k);
        m/=d;
        sum[0]=0;
        for(int i=1;i<=m;++i)
            sum[i]=(sum[i-1]+mypow(i,k))%mod;
        int len=strlen(s);
        ll n=0;
        for(int i=0;i<len;++i){//n在指数位置，拓展欧拉
            n=n*10+s[i]-'0';
            n%=phi;
        }
        ll ans=0;
        for(int i=1;i<=m;++i){
            ans=(ans+(mu[i]*mypow(i,k*n%phi+phi)%mod+mod)%mod*mypow(sum[m/i],n%phi+phi))%mod;
        }
        ans=ans*mypow(d,k*n%phi+phi)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
