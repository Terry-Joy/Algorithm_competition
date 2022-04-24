#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    n++;
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    ll ans = 0;
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] < b[i]) {
            ans += (b[i] - a[i] + 1) / 2;
            a[i - 1] -= (b[i] - a[i] + 1) / 2;
        }
    }
    cout << ((a[0] < b[0]) ? -1 : ans);
    return 0;
}