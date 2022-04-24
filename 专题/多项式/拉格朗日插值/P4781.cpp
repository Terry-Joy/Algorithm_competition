#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+5;
const int mod=998244353;
int x[maxn],y[maxn],n,k;
int mypow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1ll*ans*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return ans;
}
int inv(int x){return mypow(x,mod-2);}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)scanf("%d%d",&x[i],&y[i]);
    ll ans=0;
    for(int i=0;i<n;++i){
        int zi=y[i],mu=1;
        for(int j=0;j<n;++j){
            if(i!=j){
                zi=1ll*zi*(k-x[j])%mod;
                mu=1ll*mu*(x[i]-x[j])%mod;
            }
        }
        ans=(ans+1ll*zi*inv(mu)%mod)%mod;
    }
    cout<<(ans%mod+mod)%mod<<"\n";
    return 0;
}