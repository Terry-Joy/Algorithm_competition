#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=3e6+100;
const int mod=1e9+7;
int dp[maxn][3],fac[maxn],facinv[maxn];
inline int Add(int x,int y){
	x+=y;
	if(x>=mod)x-=mod;
	return x;
}
inline int Sub(int x,int y){
	x-=y;
	if(x<0)x+=mod;
	return x;
}
int mypow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=(ll)ans*a%mod;
		a=(ll)a*a%mod;
		b>>=1;
	}
	return ans;
}
inline int mul(int x,int y){
	return (ll)x*y%mod;
}
void init(){
	fac[0]=fac[1]=1;
	for(int i=2;i<maxn;++i)fac[i]=(ll)fac[i-1]*i%mod;
	facinv[maxn-1]=mypow(fac[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;--i)
		facinv[i]=mul(i+1,facinv[i+1]);
}
int C(int n,int m){
	if(n<m)return 0;
	return (ll)fac[n]*facinv[n-m]%mod*facinv[m]%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	int inv3=mypow(3,mod-2);
	init();
	dp[0][0]=dp[0][1]=dp[0][2]=n+1;
	for(int i=1;i<=3*n;++i){
		dp[i][0]=Add(dp[i][0],mul(Sub(Sub(C(3*n+3,i+1),mul(2,dp[i-1][0])),dp[i-1][1]),inv3));
		dp[i][1]=Add(dp[i][1],Add(dp[i][0],dp[i-1][0]));
		dp[i][2]=Add(dp[i][2],Add(dp[i][1],dp[i-1][1]));
	}
	for(int i=1;i<=q;++i){
		int x;
		cin>>x;
		cout<<dp[x][0]<<"\n";
	}
	return 0;
}