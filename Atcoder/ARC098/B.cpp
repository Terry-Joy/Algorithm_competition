#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
int a[maxn],n;
ll sum[maxn],xorSum[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;++i)xorSum[i]=xorSum[i-1]^a[i];
	int r=1;
	ll ans=0;
	for(int i=1;i<=n;++i){
		while(r<=n&&(sum[r]-sum[i-1]==(xorSum[r]^xorSum[i-1])))
			r++;
		ans+=r-i;
	}
	cout<<ans;
	return 0;
}