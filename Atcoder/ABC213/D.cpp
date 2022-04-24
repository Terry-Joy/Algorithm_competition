#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    vector<set<int>> G(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    vector<int> ans;
    function<void(int, int)> dfs = [&](int x, int fa) {
        ans.emplace_back(x);
        for (auto v : G[x]) {
            if (v == fa)
                continue;
            dfs(v, x);
            if (G[x].size() >= 2 || x == 1) { //不是叶子或者在1
                ans.emplace_back(x);
            }
        }
    };
    dfs(1, -1);
    for (auto u : ans)
        cout << u << " ";
    return 0;
}