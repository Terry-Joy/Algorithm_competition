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
	for (int i = 0; i < n; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a.begin(), a.end(), [&](P x, P y) { 
		if (x.fi == y.fi) 
			return x.se > y.se;
		return x.fi < y.fi;
	});
	int now = 1;
	ll ans = 0;
	priority_queue<int, vector<int>, greater<int> >q;
	for (int i = 0; i < n; ++i) {
		if (now <= a[i].fi) {
			ans += a[i].se;
			q.push(a[i].se);
			now++;
		} else {
			if (!q.empty() && q.top() < a[i].se) {
				ans += a[i].se - q.top();
				q.pop();
				q.push(a[i].se);
			}
		}
	}
	cout << ans;
	return 0;
}