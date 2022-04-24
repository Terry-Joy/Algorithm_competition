#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, X, R, P, K;
	cin >> n >> X >> R >> P >> K;
	string s;
	cin >> s;
	vector<ll> tmp;
	ll ans = (ll)n * X;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			tmp.emplace_back(((ll)n - i) * P);
		}else {
			tmp.emplace_back(((ll)n - i) * (P + R));
			ans -= ((ll)n - i) * R;
		}
	}		
	sort(tmp.begin(), tmp.end(),[&](ll x, ll y) {
		return x > y;
	});
	for (int i = 0; i < K; ++i) {
		ans += tmp[i];
	}
	cout << ans;
	return 0;
}