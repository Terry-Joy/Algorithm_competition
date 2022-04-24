#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>((1 << n), 0));
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<int>> e(n, vector<int>(n, 0));
    for (int i = 1; i <= k; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        e[x][y] = c;
    }
    ll ans = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
        dp[i][1 << i] = a[i];
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j)))
                continue;
            for (int f = 0; f < n; ++f) {
                if (i & (1 << f))
                    continue;
                dp[f][i | (1 << f)] = max(dp[f][i | (1 << f)], dp[j][i] + e[j][f] + a[f]);
                if (__builtin_popcount(i | (1 << f)) == m)
                    ans = max(ans, dp[f][i | (1 << f)]);
            }
        }
    }
    cout << ans;
    return 0;
}