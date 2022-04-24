#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
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
    ll n;
    cin>>n;
    if(n&1)puts("0");
    else{
    	 if(n==2){
            puts("1");return 0;
        }
        ll ans=1;
        for(int i=n-1;i>=1;i-=2){
            ans*=i;
            ans%=mod;
        }
        cout<<ans*mypow(n/2,(n/2)-2)%mod*mypow(4,(n/2)-1)%mod<<'\n';
    }
    return 0;
}
