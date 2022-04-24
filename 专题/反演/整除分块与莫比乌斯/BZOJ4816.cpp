#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=2e6+5;
int mu[maxn],prime[maxn/12],fab[maxn],cnt,inab[maxn],F[maxn];
bool v[maxn];
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
    mu[1]=v[1]=fab[1]=inab[1]=F[1]=F[0]=1;
    fab[0]=0;
    for(int i=2;i<=maxn-5;++i){
        fab[i]=(fab[i-1]+fab[i-2])%mod;
        inab[i]=mypow(fab[i],mod-2);
        F[i]=1;
        if(!v[i])prime[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&prime[j]*i<=maxn-5;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0)break;
            else mu[i*prime[j]]=-mu[i];
        }
    }
    for(int i=1;i<=maxn-5;++i){
        if(mu[i]){
            for(int j=i;j<=maxn-5;j+=i){
                F[j]=1ll*F[j]*((mu[i]==-1)?inab[j/i]:fab[j/i])%mod;
            }
        }
    }
    for(int i=2;i<=maxn-5;++i)
        F[i]=1ll*F[i]*F[i-1]%mod;
}
int main(){
    init();
    int t,n,m,l,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        if(n>m)swap(n,m);
        int ans=1,sum;
        for(l=1;l<=n;l=r+1){
            r=min(n/(n/l),m/(m/l));
            sum=1ll*F[r]*mypow(F[l-1],mod-2)%mod;
            ans=1ll*ans*mypow(sum,1ll*(n/l)*(m/l)%(mod-1))%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
