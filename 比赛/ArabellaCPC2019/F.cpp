#include <bits/stdc++.h>
using namespace std;
bool del[1024];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    p--;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> len(n);
    vector<int> ord(n);
    for (int i = 0; i < n - 1; ++i)
        cin >> len[i];
    for (int i = 0; i < n - 1; ++i) {
        cin >> ord[i];
        ord[i]--;
    }
    dp[0][p] = 1;
    for (int i = 0; i < n - 1; ++i) {
        int fi = len[i] % (n - i);
        vector<int> pos;
        for (int j = 0; j < n; ++j) {
            if (!del[j]) {
                pos.emplace_back(j);
            }
        }
        int sz = pos.size();
        for (int j = 0; j < sz; ++j) {
            if (!dp[i][pos[j]])
                continue;
            for (int k : {fi, sz - fi}) {
                int nxt = (j + k) % sz;
                dp[i + 1][pos[nxt]] = 1;
            }
        }
        del[ord[i]] = 1;
    }
    int ps = -1;
    for (int i = 0; i < n; ++i) {
        if (!del[i]) {
            cout << (dp[n - 1][i] ? "Yes" : "No");
            return 0;
        }
    }
    return 0;
}