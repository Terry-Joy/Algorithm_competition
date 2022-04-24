#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    n <<= 1;
    string s;
    cin >> s;
    int cntA = 0, cntB = 0, cntC = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A')
            cntA++;
        else if (s[i] == 'B')
            cntB++;
        else
            cntC++;
    }
    int ab = (cntA + cntB - cntC) / 2, ac = (cntA - cntB + cntC) / 2,
        bc = (-cntA + cntB + cntC) / 2;
    if (ab < 0 || ac < 0 || bc < 0) {
        cout << "NO";
        return 0;
    }
    int fi = s.find_first_of('B'), ed = s.find_last_of('B');
    if ((fi == -1 && (ab + bc) > 0) || (ed == -1 && (ab + bc) > 0)) {
        cout << "NO";
        return 0;
    }
    int p1 = fi, p2 = ed;
    vector<bool> vis(n, 0);
    vector<pair<int, int>> ans;
    bool f = 1;
    if (bc) {
        for (int i = fi; i < n; ++i) {
            if (s[i] == 'B') {
                vis[i] = true;
                while (p1 < n) {
                    if (s[p1] == 'C' && !vis[p1] && p1 > i) {
                        vis[p1] = true;
                        ans.emplace_back(make_pair(i, p1));
                        p1++;
                        bc--;
                        break;
                    }
                    p1++;
                }
            }
            if (!bc || p1 == n)
                break;
        }
    }
    if (bc)
        f = 0;
    if (ab) {
        for (int i = ed; i >= 0; --i) {
            if (s[i] == 'B') {
                if (vis[i]) {
                    f = 0;
                    break;
                }
                vis[i] = true;
                while (p2 >= 0) {
                    if (s[p2] == 'A' && !vis[p2] && p2 < i) {
                        vis[p2] = true;
                        ans.emplace_back(make_pair(p2, i));
                        p2--;
                        ab--;
                        break;
                    }
                    p2--;
                }
                if (!ab || p2 == -1)
                    break;
            }
        }
    }
    if (ab)
        f = 0;
    if (ac) {
        p1 = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A' && !vis[i]) {
                p1 = i;
                break;
            }
        }
        if (p1 == -1) {
            f = 0;
        }
        p2 = p1;
        for (int i = p1; i < n; ++i) {
            if (s[i] == 'A' && !vis[i]) {
                vis[i] = true;
                while (p2 < n) {
                    if (s[p2] == 'C' && !vis[p2] && p2 > i) {
                        vis[p2] = true;
                        ans.emplace_back(make_pair(i, p2));
                        p2++;
                        ac--;
                        break;
                    }
                    p2++;
                }
                if (!ac || p2 == n)
                    break;
            }
        }
    }
    if (ac)
        f = 0;
    if (!f) {
        cout << "NO";
        return 0;
    }
    cout << "YES"
         << "\n";
    for (auto [u, v] : ans) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
    return 0;
}