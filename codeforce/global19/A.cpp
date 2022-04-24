#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>a(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (is_sorted(a.begin(), a.end())) 
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}