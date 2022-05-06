#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n;
	cin >> s;
	int ans = 1e9;
	unordered_map<int, char> mp;
	mp[0] = 'A'; mp[1] = 'C'; mp[2] = 'T'; mp[3] = 'G';
	for (int i = 0; i <= n - 4; ++i) {
		int mn = 0;
		for (int j = i; j < i + 4; ++j) {
			if (s[j] >= mp[j - i]) {
				mn += min(s[j] - mp[j - i], 'Z' - s[j] + mp[j - i] - 'A' + 1);
			} else {
				mn += min(mp[j - i] - s[j], 'Z' - mp[j - i] + s[j] - 'A' + 1);
			}
		}
		ans = min(ans, mn);
	}
	cout << ans;
	return 0;
}