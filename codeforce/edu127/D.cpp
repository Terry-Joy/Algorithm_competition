#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		vector<ll> a(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int mn = *min_element(a.begin(), a.end());
		int mx = *max_element(a.begin(), a.end());
		ll ans = 0;
		for (int i = 1; i < n; ++i) {
			ans += abs(a[i] - a[i - 1]);
		}
		ll add = 1e9;
		add = min((a[0] - 1), min(a[n - 1] - 1, 2ll * (mn - 1)));
		ans += add;
		if (x > mx) {
			add = 1e9;
			add = min((x - a[0]), min(x - a[n - 1], 2ll * (x - mx)));
			ans += add;
		}
		cout << ans << '\n';
	}
	return 0;
}