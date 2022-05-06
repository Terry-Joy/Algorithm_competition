#include<bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
const int M = 1000000;
int n, m, cnt, fa[maxn], sz[maxn];
int find(int x) { 
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}
int main() {
	n = 200000;
	cout << n << "\n";
	for (int i = 1; i <= n; ++i) {
		fa[i] = i, sz[i] = 1;
	}
	srand(time(0));
	while (cnt < n - 1) {
		int x = rand() % n + 1, y = rand() % n + 1;
		int xx = find(x), yy = find(y);
		if (xx == yy)
			continue;
		if (sz[xx] > sz[yy]) {
			swap(xx, yy);
		}
		sz[yy] += sz[xx];
		fa[xx] = yy;
		cnt++;
		int w = rand() % M + 1;
		cout << x << " " << y << " " << w;
		if (cnt != n - 1) {
			cout << "\n";
		}
	}
	return 0;
}