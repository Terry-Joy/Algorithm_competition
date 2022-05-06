#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll ans = 0;
		int n, x;
		cin >> n >> x;
		vector<ll> a(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = 1; i < n; ++i) {
			a[i] += a[i - 1];
		}
		int sum = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] + sum * (i + 1) > x)
				continue;
			int l = 0, r = 1e9;
			while (l < r) {
				int mid = l + r + 1 >> 1;
				if (a[i] + (sum + mid) * (ll)(i + 1) <= x) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			ans += (l + 1) * (i + 1);
			sum += l + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}