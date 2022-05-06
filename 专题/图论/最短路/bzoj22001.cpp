#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using PII = pair<int, int>;
const int INF = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, R, P, s;
	cin >> n >> R >> P >> s;
	vector<vector<PII> > G(n + 1);
	int u, v, w;
	for (int i = 1; i <= R; ++i) {
		cin >> u >> v >> w;
		G[u].eb(v, w);
		G[v].eb(u, w);
	}
	vector<int> c(n + 1, 0), deg(n + 1, 0);
	function<void(int, int, int)> dfs = [&](int x, int fa, int id) {
		c[x] = id;
		for (auto [v, w] : G[x]) {
			if (v == fa || c[v])
				continue;
			dfs(v, x, id);
		}
	};
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!c[i]) {
			dfs(i, 0, ++cnt);
		}
	}
	vector<vector<int> > Point(cnt + 1);
	for (int i = 1; i <= P; ++i) {
		cin >> u >> v >> w;
		G[u].eb(v, w);
		deg[c[v]]++;
		//Point[c[v]].eb(v);
	}
	queue<int> q;
	for (int i = 1; i <= cnt; ++i) {
		if (!deg[i]) {
			q.emplace(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		Point[c[i]].eb(i);
	}
	if (deg[c[s]]) {
		q.emplace(c[s]);
	}
	vector<int> d(n + 1, INF);
	d[s] = 0;
	while (q.size()) {
		int x = q.front();
		q.pop();
		priority_queue<PII, vector<PII>,greater<PII>> q2;
		for (auto u : Point[x]) {
			q2.emplace(d[u], u);
		}
		while (q2.size()) {
			auto [dd, u] = q2.top();
			q2.pop();
			if (dd > d[u])
				continue;
			for (auto [v, w] : G[u]) {
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					if (c[u] == c[v]) {//同一个联通块内部才丢进队列，保证取出来的确实是全局最小值。
						q2.emplace(d[v], v);
					}
				}
				if (c[u] != c[v]) {
					deg[c[v]]--;
					if (!deg[c[v]]) { 
						q.emplace(c[v]);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (d[i] >= INF) {
			cout << "NO PATH\n";
		} else {
			cout << d[i] << "\n";
		}
	}
	return 0;
}