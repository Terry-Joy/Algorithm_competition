#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
const ll mod=1e9+7;
const int maxn=1e6+5;
ll fac[maxn],facinv[maxn],pre[maxn],suf[maxn],a[maxn],S[maxn];
ll mypow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
struct Lglr{
    void init(){
        fac[1]=fac[0]=1;
        for(int i=2;i<maxn;++i)fac[i]=fac[i-1]*i%mod;
        facinv[maxn-1]=mypow(fac[maxn-1],mod-2);
        for(int i=maxn-2;i>=0;--i)
            facinv[i]=facinv[i+1]*(i+1)%mod;
    }
    ll cal(ll x,ll*a,int up){ //[0,n] 求n次多项式第x项值
        if(x<=up)return a[x];
        pre[0]=x;suf[up+1]=1;
        for(int i=1;i<=up;++i)pre[i]=pre[i-1]*(x-i)%mod;
        for(int i=up;i>=0;--i)suf[i]=suf[i+1]*(x-i)%mod;
        ll ans=0;
        for(int i=0;i<=up;++i){
            ll f=facinv[up-i]*facinv[i]%mod;
            f=(up-i)&1?-f:f;
            ans=(ans+a[i]*f%mod*(i==0?1:pre[i-1])%mod*suf[i+1]%mod)%mod;
            ans=(ans%mod+mod)%mod;//判断范围卡常
        }
        return ans;
    }
    ll kSum(int n,int k,ll*a){//自然数前n项k次幂和 i=(1,n) i^k求和
        init();
        for(int i=1;i<=k+1;++i){
            a[i]=(a[i-1]+mypow(i,k))%mod; 
        }
        return cal(n,a,k+1);
    }
}lglr;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k+1;++i){
        a[i]=(a[i-1]+mypow(i,k))%mod;
    }
    lglr.init();
    cout<<lglr.cal(n,a,k+1)<<"\n";
    return 0;
}