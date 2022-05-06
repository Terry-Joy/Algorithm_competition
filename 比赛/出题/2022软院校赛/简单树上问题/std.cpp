#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 2e5 + 5;

ll ans[maxn];
int cnt;
struct Edge {
	int u, v, w;
	Edge(int m_u, int m_v, int m_w) : u(m_u), v(m_v), w(m_w) {}
	bool operator<(const Edge& a) const {
		return w < a.w;
	}
};
vector<vector<PII>> g; 
struct DS {
	vector<int> fa, sz;
	vector<vector<int> > G;
	void init(int n) {
		fa.resize(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			fa[i] = i;
		sz.resize(n + 1, 1);
		G.resize(n + 1);
	}
	int find(int x) { 
		return x == fa[x] ? x : find(fa[x]);
	}
	void merge(int x, int y, int edge) {
		int xx = find(x), yy = find(y);
		if (xx == yy)		
			return;
		if (sz[xx] > sz[yy])
			swap(xx, yy);
		G[yy].eb(xx);
		ans[xx] += (ll)sz[yy] * edge;
		ans[yy] += (ll)sz[xx] * edge;
		sz[yy] += sz[xx];
		fa[xx] = yy;
		ans[xx] -= ans[yy];
	}
	void dfs(int x) {
		for (auto v : G[x]) {
			ans[v] += ans[x];
			dfs(v);	
		}
	}
}ds;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	ds.init(n);
	vector<Edge> edge;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.eb(u, v, w);
	}
	sort(edge.begin(),edge.end());
	for (auto [u, v, w] : edge) {
		ds.merge(u, v, w);
	}
	int root = ds.find(1);
	ds.dfs(root);
	for (int i = 1; i <= n; ++i) {
		cout << ans[i];
		if (i != n) {
			cout << "\n";
		}
	}
	return 0;
}