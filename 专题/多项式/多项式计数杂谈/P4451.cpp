#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int phi=mod-1;
const int maxn=1e4+5;
char s[maxn];
const int sqr=59713600;
int mypow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=(ll)ans*a%mod;
		a=(ll)a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	int len=strlen(s);
	ll now=0;
	for(int i=0;i<=len-1;++i){
		now=(now*10+s[i]-'0')%phi;	
	}
	int a=1+sqr,b=(1-sqr+mod)%mod;
	cout<<((ll)mypow(a,now)-mypow(b,now)+mod)%mod*sqr%mod*mypow(4,mod-2)%mod;
	return 0;
}