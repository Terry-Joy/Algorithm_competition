#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> G(n + 1);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            G[u].eb(v);
            G[v].eb(u);
        }
        vector<int> mn(n + 1, 0);
        int rt = INF;
        for (int i = 1; i <= n; ++i) {
            if (G[i].size() == 1) {
                rt = i;
                break;
            }
        }
        vector<int> ans;
        function<void(int, int)> dfs = [&](int x, int fa) {
            if (G[x].size() == 1) {
                mn[x] = x;
            } else {
				for (auto v : G[x]) {
					if (v == fa)
						continue;
					dfs(v, x);
				}
				sort(G[x].begin(), G[x].end(), [&](int i, int j) {
					return mn[i] < mn[j];
				});
				mn[x] = mn[G[x][1]];
			}
        };
        function<void(int, int)> getAns = [&](int x, int fa) {
            for (auto v : G[x]) {
                if (v == fa)
                    continue;
                getAns(v, x);
            }
            ans.emplace_back(x);
        };
        int fa = G[rt][0];
        dfs(fa, rt);
		while(fa < mn[G[fa].back()]) //往根除了最小叶子id的子树外跳
			fa = G[fa].back();
        getAns(fa, 0);
        for (auto u : ans) {
            cout << u << " ";
        }
        cout << "\n";
    }
    return 0;
}