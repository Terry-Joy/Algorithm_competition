#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<P> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].fi;
	for (int i = 0; i < n; i++)
		cin >> a[i].se;
	priority_queue<P> q;
	ll now = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int u = a[i].fi, v = a[i].se;
		now += u;
		if (now >= v) {
			now -= v;
			q.push({v, i + 1});
			ans++;
		} else {
			if (!q.empty() && q.top().fi > v) {
				now += q.top().fi - v;
				q.pop();
				q.push({v, i + 1});
			}
		}
	}
	cout << ans << "\n";
	while (!q.empty()) {
		cout << q.top().se << " ";
		q.pop();
	}
	return 0;
}