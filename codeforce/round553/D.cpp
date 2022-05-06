#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b) {
		return a.first - a.second > b.first - b.second;
	});
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (ll)i * (a[i - 1].first - a[i - 1].second) + (ll)a[i - 1].second * n - a[i - 1].first;
	}
	cout << ans;
	return 0;
}