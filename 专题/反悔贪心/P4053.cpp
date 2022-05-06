#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using P = pair<int,int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<P> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].se >> a[i].fi;
	}
	sort(a.begin(), a.end());
	int now = 0, ans = 0;
	priority_queue<int> q;
	for(auto [u, v] : a) {
		if (now + v <= u) {
			ans++;
			now += v;
			q.emplace(v);
		} else {
			if (!q.empty() && q.top() > v) {
				now -= q.top() - v;
				q.pop();
				q.emplace(v);
			}
		}
	}
	cout << ans;
	return 0;
}