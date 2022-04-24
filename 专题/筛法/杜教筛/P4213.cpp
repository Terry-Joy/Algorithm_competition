//杜教筛 O(n^(2/3))
//g(1)S(n)=∑(f*g)(i)(i属于1到n)-∑g(d)S(n/d)  (d属于2到n)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
int prime[maxn],cnt=0,N,t;
bool visphi[1300],v[maxn],vismu[1300];
ll phi[maxn],mu[maxn];
ll phiS2[1300],muS2[maxn];
void init(){
    mu[1]=phi[1]=1;
    for(int i=2;i<=maxn-5;++i){
        if(!v[i])prime[++cnt]=i,phi[i]=i-1,mu[i]=-1;
        for(int j=1;j<=cnt&&prime[j]*i<=maxn-5;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            mu[i*prime[j]]=-mu[i];
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    for(int i=2;i<=maxn-5;++i)
        phi[i]+=phi[i-1],mu[i]+=mu[i-1];
}
ll phiS(int n){
    if(n<=maxn-5)return phi[n];
    int x=N/n;//也可用unordered map 但常数稍大 原理易得
    if(visphi[x])return phiS2[x];
    visphi[x]=1;
    ll&ans=phiS2[x];
    ans=1ll*(n+1)*n/2;
    for(int i=2,j;i<=n;i=j+1){
        j=n/(n/i);
        ans-=1ll*(j-i+1)*phiS(n/i);
    }
    return ans;
}
ll muS(int n){
    if(n<=maxn-5)return mu[n];
    int x=N/n;
    if(vismu[x])return muS2[x];
    vismu[x]=1;
    ll&ans=muS2[x];
    ans=1ll;
    for(int i=2,j;i<=n;i=j+1){
        j=n/(n/i);
        ans-=1ll*(j-i+1)*muS(n/i);
    }
    return ans;
}
int main(){
    init();
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        for(int i=1;i<=1295;++i)vismu[i]=visphi[i]=0;
        printf("%lld %lld\n",phiS(N),muS(N));
    }
    return 0;
}