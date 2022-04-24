#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10010];
int main(){
	int t,n,m;
	cin>>t;
	for(int f=1;f<=t;++f){
		cin>>n>>m;
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		for(int i=2;i<=n;++i)a[i]+=a[i-1];
		if(n<m){
			cout<<a[n]<<"\n";continue;
		}
		ll ans=0;
		for(int i=m;i<=n;++i)ans=max(ans,a[i]-a[i-m]);
		if(f!=t)
			cout<<ans<<"\n";
		else
			cout<<ans;
	}
	return 0;
}