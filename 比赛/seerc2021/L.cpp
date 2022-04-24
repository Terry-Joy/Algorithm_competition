#include <bits/stdc++.h>
using namespace std;
int n, len;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> n;
    cin >> s;
    len = 3 * n;
    int cntA = 0, cntB = 0, cntC = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A')
            cntA++;
        else if (s[i] == 'B')
            cntB++;
        else
            cntC++;
    }
    if (cntA == n && cntB == n && cntC == n) {
        cout << 0;
        return 0;
    }
    vector<vector<int>> sum(3, vector<int>(len, 0));
    int p[3];

    for (int i = 0; i < 3; ++i) {
        sum[i][0] = (s[0] == char('A' + i));
        p[i] = -1;
        if (sum[i][0] == n)
            p[i] = 0;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j < len; ++j) {
            sum[i][j] = (sum[i][j - 1] + (s[j] == char('A' + i)));
            if (sum[i][j] == n) {
                p[i] = j;
            }
        }
    }
    vector<tuple<int, int, char>> ans;
    auto solve = [&](int rp, int s1, int s2) -> bool {
        int li1 = sum[s1][len - 1] - n, li2 = sum[s2][len - 1] - n;
        if (li1 < 0 || li2 < 0)
            return false;
        int l = 0;
        for (int r = 0; r < len; ++r) {
            while (l < r && ((sum[s1][r] - ((!l) ? 0 : sum[s1][l - 1])) > li1 ||
                             (sum[s2][r] - ((!l) ? 0 : sum[s2][l - 1])) > li2))
                l++;
            if ((sum[s1][r] - ((!l) ? 0 : sum[s1][l - 1])) == li1 &&
                (sum[s2][r] - ((!l) ? 0 : sum[s2][l - 1])) == li2) {
                ans.push_back(make_tuple(l + 1, r + 1, char(rp + 'A')));
                return true;
            }
        }
        return false;
    };
    if (solve(0, 1, 2) || solve(1, 0, 2) || solve(2, 0, 1)) {
        cout << 1 << "\n";
        for (auto u : ans) {
            cout << get<0>(u) << " " << get<1>(u) << " " << get<2>(u) << "\n";
        }
    } else {
        int f = -1, ps = len + 10, f2 = 0, f3 = 0;
        for (int i = 0; i < 3; ++i) {
            if (p[i] != -1 && p[i] < ps) {
                ps = p[i];
                f = i;
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (i != f) {
                f2 = i;
                break;
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (i != f2 && i != f) {
                f3 = i;
                break;
            }
        }
        cout << 2 << "\n";
        cout << ps + 2 << " " << ps + n - sum[f2][ps] + 1 << " " << char(f2 + 'A') << "\n";
        cout << ps + n - sum[f2][ps] + 2 << " " << 3 * n << " " << char(f3 + 'A') << "\n";
    }
    return 0;
}