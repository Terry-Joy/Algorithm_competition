#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int mod=998244353;
int fac[maxn],facinv[maxn];
int mypow(ll a,ll b){ 
    int ans=1;
    while(b){ 
        if(b&1)ans=(ll)ans*a%mod;
        a=(ll)a*a%mod;
        b>>=1;
    }
    return ans;
}
void init(){ 
    fac[1]=fac[0]=1;
    for(int i=2;i<maxn;++i)fac[i]=(ll)fac[i-1]*i%mod;
    facinv[maxn-1]=mypow(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;--i)
        facinv[i]=(ll)facinv[i+1]*(i+1)%mod;
}
int C(int n,int m){ 
    if(n<m)return 0;
    if(m==0||n==m)return 1;
    return (ll)fac[n]*facinv[n-m]%mod*facinv[m]%mod;
}
int main(){ 
    init();
    int t;
    scanf("%d",&t);
    while(t--){ 
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int ans=C(k+m-1,m-1);
        for(int i=1;(ll)i*n<=k;++i){ 
            if(i&1)
                ans=(ans-(ll)C(m,i)*C(k-i*n+m-1,m-1)%mod+mod)%mod;
            else
                ans=(ans+(ll)C(m,i)*C(k-i*n+m-1,m-1)%mod)%mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
