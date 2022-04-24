#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll dp[52][52][52*52];
int main(){
	int n,a,x[52];
	cin>>n>>a;
	for(int i=1;i<=n;++i)cin>>x[i];
	int mx=*max_element(x+1,x+1+n);
	dp[0][0][0]=1;
	for(int i=0;i<=n-1;++i){
		for(int j=0;j<=i;++j){
			for(int k=0;k<=mx*j;++k){
				dp[i+1][j+1][k+x[i+1]]+=dp[i][j][k];
				dp[i+1][j][k]+=dp[i][j][k];
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		ans+=dp[n][i][i*a];
	}
	cout<<ans;
}