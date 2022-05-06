#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using PII = pair<int,int>;
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> pos(5, 0);
	for (int i = 0; i < 5; ++i) {
		cin >> pos[i];
	}
	sort(pos.begin(), pos.end());
	vector<vector<PII>> G(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v, w; 
		cin >> u >> v >> w;
		G[u].eb(v, w);
		G[v].eb(u, w);
	}
	vector<vector<int>> d(6, vector<int> (n + 1, INF));
	auto dij = [&](int s, int i) { 
		d[i][s] = 0;
		priority_queue<PII, vector<PII>, greater<PII>> q;
		q.emplace(0, s);
		while (q.size()) {
			auto [dd, u] = q.top();
			q.pop();
			if (dd > d[i][u])
				continue;
			for (auto [v, w] : G[u]) {
				if (d[i][v] > d[i][u] + w) {
					d[i][v] = d[i][u] + w;
					q.emplace(d[i][v], v);
				}
			}
		}
	};
	int ans = INF;
	unordered_map<int, int> mp;
	mp[1] = 0;
	for (int i = 0; i < 5; ++i) {
		mp[pos[i]] = i + 1;
	}
	dij(1, 0);
	for (int i = 0; i < 5; ++i) {
		dij(pos[i], mp[pos[i]]);
	}
	do {
		int sum = 0;
		int now = 1;
		for (int i = 0; i < 5; ++i) {
			sum += d[mp[now]][pos[i]];
			now = pos[i];
		}
		ans = min(ans, sum);
	}while (next_permutation(pos.begin(), pos.end()));
	cout << ans;
	return 0;
}