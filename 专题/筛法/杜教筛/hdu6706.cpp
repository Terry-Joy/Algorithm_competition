#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<unordered_map>
using namespace std;
const int maxn=1e6+5;
const int mod=1e9+7;
int phi[maxn],cnt,prime[maxn/5],inv2,inv6,N,t,a,b;
bool v[maxn];
unordered_map<int,int>phiS2;
int mypow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return ans;
}
void init(){
    v[1]=1;
    phi[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    for(int i=2;i<maxn;++i)
        phi[i]=(phi[i-1]+1ll*phi[i]*i%mod)%mod;
}
int S1(int n){//i^2
    return 1ll*n*(n+1)%mod*(2*n+1)%mod*inv6%mod;
}
int S2(int n){
    return 1ll*n*(n+1)%mod*inv2%mod;
}
int phiS(int n){
    if(n<maxn)return phi[n];
    if(phiS2[n])return phiS2[n];
    int ans=S1(n);
    for(int i=2,j,tmp;i<=n;i=j+1){
        j=n/(n/i);
        tmp=S2(j)-S2(i-1);
        ans=((ans-1ll*tmp*phiS(n/i)%mod)%mod+mod)%mod;
    }
    return phiS2[n]=ans;
}
int main(){
    init();
    inv2=mypow(2,mod-2);
    inv6=mypow(6,mod-2);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&N,&a,&b);
        int ans=(phiS(N)-1+mod)%mod;
        ans=1ll*ans*inv2%mod;
        printf("%d\n",ans);
    }
    return 0;
}