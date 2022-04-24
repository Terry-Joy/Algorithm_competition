#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+9;
const ll sqr=383008016;
const int maxn=1e5+5;
ll fac[maxn],facinv[maxn];
ll mypow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int x){
	fac[0]=1;
	for(int i=1;i<=x;++i)fac[i]=fac[i-1]*i%mod;
	facinv[x]=mypow(fac[x],mod-2);
	for(int i=x-1;i>=0;--i)
		facinv[i]=facinv[i+1]*(i+1)%mod;
}
ll C(int n,int m){
	if(n<m)return 0;
	return fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
int main(){
	int t;
	cin>>t;
	ll a=(sqr+1)*mypow(2,mod-2)%mod,b=(sqr-1)*mypow(2,mod-2)%mod;
	ll w=sqr*mypow(5,mod-2)%mod;
	init(maxn-4);
	while(t--){
		ll n;
		int k;
		cin>>n>>k;
		ll ans=0;		
		for(int i=0;i<=k;++i){
			ll tmp=mypow(a,i)*mypow(b,k-i)%mod;
			ll tmp2=mypow(tmp,n);
			ll sum=tmp*(tmp2-1+mod)%mod;
			sum=sum*mypow((tmp-1+mod)%mod,mod-2)%mod;
			if((k-i)&1)
				ans=(ans-C(k,i)*sum%mod+mod)%mod;
			else
				ans=(ans+C(k,i)*sum%mod)%mod;
		}
		ans=(ans+mod)%mod;
		cout<<ans*mypow(w,k)%mod<<"\n";
	}
	return 0;
}