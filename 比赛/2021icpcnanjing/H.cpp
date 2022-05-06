#include<bits/stdc++.h>
#define eb emplace_back
#define fi first 
#define se second
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int maxn = 1e5 + 5;
vector<int> G[maxn];
ll f[maxn], sum[maxn];
int t[maxn], a[maxn];
void dfs(int x, int fa) {
	int mxa = 0;
	P mx1 = {0, -1}, mx2 = {0, -1};
	for (auto v : G[x]) {
		if (v == fa)
			continue;
		dfs(v, x);
		sum[x] += f[v];
		mxa = max(mxa, a[v]);
		if (t[v] == 3) {
			if (mx1.se == -1) {
				mx1.fi = a[v];
				mx1.se = v;
			} else {
				if (a[v] > mx1.fi) {
					mx2.fi = mx1.fi;
					mx1.fi = a[v];
					mx2.se = mx1.se;
					mx1.se = v;
				} else if (a[v] > mx2.fi) {
					mx2.fi = a[v];
					mx2.se = v;
				}
			} 
		}
	}
	f[x] = sum[x] + mxa;
	for (auto v: G[x]) {
		if (v == fa)
			continue;
		f[x] = max(f[x], sum[x] - f[v] + a[v] + sum[v] + (v == mx1.se ? mx2.fi : mx1.fi));
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i <= n; ++i) {
			G[i].clear();
			f[i] = sum[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			cin >> t[i];
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			G[u].eb(v);
			G[v].eb(u);
		}
		G[0].eb(1);
		dfs(0, -1);
		cout << f[0] << "\n";
	}
	return 0;
}