#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll f(ll b,ll n){
	if(n<b)return n;
	return f(b,n/b)+(n%b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,s;
	cin>>n>>s;

	bool ok=0;
	if(n<s){
		cout<<-1;return 0;
	}
	if(n==s){//特判
		cout<<n+1;return 0;
	}
	ll d=n-s;
	vector<ll>fac;
	for(ll i=1;i*i<=d;++i){
		if(d%i==0){
			fac.push_back(i);
			if(d/i!=i)
				fac.push_back(d/i);
		}
	}
	sort(fac.begin(),fac.end());
	for(auto&u:fac){
		if(f(u+1,n)==s){
			cout<<u+1<<"\n";
			return 0;
		}
	}
	cout<<-1;
	return 0;
}