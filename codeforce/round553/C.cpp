#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
ll inv2 = (mod + 1) / 2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll l, r;
	cin >> l >> r;
	auto sum = [&](ll x) { 
		ll num = 0, even = 0, odd =0;
		while (x > 0) {
			if (num & 1) {
				even += min(x, 1ll << num);
			} else {
				odd += min(x, 1ll << num);
			}
			x -= 1ll << num;
			num++;
		}
		odd %= mod;
		even %= mod;
		odd = odd * odd % mod;
		even = even * (even + 1) % mod;
		return (odd + even) % mod;
	};
	cout << (sum(r) - sum(l - 1) + mod) % mod;
	return 0;
}