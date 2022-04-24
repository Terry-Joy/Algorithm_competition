#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
bool check(ll a){ 
    ll x=a*(a+1)/2;
    return x<=n+1;
}
int main(){
    cin>>n;
    ll l=0,r=2e9;
    while(l<r){ 
        ll mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<n+1-l;
	return 0;
}

