#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (ll)a[i] * (n - a[i] + 1);
	}
	for (int i = 0; i < n - 1; i++) {
		ans -= (ll) min(a[i], a[i + 1]) * (n - max(a[i], a[i + 1]) + 1);
	}
	cout << ans;
	return 0;
}