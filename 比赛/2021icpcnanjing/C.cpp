#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n, 0);
	vector<vector<int>> pos(4e6 + 1); 
	vector<int> cnt(3e6 + 1, 0);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] += 2e6;
		cnt[a[i]]++;
		ans = max(ans, cnt[a[i]]);
		pos[a[i]].eb(a[i]);
		if (k)
			pos[a[i] + k].eb(a[i]);
	}
	for (int i = 1e6 + k; i <= 3e6 + k; ++i) {
		if (pos[i].empty()) 
			continue;
		vector<vector<int>> sum(pos[i].size(), vector<int>(2, 0));
		sum[0][0] = (pos[i][0] == i - k);
		sum[0][1] = (pos[i][0] == i);
		for (int j = 1; j < pos[i].size(); ++j) {
			sum[j][0] = sum[j - 1][0] + (pos[i][j] == i - k);
			sum[j][1] = sum[j - 1][1] + (pos[i][j] == i);
		}
		int num = sum[pos[i].size() - 1][1];
		int mx = 0;
		for (int j = 0; j < pos[i].size(); ++j) {
			ans = max(ans, num + sum[j][0] - sum[j][1] + mx);
			mx = max(mx, sum[j][1] - sum[j][0]);
		}
	}
	cout << ans;
	return 0;
}