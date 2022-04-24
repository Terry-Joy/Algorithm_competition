#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int prime[maxn/5],N,p,mod,m,cnt,times;
ll phiS2[1020],phi[maxn];
bool v[maxn],visphi[1020];
void init(){
    v[1]=phi[1]=1;mod=p-1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }else
                phi[i*prime[j]]=phi[i]*(prime[j]-1); 
        }
    }
    for(int i=2;i<maxn;++i){
        phi[i]+=phi[i-1];
        if(phi[i]>=mod)phi[i]-=mod;
    }
}
int phiS(int n){
    if(n<maxn)return phi[n];
    int x=N/n;
    if(visphi[x])return phiS2[x];
    visphi[x]=1;
    ll&ans=phiS2[x];
    ans=1ll*(n+1)*n/2;
    for(int i=2,j;i<=n;i=j+1){
        j=n/(n/i);
        ans-=1ll*(j-i+1)*phiS(n/i);
    }
    ans%=mod;
    return ans;
}
ll mypow(ll a,ll b,ll p){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%p;
        a=a*a%p;b>>=1;
    }
    return ans;
}
int main(){
    scanf("%d%d%d",&N,&m,&p);
    init();
    ll ans=0,ans1=0;
    for(int i=1,j,tt1;i<=N;i=j+1){
        j=N/(N/i);
        tt1=N/i;
        ans1=0;
        times++;
        for(int k=1,f,tt2;k<=tt1;k=f+1){
            times++;
            tt2=tt1/k;
            f=tt1/tt2;
            ans1=(ans1+(((f*1ll*(f+1)/2)-k*1ll*(k-1)/2)*tt2*tt2))%mod;//后面最多2个1e9,爆不了
        }            
        ans=(ans+ans1*(phiS(j)-phiS(i-1)))%mod;
        if(ans<0)ans+=mod;
    }
    cout<<times<<endl;
    cout<<mypow(m,ans,p)<<"\n";
    return 0;
}
