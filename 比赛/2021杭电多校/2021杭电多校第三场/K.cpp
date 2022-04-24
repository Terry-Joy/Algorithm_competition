#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll>mp;
ll n,k;
ll dp(ll x){ 
    if(mp[x])return mp[x];
    if(x<=k)return mp[x]=1;
    return mp[x]=dp(x/2)+dp(x-x/2)+1;
}
int main(){ 
    int t;
    cin>>t;
    while(t--){ 
        mp.clear();
        scanf("%lld%lld",&n,&k);
        cout<<dp(n)<<"\n";
    }
    return 0;
}
