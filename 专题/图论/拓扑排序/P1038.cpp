#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using PII = pair<int, int>;
const int maxn = 10005;
int n, U[maxn], deg[maxn], m, sum[maxn], out[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	queue<int> q;
	vector<vector<PII>> G(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> sum[i] >> U[i];
		if (sum[i] > 0) { 
			q.push(i);
		} 
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].eb(v, w);
		deg[v]++;
		out[u] = 1;
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto &[v, w] : G[x]) {
			deg[v]--;
			if (sum[x] > 0) { 
				sum[v] += w * sum[x];
			}
			if (!deg[v]) {
				q.push(v);
				sum[v] -= U[v];
			}
		}
	}
	vector<PII> ans;
	for (int i = 1; i <= n; ++i) {
		if (sum[i] > 0 && !out[i]) { 
			ans.eb(i, sum[i]);
		}
	}
	if (!ans.size()) {
		cout << "NULL";
	} else {
		for (auto &[u, v] : ans) { 
			cout << u << " " << v << "\n";
		}
	}
	return 0;
}