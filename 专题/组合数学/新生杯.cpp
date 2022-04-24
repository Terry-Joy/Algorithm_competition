#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+5;
ll fac[maxn],facinv[maxn],mod=998244353;
ll mypow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(){
	fac[0]=fac[1]=1;
	for(int i=2;i<maxn;++i)fac[i]=fac[i-1]*i%mod;
	facinv[maxn-1]=mypow(fac[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;--i)
		facinv[i]=facinv[i+1]*(i+1)%mod;
}
ll C(int n,int m){
	if(n<m)return 0;
	return fac[n]*facinv[n-m]%mod*facinv[m]%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	init();
	int n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(m+1<=n)cout<<0<<"\n";
		else
			cout<<C(2*n,n)*mypow(n+1,mod-2)%mod*
			cout<<(C(n+m,m)-C(n+m,m+1)+mod)%mod<<"\n";
	}
	return 0;
}