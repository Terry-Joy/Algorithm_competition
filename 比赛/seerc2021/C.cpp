#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3010;
const int mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k = 0;
	cin >> n;
	vector<vector<int> > G(n + 1);
	vector<vector<int> > dp(maxn, vector<int>(2 * n + 5, 0));
	vector<int> c(n + 1, 0), col(n + 1, 0), sz(n + 1, 0), tmp(2 * n + 5, 0);
	int u, v;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	int ans = 0;
	function<void(int, int)> dfs = [&](int x, int fa) {
		for (int i = -k; i <= k; ++i) 
			dp[x][i + k] = 0;
		dp[x][col[x] + k] = sz[x] = 1;
		for (auto v: G[x]) {
			if(v == fa)
				continue;
			dfs(v, x);
			for (int i = max(-k, -sz[x]); i <= min(k, sz[x]); ++i) {
				for(int j = max(-k, -sz[v]); j <= min(k, sz[v]); ++j) {
					if(i + j <= min(sz[x] + sz[v], k) && i + j >= max(-k, -sz[x] - sz[v])) {
						tmp[i + j + k] = (tmp[i + j + k] + (ll)dp[x][i + k] * dp[v][j + k]) % mod;
					}
				}
			}
			sz[x] += sz[v]; 
			for(int i = max(-k, -sz[x]); i <= min(k, sz[x]); ++i) 
				dp[x][i + k] = (dp[x][i + k] + tmp[i + k]) % mod, tmp[i + k] = 0;
		} 
		for (int i = 1; i <= k; ++i) 
			ans = (ans + dp[x][i + k]) % mod;
	};
	for (int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			col[j] = (c[j] == i) ? 1 : -1;
			k += (c[j] == i);
		}
		if(k)
			dfs(1, 0);
		k = 0;
	}
	cout << ans;
	return 0;
}