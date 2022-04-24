#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
char s[105];
ll dp[105][105];
int n,m,nxt[105];
char c[10]={'c','o','n','i','e'};
void getKmp(){
	for(int i=2,j=0;i<=m;++i){
		while(j&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])j++;
		nxt[i]=j;
	}
}
ll mypow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	dp[0][0]=1;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	getKmp();
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			for(int k=0;k<=4;++k){
				int pos=j;
				while(pos&&(pos==m||c[k]!=s[pos+1]))pos=nxt[pos];
				if(c[k]==s[pos+1])pos++;
				dp[i+1][pos]=(dp[i+1][pos]+1ll*dp[i][j]*(pos==m?2:1))%mod;	
			} 
		} 
	}
	ll ans=0;
	for(int i=0;i<=m;++i)ans=(ans+dp[n][i])%mod;
	ll inv=mypow(5,n);
	inv=mypow(inv,mod-2);
	cout<<ans*inv%mod<<"\n";
	return 0;	
}