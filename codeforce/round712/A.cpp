#include<bits/stdc++.h>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool flag = false;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != 'a') {
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			string s1 = "a" + s;
			auto check = [&](string x) {
				string s2 = x;
				reverse(s2.begin(), s2.end());
				for (int i = 0; i < s2.length(); i++) {
					if (s2[i] != x[i]) {
						return false;
					}
				}
				return true;
			};
			if (!check(s1)) {
				cout << s1 << "\n";
			} else {
				s1 = s + "a";
				cout << s1 << "\n";
			}
		}
	}
	return 0;
}