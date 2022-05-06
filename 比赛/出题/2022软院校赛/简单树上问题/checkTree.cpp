#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
int cnt = 0;
//vector<vector<int>> G;
int head[maxn], ver[maxn<<1], next1[maxn<<1], tot;
void add(int x, int y) {
	ver[++tot] = y, next1[tot] = head[x], head[x] = tot;
}
void dfs(int x, int fa) {
	cnt++;
	for (int i = head[x]; i; i = next1[i]) {
		int v = ver[i];
		if (v == fa) 
			continue;
		dfs(v, x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	//G.resize(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	if (cnt < n) {
		cout << "buxing";
	} else if (cnt == n) {
		cout << "ok";
	}
	return 0;
}