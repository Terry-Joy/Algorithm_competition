#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int dp[maxn][201];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1, 0), las(102, 0);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 200; ++j)
			dp[i][j] = dp[i - 1][j];
		for (int j = 1; j <= 100; ++j) {
			if (!las[j]) continue;
			dp[i][j + a[i]] = max(dp[i][j + a[i]], dp[las[j] - 1][j + a[i]] + 2);
			ans = max(ans, dp[i][j + a[i]]);
		}
		las[a[i]] = i;
	}
	cout << ans;
	return 0;
}