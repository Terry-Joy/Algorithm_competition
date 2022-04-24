#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    ll ans = 0;
    cin >> n;
    int a, b;
    vector<int> tmp;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        ans += b;
        tmp.emplace_back(a + b);
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) {
        ans -= tmp[i];
    }
    cout << ans;
    return 0;
}