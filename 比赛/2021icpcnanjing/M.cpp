#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n, 0);
		bool f = false, f2 = false;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] > 0) { 
				f = true;
			}
			if (a[i] < 0) { 
				f2 = true;
			}
			sum += abs(a[i]);
		}
		if (n == 1) {
			cout << a[0] << "\n";
			continue;
		}
		if (f && f2) {
			cout << sum << "\n";
		} else if (f) {
			cout << sum - 2 * (*min_element(a.begin(), a.end())) << "\n";
		} else {
			cout << sum + 2 * (*max_element(a.begin(), a.end())) << "\n";
		}
	}
	return 0;
}