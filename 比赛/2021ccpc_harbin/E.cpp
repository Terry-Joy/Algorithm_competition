#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (!a[0]) {
			bool ok = false;
			for (int i = 0; i < n; i++) {
				if (a[i]) {
					ok = true;
					break;
				}
			}
			cout << (ok ? "-1\n" : "1\n"); 
			continue;
		}
		int M = 1;
		bool flag = false;
		for (int i = 1; i < n; ++i) {
			if (a[i] != a[i - 1] * 2) {
				M = 2 * a[i - 1] - a[i];
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "-1\n";
			continue;
		}
		bool flag2 = true;
		for (int i = 1; i < n; ++i) {
			if (a[i] != a[i - 1] * 2 % M) {
				flag2 = false;
				break;
			}
		}
		if (!flag2) {
			cout << "-1\n";
			continue;
		}
		cout << M << "\n";
	}
	return 0;
}