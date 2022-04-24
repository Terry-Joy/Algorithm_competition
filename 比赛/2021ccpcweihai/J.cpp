#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << b * 180 / __gcd(b * 180, a) - 1 << "\n";
    }
    return 0;
}