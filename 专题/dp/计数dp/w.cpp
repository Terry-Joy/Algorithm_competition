#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=405;
ll f[maxn][maxn],g[maxn],p,fac[maxn][maxn],c[maxn][maxn],sum1[maxn],sum2[maxn];
int n,k;
ll mypow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
void init(){
    for(int i=0;i<=n;++i)
        for(int j=0;j<=i;++j){
            if(j==0||j==i)
                c[i][j]=1;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            fac[i][j]=mypow(i,j);
}
int main(){
    scanf("%d%d%lld",&n,&k,&p);
    init();
    for(int j=1;j<=n;++j){
        for(int val=2;val<=j;++val){
            ll x1=1,x2=1;
            ll mu1=mypow(val,p-2),mu2=mypow(val-1,p-2);
            sum1[0]=sum2[0]=0;
            for(int i=1;i<=n;++i){
                x1=x1*mu1%p;x2=x2*mu2%p;
                f[i][j]=((f[i][j]-sum1[i-1]*fac[val][i]%p)%p+p)%p;
                f[i][j]=(f[i][j]+sum2[i-1]*fac[val-1][i]%p)%p;
                sum1[i]=(sum1[i-1]+((f[i][j-val+1]-f[i][j-val])%p+p)%p*x1%p)%p;
                sum2[i]=(sum2[i-1]+((f[i][j-val+1]-f[i][j-val])%p+p)%p*x2%p)%p;
            }
        }
        for(int i=1;i<=n;++i){
            f[i][j]=(f[i][j]+fac[j][i])%p;
            for(int d=i+1;d<=n;++d)
                f[d][j]=(f[d][j]-((f[i][j]-f[i][j-1])%p+p)%p+p)%p;
        }    
    }
    for(int i=1;i<=n;++i)g[i]=f[n][i];
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            g[i]=((g[i]-c[i][j]*g[j]%p)%p+p)%p;
        }
    }
    ll ans=0;
    for(int i=1;i<=min(n,k);++i){//c[k][i]
        ll num=1;
        for(int j=1;j<=i;++j){
            num=num*(k-j+1)%p;
            num=num*mypow(j,p-2)%p;
        }
        ans=(ans+num*g[i]%p)%p;
    }
    cout<<ans<<"\n";
    return 0;
}