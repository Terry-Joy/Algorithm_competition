#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<char> ans1, ans2;
		if (s[0] != '1' || s[n - 1] != '1') {
			cout << "NO\n";
			continue; 
		} else {
			int sum0 = 0, sum1 = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '0') 
					sum0++;
				else
					sum1++; 
			}
			if (sum0 & 1) {
				cout << "NO\n";
				continue;
			}
			int sum = sum1;
			for (int i = 0; i < n; ++i) {
				if (s[i] == '1') {
					if (sum1 > sum / 2) {
						ans1.eb('(');
						ans2.eb('(');
					} else {
						ans1.eb(')');
						ans2.eb(')');
					}
					sum1--;
				} else {
					if (sum0 & 1) {
						ans1.eb('(');
						ans2.eb(')');
					} else {
						ans1.eb(')');
						ans2.eb('(');
					}
					sum0--;
				}
			}
			cout << "YES\n";
			for (auto u : ans1) {
				cout << u;
			}
			cout << "\n";
			for (auto u : ans2) {
				cout << u;
			}
			cout << "\n";
		}
	}
	return 0;
}