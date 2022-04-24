#include <cstdio>

const int N=1e7+5,M=N/10;
int n,tot,p[M],phi[N];
bool flg[N];

void sieve(int n) {
    phi[1]=1;
    for(int i=2;i<=n;++i) {
        if(!flg[i]) p[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot&&i*p[j]<=n;++j) {
            flg[i*p[j]]=1;
            if(i%p[j]==0) {
                phi[i*p[j]]=phi[i]*p[j];
                break;
            } else {
                phi[i*p[j]]=phi[i]*phi[p[j]];
            }
        }
    }
}
int pow(int x,int p,int mod) {
    int ret=1;
    for(;p;p>>=1,x=1LL*x*x%mod) if(p&1) ret=1LL*ret*x%mod;
    return ret;
}
int solve(int p) {
    if(p==1) return 0;
    return pow(2,solve(phi[p])+phi[p],p);
}
int main() {
    sieve(N-5);
    int T;
    for(scanf("%d",&T);T--;) {
        int p;
        scanf("%d",&p);
        printf("%d\n",solve(p));
    }
    return 0;
}
