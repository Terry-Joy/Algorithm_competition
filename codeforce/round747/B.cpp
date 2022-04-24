#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
ll solve(ll n,ll k){
	ll now=1,ans=0;
	while(k){
		if(k&1)ans=(ans+now)%mod;
		k>>=1;
		now=now*n%mod;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		cout<<solve(n,k)<<"\n";
	}
	return 0;
}