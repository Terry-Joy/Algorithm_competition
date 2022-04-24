#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
int prime[maxn],cnt,phi[maxn];
bool v[maxn];
void init(){//预处理欧拉函数前缀和
    v[1]=1;phi[1]=1;
    for(int i=2;i<maxn;++i){
        if(!v[i])prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&prime[j]*i<maxn;++j){
            v[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }else{
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
    for(int i=2;i<maxn;++i){
        phi[i]+=phi[i-1];
        if(phi[i]>=mod)phi[i]-=mod;
    }
}
ll mypow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){
    init();
    int n,k;
    scanf("%d%d",&n,&k);
    ll ans=0;
    for(int l=1,r;l<=k;l=r+1){//整除分块
        r=(k/(k/l));
        ans=ans+mypow(k/l,n)%mod*((phi[r]-phi[l-1])%mod+mod)%mod;
        if(ans>=mod)ans-=mod;
    }
    cout<<ans<<"\n";
    return 0;
}