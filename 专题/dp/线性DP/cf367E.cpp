#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int Add(int x, int y) {
	x += y;
	if (x >= mod) 
		x -= mod;
	return x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m >> x;	
	if (n > m) {
		cout << 0;
		return 0;
	}
	vector<vector<vector<int> > > dp(m + 1, vector<vector<int>> (n + 1, vector<int> (n + 1, 0)));
	dp[0][0][0] = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k <= j; ++k) {
				if (!dp[i][j][k])
					continue;
				if (j + 1 <= n) {
					dp[i + 1][j + 1][k] = Add(dp[i + 1][j + 1][k], dp[i][j][k]);
					dp[i + 1][j + 1][k + 1] = Add(dp[i + 1][j + 1][k + 1], dp[i][j][k]);  
 				}
				if (i + 1 != x) {
					dp[i + 1][j][k] = Add(dp[i + 1][j][k], dp[i][j][k]);
					if (k + 1 <= j)
						dp[i + 1][j][k + 1] = Add(dp[i + 1][j][k + 1], dp[i][j][k]);
				}
			}
		}
	}
	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		ans = (long long) ans * i % mod;
	}
	cout << (long long) ans * dp[m][n][n] % mod;
}