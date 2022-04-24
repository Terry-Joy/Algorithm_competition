#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1005;
const int mod = 998244353;
int dp[maxn][(1<<10)+5][12];
char s[maxn];
int Add(int x, int y) {
	x += y;
	if(x >= mod) x -= mod;
	return x;
}
int mul(int x, int y) {
	return (ll)x * y % mod;
}
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> (s + 1);
	dp[0][0][0] = 1;
	int lim = (1 << 10);
	for(int i = 0; i < n; ++i) {
		int c = s[i+1] - 'A' + 1;
		for(int j = 0; j < lim; ++j) {
			for(int k = 0; k <= 10; ++k) {
				if(!dp[i][j][k])
					continue;
				if(!(j & (1 << (c-1)))) { //没出现过
					dp[i + 1][j|(1 << (c-1))][c] = Add(dp[i + 1][j|(1 << (c-1))][c], dp[i][j][k]); //选
					dp[i + 1][j][k] = Add(dp[i + 1][j][k], dp[i][j][k]);//不选
				}else {//出现过
					if(!k) {//空
						dp[i + 1][j][k] = Add(dp[i + 1][j][k], dp[i][j][k]); //不选
						dp[i + 1][j|(1 << (c-1))][c] = Add(dp[i + 1][1 << (c-1)][c], dp[i][j][k]);//选
					}else{
						if(c == k) {//接上或不接
							dp[i + 1][j][k] = Add(dp[i + 1][j][k], mul(2, dp[i][j][k]));	
						}else {//不接
							dp[i + 1][j][k] = Add(dp[i + 1][j][k], dp[i][j][k]);
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i < lim; ++i) {
		for(int j = 1; j <= 10; ++j) {
			ans = Add(ans, dp[n][i][j]);
		}
	}
	cout << ans;
	return 0;
}