#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int INF = 0x3f3f3f3f3f3f3f3f;
int n, m, s;
void spfa(int s, const vector<vector<PII> > &G) {
	vector<ll> d(n + 1, INF);
	vector<bool> vis(n + 1, false);
	d[s] = 0;
	vis[s] = 1;
	queue<int> q;
	q.emplace(s);
	while (q.size()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (auto [v, w] : G[u]) {	
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				if (!vis[v]) {
					q.emplace(v);
					vis[v] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (d[i] == INF) {
			cout << INT_MAX << " ";
		} else {
			cout << d[i] << " ";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<PII> > G;
	cin >> n >> m >> s;
	G.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].eb(v, w);
	}
	spfa(s, G);
	return 0;
}