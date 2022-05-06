#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using PII = pair<int, int>;
const int INF = 0x3f3f3f3f;

int n, R, P, s;

void spfa(int s, const vector<vector<PII>> G) {
	vector<int> d(n + 1, INF);
	vector<bool> vis(n + 1, false);
	deque<int> q;
	q.eb(s);
	int sum = 0, cnt = 1;
	vis[s] = 1;
	d[s] = 0;
	while (q.size()) {
		int u = q.front();
		while (cnt * d[u] > sum) {
			q.pop_back();
			q.eb(u);
			u = q.front();
		}
		q.pop_front();
		cnt--;
		sum -= d[u];
		vis[u] = 0;
		for (auto [v, w] : G[u]) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				if (!vis[v]) {
					if (!q.empty() && d[v] <= d[q.front()]) {
						q.emplace_front(v);
					} else {
						q.eb(v);
					}
					vis[v] = 1;
					sum += d[v];
					cnt++;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (d[i] == INF) {
			cout << "NO PATH\n";
		} else {
			cout << d[i] << "\n";
		}
	}
}

// void spfa(int s, const vector<vector<PII>> G) {
// 	vector<int> d(n + 1, INF);
// 	vector<bool> vis(n + 1, false);
// 	queue<int> q;
// 	q.emplace(s);
// 	int sum = 0, cnt = 1;
// 	vis[s] = 1;
// 	d[s] = 0;
// 	while (q.size()) {
// 		int u = q.front();
// 		while (d[u] * cnt > sum) {
// 			q.pop();
// 			q.push(u);
// 			u = q.front();
// 		}
// 		q.pop();
// 		cnt--;
// 		sum -= d[u];
// 		vis[u] = 0;
// 		for (auto [v, w] : G[u]) {
// 			if (d[v] > d[u] + w) {
// 				d[v] = d[u] + w;
// 				if (!vis[v]) {
// 					q.emplace(v);
// 					sum += d[v];
// 					cnt++;
// 				}
// 			}
// 		}
// 	}
// 	for (int i = 1; i <= n; ++i) {
// 		if (d[i] == INF) {
// 			cout << "NO PATH\n";
// 		} else {
// 			cout << d[i] << "\n";
// 		}
// 	}
// }

// void spfa(int s, const vector<vector<PII>> G) {
// 	vector<int> d(n + 1, INF);
// 	vector<bool> vis(n + 1, false);
// 	deque<int> q;
// 	q.eb(s);
// 	vis[s] = 1;
// 	d[s] = 0;
// 	while (q.size()) {
// 		int u = q.front();
// 		q.pop_front();
// 		vis[u] = 0;
// 		for (auto [v, w] : G[u]) {
// 			if (d[v] > d[u] + w) {
// 				d[v] = d[u] + w;
// 				if (!vis[v]) {
// 					if (!q.empty() && d[v] <= d[q.front()]) {
// 						q.emplace_front(v);
// 					} else {
// 						q.emplace_back(v);
// 					}
// 					vis[v] = 1;
// 				}
// 			}
// 		}
// 	}
// 	for (int i = 1; i <= n; ++i) {
// 		if (d[i] == INF) {
// 			cout << "NO PATH\n";
// 		} else {
// 			cout << d[i] << "\n";
// 		}
// 	}
// }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> R >> P >> s;
	vector<vector<PII> > G(n + 1);
	int u, v, w;
	for (int i = 1; i <= R; ++i) {
		cin >> u >> v >> w;
		G[u].eb(v, w);
		G[v].eb(u, w);
	}
	for (int i = 1; i <= P; ++i) {
		cin >> u >> v >> w;
		G[u].eb(v, w);
	}
	spfa(s, G);
	return 0;
}