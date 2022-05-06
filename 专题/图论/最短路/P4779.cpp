#include<bits/stdc++.h>
#define eb emplace_back
#define mp make_pair
using namespace std;
using PII = pair<int, int>;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
vector<vector<PII>> G;
int n, m, s;
struct DIJ {
	int d[maxn];
	void dij(int s) { 
		fill(d, d + 1 + n, 0x3f3f3f3f);
		priority_queue<PII, vector<PII>,greater<PII>> q;
		q.emplace(0, s);
		d[s] = 0;
		while (q.size()) {
			auto [dd, u] = q.top();
			q.pop();
			if (dd > d[u])//某个点多次进堆，但第一次出堆的时候是最优的
				continue;
			for (auto &[v, w] : G[u]) {
				if (d[u] + w < d[v]) {
					d[v] = d[u] + w;
					q.emplace(d[v], v);
				}
			}
		}
	}
}dij;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	G.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].eb(v, w);
	}
	dij.dij(s);
	for (int i = 1; i <= n; ++i) {
		cout << dij.d[i] << " ";
	}
	return 0;
}