#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int x = n;
		int bit = 1;
		while (x) {
			bit *= 10;
			x /= 10;
		}
		vector<bool> vis(m + 1, false);
		if (m == 1) {
			cout << 0 << "\n";
			continue;
		}
		int now = 0, ans = 0;
		for (int i = 1; ; ++i) {
			now = ((ll)now * bit + n) % m;
			if (!now) {
				ans = i;
				break;
			}
			if (vis[now]) {
				ans = -1;
				break;
			}
			vis[now] = true;
		}
		cout << ans;
		if (t)
			cout << "\n";
	}
	return 0;
}