#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e6+15;
ll a[maxn],fac[maxn],facinv[maxn],pre[maxn],suf[maxn];
int t;
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
    //给定(0,f0)...(up,fup)求 up次多项式 f(x)的值 O(n)
    ll cal(ll x,ll*a,int up){//pre往偏移一位
        if(x<=up)return a[x];
        pre[0]=1;suf[up+1]=1;
        for(int i=0;i<=up;++i)pre[i+1]=(x-i)%mod*pre[i]%mod;
        for(int i=up;i>=0;--i)suf[i]=(x-i)%mod*suf[i+1]%mod;
        ll ans=0;
        for(int i=0;i<=up;++i){
            ll f=a[i]*pre[i]%mod*suf[i+1]%mod*facinv[i]%mod*facinv[up-i]%mod;
            if((up-i)&1)ans=(ans-f+mod)%mod;
            else ans=(ans+f)%mod;
        }
        return ans;
    }
    //给定n+1个点，求n次多项式f(k)的值 O(n^2)
    ll inv(int x){return mypow(x,mod-2);}
    ll cal2(ll k,ll*x,ll*y){
        for(int i=0;i<=n;++i)cin>>x[i]>>y[i];
        ll ans=0;
        for(int i=0;i<=n;++i){
            ll zi=y[i],mu=1;
            for(int j=0;j<=n;++j){
                if(i!=j){
                    zi=zi*(k-x[j])%mod;
                    mu=mu*(x[i]-x[j])%mod;
                }
            }
            ans=(ans+zi*inv(mu)%mod)%mod;
        }
        return (ans+mod)%mod;
    }

     //O(n^2)求多项式系数 O(n)单点求f(k)
    ll a[maxn], b[maxn], c[maxn], temp[maxn];
    ll x[maxn], y[maxn];
    int n;
    void mul(ll *f, int len, ll t) { //len为多项式的次数+1，函数让多项式f变成f*(x+t)
        for (int i = len; i > 0; --i)
            temp[i] = f[i], f[i] = f[i - 1];
        temp[0] = f[0], f[0] = 0;
        for (int i = 0; i <= len; ++i)
            f[i] = (f[i] + t * temp[i]) % mod;
    }
    void dev(ll *f, ll *r, ll t) { //f是被除多项式的系数，r保存f除以x+t的结果
        for (int i = 0; i <= n; ++i)
            temp[i] = f[i];
        for (int i = n; i > 0; --i) {
            r[i - 1] = temp[i];
            temp[i - 1] = (temp[i - 1] - t * temp[i]) % mod;
        }
    }
    void lglr() {
        memset(a, 0, sizeof a);
        b[1] = 1, b[0] = -x[1];
        for (int i = 2; i <= n; ++i) {
            mul(b, i, -x[i]);
        }//预处理(x-x1)*(x-x2)...*(x-xn)
        for (int i = 1; i <= n; ++i) {
            ll fz = 1;
            for (int j = 1; j <= n; ++j) {
                if (j == i)
                    continue;
                fz = fz * (x[i] - x[j]) % mod;
            }
            fz = qpow(fz, mod - 2);
            fz = fz * y[i] % mod; //得到多项式系数
            dev(b, c, -x[i]);//得到多项式，保存在c数组
            for (int j = 0; j < n; ++j)
                a[j] = (a[j] + fz * c[j]) % mod;
        }
    }
    ll sum(){//n点n-1次多项式
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        scanf("%lld%lld", &x[i], &y[i]);
        lglr();
        ll ans = 0,res=1;
        for (int i = 0; i < n; ++i) {
            ans = (ans + res * a[i]) % mod;
            res = res * k % mod;
        }
        return (ans+mod)%mod;
    }
}lglr;
ll cal(ll L,ll R,int a){
    ll sum1 = (R-a)/4;
    if(R >= a) sum1++;
    ll sum2 = (L-1-a)/4;
    if(L-1 >= a) sum2++;
    return (sum1-sum2)%mod;
}
ll solve(ll t,ll x,ll y){
    ll ans=0;
    ans += cal(x,y,2);
    ans += t*cal(x,y,1);
    ans += t/2*cal(x,y,3);
    return ans % mod;
}
int main(){
    lglr.init();
    ll x,y;
    scanf("%d%lld%lld",&t,&x,&y);
    for(int i=1;i<=t+1;++i){
        a[i]=(mypow(2*i,t+1)-2*i+mod)%mod*mypow(2*i-1,mod-2)%mod+a[i-1];
        a[i]%=mod;
    }
    ll ans=lglr.cal(y/2,a,t+1)-lglr.cal((x+1)/2-1,a,t+1);
    ans=(ans%mod+mod)%mod;
    ans=(ans+solve(t,x,y))%mod;
    cout<<(ans%mod+mod)%mod<<"\n";
    return 0;
}