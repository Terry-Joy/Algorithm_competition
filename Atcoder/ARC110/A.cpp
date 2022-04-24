#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){ return a/gcd(a,b)*b;}
int main(){ 
    ll n;
    cin>>n;
    ll ans=1;
    for(ll i=2;i<=n;++i){ 
        ans=lcm(i,ans);
    }
    cout<<ans+1<<"\n";
    return 0;
}
