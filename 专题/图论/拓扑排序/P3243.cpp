#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > G(n + 1);
		vector<unordered_map<int, bool>> mp(n + 1);
		vector<int> deg(n + 1);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			if (mp[u].find(v) == mp[u].end()) {
				mp[u][v] = 1;
				G[v].eb(u);
				deg[u]++;
			}
		}	
		priority_queue<int> q;
		for (int i = 1; i <= n; ++i) {
			if (!deg[i]) {
				q.emplace(i);
			}
		}	
		vector<int> ans;
		while (!q.empty()) {
			auto u = q.top();
			q.pop();
			ans.eb(u);
			for (auto &v : G[u]) {
				deg[v]--;
				if (!deg[v]) {
					q.emplace(v);
				}
			}
		}
		if (ans.size() < n) {
			cout << "Impossible!\n";
		} else {
			reverse(ans.begin(), ans.end());
			for (auto u : ans) { 
				cout << u << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}