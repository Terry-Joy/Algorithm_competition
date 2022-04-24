#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1e9+7;
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
    cout<<(((mypow(10,n)-2*mypow(9,n))%mod+mod)%mod+mypow(8,n))%mod;
    return 0;
}