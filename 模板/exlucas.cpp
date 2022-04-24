//拓展卢卡斯定理:
//1<=m<=n<=1e18,2<=p<=1e6,不保证p是质数
//求C(n,m)%p
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll power(ll a,ll b,ll mod){
	ll res=1;
	a%=mod;
	while(b){
        if(b&1)
            res=res*a%mod;
        a=a*a%mod;b>>=1;
    }
    return res%mod;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){x=1;y=0;return a;}
    ll gcd=exgcd(b,a%b,x,y);
    ll tmp=x;x=y;y=tmp-(a/b)*y;
    return gcd;
}
ll get_inv(ll a,ll mod){//a关于mod的逆元，返回1/a，a与mod互素
	ll x,y;
    ll gcd=exgcd(a,mod,x,y);
	x=(x%mod+mod)%mod;
    if(x==0) x+=mod;
	return x;
}
ll Mul(ll n,ll pi,ll pk){
    if(!n) return 1;
    ll ans=1;
    if(n/pk){
         for(ll i=2;i<=pk;++i)
            if(i%pi) ans=ans*i%pk;
        ans=power(ans,n/pk,pk);
    }
    for(ll i=2;i<=n%pk;++i)
        if(i%pi) ans=ans*i%pk;
    return ans*Mul(n/pi,pi,pk)%pk;
}
ll C(ll n,ll m,ll mod,ll pi,ll pk){
    if(m>n) return 0;
    ll a=Mul(n,pi,pk),b=Mul(m,pi,pk),c=Mul(n-m,pi,pk);
    ll k=0,ans;
    for(ll i=n;i;i/=pi) k+=i/pi;
    for(ll i=m;i;i/=pi) k-=i/pi;
    for(ll i=n-m;i;i/=pi) k-=i/pi;
    ans=a*get_inv(b,pk)%pk*get_inv(c,pk)%pk*power(pi,k,pk)%pk;
    return ans*(mod/pk)%mod*get_inv(mod/pk,pk)%mod;
}
ll exLucas(ll n,ll m,ll mod)//C(n,m)%mod{
    ll ans=0,x=mod;
    for(ll i=2;i<=mod;i++){//对p进行质因子分解
        if(x%i==0){
            ll pk=1;
            while(x%i==0)
                pk*=i,x/=i;
            ans=(ans+C(n,m,mod,i,pk))%mod;
        }
    }
    if(x>1)
        ans=(ans+C(n,m,mod,x,x))%mod;
    return ans;
}
int main(){
    ll n,m,p;//求C(n,m)%p
    scanf("%lld%lld%lld",&n,&m,&p);
    printf("%lld\n",exLucas(n,m,p));
    return 0;
}