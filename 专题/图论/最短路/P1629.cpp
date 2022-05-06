#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using PII = pair<int, int>;
using ll = long long;
const int INF = 0x3f3f3f3f;
int n, m;
ll dij(int s, vector<vector<PII> >& G) {
	vector<int> d(n + 1, INF);
	d[s] = 0;
	priority_queue<PII, vector<PII>,greater<PII>> q;
	q.emplace(d[s], s);
	while (q.size()) {
		auto [dd, u] = q.top();
		q.pop();
		if (dd > d[u])
			continue;
		for (auto &[v, w] : G[u]) {
			if (d[u] + w < d[v]) {
				d[v] = d[u] + w;
				q.emplace(d[v], v);
			}
		}
	}
	ll ans = 0;
	for (int i = 2; i <= n; ++i)
		ans += d[i];
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<vector<PII>> G;
	vector<vector<PII>> G2;
	G.resize(n + 1);
	G2.resize(n + 1);
	int u, v, w;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		G[u].eb(v, w);
		G2[v].eb(u, w);
	}
	ll ans = 0;
	ans += dij(1, G);
	ans += dij(1, G2);
	cout << ans;
	return 0;
}