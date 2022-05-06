#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		string s1, s2;
		bool f1 = true, f2 = true;
		bool ans = true;
		int sum0 = 0, sum1 = 0;
		cin >> s1 >> s2;
		for (int i = 0; i < n; i++) {
			if (s1[i] == '1')
				sum1++;
			else
				sum0++;
			f1 &= (s1[i] == s2[i]);
			f2 &= (s1[i] != s2[i]);
			ans &= f1;
			if (sum1 == sum0) {
				ans |= f2;
				f1 = f2 = true;
				if (!ans) {
					break;
				}
			}
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}