#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k;
const int maxn=5e3+5;
ll dp[maxn][maxn],mod=1e9+7;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=min(k,i);++j){
			dp[i][j]=(dp[i-1][j-1]+(i-1)*dp[i-1][j])%mod;
		}			
	}
	cout<<dp[n][k];
	return 0;
}