#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+100;
ll a[maxn],b[maxn],f[maxn][21];
int n,Log[maxn],t;
void RMQ(){
	n=n-1;
	for(int i=1;i<=n;++i)f[i][0]=b[i];
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			f[i][j]=__gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
ll query(int l,int r){
	int k=Log[r-l+1];
	return __gcd(f[l][k],f[r-(1<<k)+1][k]);
}
int main(){
	Log[1]=0;
	for(int i=2;i<=maxn-99;++i)Log[i]=Log[i>>1]+1;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		if(n==1){
			cout<<"1\n";continue;
		}
		for(int i=1;i<=n-1;++i)b[i]=abs(a[i+1]-a[i]);
		RMQ();
		int j=1;
		int ans=1;
		for(int i=1;i<=n;++i){
			while(j<=i&&query(j,i)==1)j++;
			ans=max(ans,i-j+2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}