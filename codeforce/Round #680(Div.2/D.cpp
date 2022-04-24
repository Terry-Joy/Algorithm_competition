#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define pb push_back
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long ll;
const int maxn=350005;
const ll mod=998244353;
ll fac[maxn],facinv[maxn];
int n,a[maxn];
ll mypow(ll a,ll b){ 
    ll ans=1;
    while(b){ 
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
void init(){ 
    fac[1]=fac[0]=1;
    for(int i=2;i<maxn;++i)fac[i]=fac[i-1]*i%mod;
    facinv[maxn-1]=mypow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i)
        facinv[i]=(facinv[i+1]*(i+1))%mod;
}
ll C(int n,int m){ 
    return fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
int main(){ 
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=2*n;++i)cin>>a[i];
    sort(a+1,a+1+2*n);
    ll ans=0;
    for(int i=1;i<=2*n;++i){ 
        if(i<=n)ans-=a[i];
        else ans+=a[i];
    }
    ans%=mod;
    cout<<C(2*n,n)*ans%mod<<endl;
    return 0;
}
