#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<P> a(n);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].fi >> a[i].se;
		ans += a[i].se;
	}
	sort(a.begin(), a.end());
	int mx = a[0].fi + a[0].se;
	for (int i = 1; i < n; ++i) {
		ans += max(0, a[i].fi - mx);
		mx = max(mx, a[i].fi + a[i].se);
	}
	cout << ans;
	return 0;
}