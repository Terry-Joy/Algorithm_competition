#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll mod=1e9+7;
 
ll qpow(ll a,ll b){
    ll ans=1;
    a%=mod;
    for(ll i=b;i;){
        if(i&1){
            ans=ans*a%mod;
        }
        i>>=1;
        a=a*a%mod;
    }    
    return ans;
}
 
int main(){
    ll n;
    scanf("%lld",&n);
    if(n==1){
        printf("1\n");
    }else if(n==2){
        printf("4\n");
    }else{
        ll res=(4*qpow(3,n-2))%mod;
        printf("%lld\n",res);
    }
    return 0;
}
