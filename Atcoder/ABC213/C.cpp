#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> a(n);
    vector<int> row, col;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].fi >> a[i].se;
        row.emplace_back(a[i].fi);
        col.emplace_back(a[i].se);
    }
    sort(all(row));
    sort(all(col));
    row.erase(unique(all(row)), row.end());
    col.erase(unique(all(col)), col.end());
    for (int i = 0; i < n; ++i) {
        a[i].fi = lower_bound(all(row), a[i].fi) - row.begin() + 1;
        a[i].se = lower_bound(all(col), a[i].se) - col.begin() + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i].fi << " " << a[i].se << "\n";
    }
    return 0;
}