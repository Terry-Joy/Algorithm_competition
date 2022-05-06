#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1, 0), b(n + 1, 0), suma(n + 1, 0), sumb(n + 1, 0);
	vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
	vector<vector<int> > mx(n + 1, vector<int>(n + 1, 0));
	vector<vector<int> > f(mx), g(mx);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	auto pre = [&](int i, int j, bool flag) {
		if (flag) {
			return sumb[j] - sumb[i];
		} else {
			return suma[j] - suma[i];
		}
	};
	auto init = [&]() { 
		for (int i = 2; i <= n; ++i) {
			suma[i] = suma[i - 1] + a[i];
		}
		for (int i = 2; i <= n; ++i) {
			sumb[i] = sumb[i - 1] + b[i];
		}
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				for (int k = i; k <= j; ++k) {
					f[i][j] = max(f[i][j], min(pre(i, k, 0), pre(k, j, 0) + pre(i, j, 1)));
					f[i][j] = max(f[i][j], min(pre(i, k, 1), pre(k, j, 1) + pre(i, j, 0)));
					g[i][j] = max(g[i][j], min(pre(k, j, 0), pre(i, k, 0) + pre(i, j, 1)));
					g[i][j] = max(g[i][j], min(pre(k, j, 1), pre(i, k, 1) + pre(i, j, 0)));
				}
			}
		}
	};
	init();
	return 0;
}