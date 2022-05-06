#include<bits/stdc++.h>
#define lson p << 1, l, mid 
#define rson p << 1 | 1, mid + 1, r
#define ls p << 1 
#define rs p << 1 | 1
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
const int INF = 2e9 + 5;
struct SegmentTree{
	int mx[maxn << 2];
	void pushUp(int p) { 
		mx[p] = max(mx[ls], mx[rs]);
	}
	void build(int p, int l, int r) {
		mx[p] = -INF;
		if (l == r)
			return;
		int mid = l + r >> 1;
		build(lson);
		build(rson);
	}
	void update(int p, int l, int r, int x, int val) {
		if (l == r) {
			mx[p] = val;
			return;
		}
		int mid = l + r >> 1;
		if (x <= mid) {
			update(lson, x, val);
		} else {
			update(rson, x, val);
		}
		pushUp(p);
	}
	int query(int p, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return mx[p];
		}
		int mid = l + r >> 1, ans = -INF;
		if (L <= mid) 
			ans = max(ans, query(lson, L, R));
		if (R > mid)
			ans = max(ans, query(rson, L, R));
		return ans;
	}
}tr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int M, D;
	cin >> M >> D;
	tr.build(1, 1, M);
	char s[2];
	ll x;
	int las = 0, cnt = 0;
	for (int i = 1; i <= M; ++i) {
		cin >> s >> x;
		if (s[0] == 'A') {
			x += las;
			cnt++;
			tr.update(1, 1, M, cnt, x % D);
		} else {
			las = tr.query(1, 1, M, cnt - x + 1, cnt);
			cout << las << "\n";
		}
	}
	return 0;
}