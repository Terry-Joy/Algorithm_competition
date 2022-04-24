#include<bits/stdc++.h>
#define fi first 
#define se second
#define eb emplace_back
using namespace std;
using ll=long long;
using P=pair<ll,int>;
const int maxn=105;
int n,a[maxn];
ll h;
bool check(ll x){
	ll sum=0,now=a[1];
	for(int i=1;i<=n;++i){
		sum+=a[i]+x-max(now,(ll)a[i]),
		now=max((ll)a[i]+x,now);
	}
	return sum>=h;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>h;
		for(int i=1;i<=n;++i)cin>>a[i];
		ll l=1,r=h;
		while(l<r){
			ll mid=l+r>>1;
			if(check(mid))	r=mid;
			else l=mid+1;
		}
		cout<<r<<"\n";
	}
	return 0;
}