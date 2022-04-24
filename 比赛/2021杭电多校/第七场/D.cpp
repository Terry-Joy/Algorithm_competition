#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
const int mod=1e9+7;
ll inv[maxn],fac[maxn],n,m;
int t;
ll C(int n,int m){ 
    if(n<m)return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){ 
    inv[1]=1;
    for(int i=2;i<maxn;++i)inv[i]=mod-inv[mod%i]*(mod/i)%mod;
    inv[0]=fac[0]=1;
    for(int i=1;i<maxn;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[i-1]*inv[i]%mod;
    scanf("%d",&t);
    while(t--){ 
        int n,m;
        scanf("%d%d",&n,&m);
        cout<<(C(n+m,n)-C(m-1,n)+mod)%mod<<"\n";
    }
    return 0;
}
