#include<bits/stdc++.h>
#define eb emplace_back

using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int head[maxn], ver[maxn<<1], tot, next1[maxn<<1];
ll ans[maxn];
void add(int x, int y) {
	ver[++tot] = y, next1[tot] = head[x], head[x] = tot;
}
struct Edge {
	int u, v, w;
	Edge(int m_u, int m_v, int m_w) : u(m_u), v(m_v), w(m_w) {}
	bool operator<(const Edge& a) const {
		return w < a.w;
	}
};
struct DS {
	//vector<int> fa, sz;
	int fa[maxn], sz[maxn];
	void init(int n) {
		for (int i = 1; i <= n; ++i)
			fa[i] = i, sz[i] = 1;
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
		add(yy, xx);
		//G[yy].eb(xx);
		ans[xx] += (ll)sz[yy] * edge;
		ans[yy] += (ll)sz[xx] * edge;
		sz[yy] += sz[xx];
		fa[xx] = yy;
		ans[xx] -= ans[yy];
	}
	void dfs(int x) {
		for (int i = head[x]; i; i = next1[i]) {
			int v = ver[i];
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
	for (int i = 0; i < n; ++i) {
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
		cout << ans[i] << "\n";
	}
	return 0;
}