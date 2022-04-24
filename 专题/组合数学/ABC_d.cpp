#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
ll fac[maxn],facinv[maxn],mod=1e9+7;
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
	init();
	int n,m;
	cin>>n>>m;
	vector<int>num;
	for(int i=2;i*i<=m;++i){
		if(m%i==0){
			int now=0;
			while(m%i==0){
				now++;
				m/=i;
			}
			num.push_back(now);
		}
	}
	if(m>1)num.push_back(1);
	ll ans=1;
	for(auto&u:num){
		ans=ans*C(u+n-1,n-1)%mod;
	}
	cout<<ans;
	return 0;
}