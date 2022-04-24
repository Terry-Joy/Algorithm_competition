#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,d;
	cin>>n>>d;
	vector<pair<int,int>>a(n);
	for(int i=0;i<n;++i){
		cin>>a[i].fi>>a[i].se;
	}
	sort(a.begin(),a.end());
	int l=0;
	ll ans=0,sum=0;
	for(int i=0;i<n;++i){
		while(a[i].fi-a[l].fi>=d)sum-=a[l].se,l++;
		sum+=a[i].se;
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}