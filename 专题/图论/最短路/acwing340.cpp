#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using PII = pair<int, int>;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, p, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> p >> k;
	vector<vector<PII>> G(n + 1);
	for (int i = 0; i < p; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].eb(v, w);
		G[v].eb(u, w);
	}
	auto check = [&](int mid) {
		vector<ll> d(n + 1, INF);
		deque<PII> q;
		d[1] = 0;
		q.eb(d[1], 1);
		while (q.size()) {
			auto [dd, u] = q.front();
			q.pop_front();
			if (dd > d[u])
				continue;
			for (auto [v, w] : G[u]) {
				w = (w > mid);
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					if (w == 1) {
						q.eb(d[v], v);
					} else {
						q.emplace_front(d[v], v);
					}
				}
			}
		}
		return d[n] <= k;
	};
	int l = 0, r = 1e6 + 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if (r == 1e6 + 1) {
		cout << -1;
	} else {
		cout << r;
	}
	return 0;
}