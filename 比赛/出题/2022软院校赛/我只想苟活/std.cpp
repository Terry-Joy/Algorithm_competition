#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
ll sum[maxn];
int cnt;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	priority_queue<int, vector<int>,greater<int> >q;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] < 0) { 
			q.emplace(-a[i]);
		} else {
			while (!q.empty()) {
				int x = q.top();
				q.pop();
				if (a[i] >= x) {
					a[i] -= x;
				} else {
					q.emplace(x - a[i]);
					break;
				}
			}			
		}
	}
	while (!q.empty()) {
		sum[++cnt] = q.top();
		q.pop();
	}
	for (int i = 1; i <= cnt; ++i) {
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		if (x >= sum[cnt]) {
			cout << n - 0;
		} else {
			x = cnt - (upper_bound(sum + 1, sum + 1 + cnt, x) -sum) + 1;
			cout << n - x;
		}
		if (i != m) {
			cout << '\n';
		}
	}
	return 0;
}