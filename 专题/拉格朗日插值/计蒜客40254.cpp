#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1005;
const ll mod=9999991;
ll fac[maxn],facinv[maxn],pre[maxn],suf[maxn],a[maxn],S[maxn];
int n,m,t;
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
    ll cal(ll x,ll*a,int up){
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
     //O(n^2)求多项式 O(n)单点求f(k)
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
            dev(b, c, -x[i]);//得到多项式，保存在b数组
            for (int j = 0; j < n; ++j)
                a[j] = (a[j] + fz * c[j]) % mod;
        }
    }
    ll sum(){//n点 n-1次多项式
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
int main(){
    lglr.init();
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;++i){
            scanf("%lld",&a[i]);
        }
        a[n+1]=lglr.cal(n+1,a,n);
        S[0]=a[0];
        for(int i=1;i<=n+1;++i)S[i]=(S[i-1]+a[i])%mod;
        int L,R;
        for(int i=1;i<=m;++i){
            scanf("%d%d",&L,&R);
            ll sum=lglr.cal(R,S,n+1)-lglr.cal(L-1,S,n+1);
            cout<<(sum%mod+mod)%mod<<"\n";
        }
    }
    return 0;
}