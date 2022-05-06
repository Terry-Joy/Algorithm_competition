#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int len = 1;
		string s;
		cin >> s;
		bool flag = true;
		for (int i = 1; i < s.length(); ++i) {
			if (s[i] != s[i - 1]) {
				if (len <= 1) {
					flag = false;
				}
				len = 1;
			}
		}
		if (len <= 1) {
			flag = false;
		}
		cout << (flag ?"YES":"NO") << "\n";
	}
	return 0;
}