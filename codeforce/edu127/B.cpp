#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n, 0);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (a[n - 1] - a[0] <= n + 1) { 
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}