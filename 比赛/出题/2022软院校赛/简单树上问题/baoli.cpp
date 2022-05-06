#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 2e5 + 5;
ll ans[maxn];
vector<vector<PII>> G;
int root;
vector<int> tmp;
void dfs(int x, int fa) {
	int sum = (!tmp.size()) ? 0 : tmp.back();
	ans[root] += sum;
	for (auto [v, w] : G[x]) {
		if (v == fa)
			continue;
		int nowmx = (!tmp.size()) ? 0 : tmp.back();
		nowmx = max(nowmx, w);
		tmp.push_back(nowmx);
		dfs(v, x);
		tmp.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	G.resize(n + 1);
	int u, v, w;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v >> w;
		G[u].eb(v, w);
		G[v].eb(u, w);
	}
	for (int i = 1; i <= n; ++i) {
		tmp.clear();
		root = i;
		dfs(i, 0);
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}