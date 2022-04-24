#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll n,k,x,p[maxn],t[maxn],s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>x>>p[0];
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i<=k;++i)cin>>t[i];
	for(int i=1;i<=k;++i)cin>>p[i];
	ll mx=p[0];
	for(int i=1;i<=n;++i){
		mx=max(mx,p[i]-t[i]);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(mx*s[i]>=x)ans++;
	}
	cout<<ans;
	return 0;
}