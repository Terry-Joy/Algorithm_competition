#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using PII = pair<int, int>;
const int INF = 0x3f3f3f3f;
int n, p, c;
vector<int> d;
void dij(int s, vector<vector<PII>> &G) {
	d[s] = 0;
	priority_queue<PII,vector<PII>,greater<PII> >q;
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
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> p >> c;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<PII>> G;
	G.resize(p + 1);
	vector<int> cnt(p + 1, 0);
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (int i = 1; i <= c; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].eb(v, w);
		G[v].eb(u, w);
	}
	d.resize(p + 1);
	int ans = 0, sum = INF;
	for (int i = 1; i <= p; ++i) {
		ans = 0;
		fill(d.begin(), d.end(), INF);
		dij(i, G);
		for (int j = 1; j <= p; ++j) {
			ans += cnt[j] * d[j];
		}
		sum = min(sum, ans);
	}
	cout << sum;
	return 0;
}