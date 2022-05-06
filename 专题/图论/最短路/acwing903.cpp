//O(n ^2 + m(n + m)logn)
#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using PII = pair<int, int>;
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	vector<vector<PII>> G(n + 1);
	vector<int> P(n + 1), L(n + 1), X(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> P[i] >> L[i] >> X[i];
		G[0].eb(i, P[i]);
		for (int j = 1; j <= X[i]; ++j) {
			int T, V;
			cin >> T >> V;
			G[T].eb(i, V);
		}
	}
	int ans = INF;
	for (int i = L[1] - m; i <= L[1]; ++i) {
		vector<bool> vis(n + 1, false);
		for (int j = 1; j <= n; ++j) {
			if (L[j] >= i && L[j] <= i + m) {
				vis[j] = 1;
			}
		}
		priority_queue<PII, vector<PII>, greater<PII> >q;
		vector<int> d(n + 1, INF);
		d[0] = 0;
		q.emplace(d[0], 0);
		while (q.size()) {
			auto [dd, u] = q.top();
			q.pop();
			if (dd > d[u])
				continue;
			for (auto [v, w]: G[u]) {
				if (vis[v] && d[u] + w < d[v]) {
					d[v] = d[u] + w;
					q.emplace(d[v], v);
				}
			}
		}
		ans = min(ans, d[1]);
	}
	cout << ans;
	return 0;
}