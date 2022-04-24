#include<bits/stdc++.h>
#define lson p << 1, l, mid 
#define rson p << 1 | 1, mid + 1, r
#define ls p << 1
#define rs p << 1 | 1
using namespace std;
const int maxn = 5e5 + 5;
const int INF = 1e9 + 1;
int dp[maxn], a[maxn], b[maxn], c[maxn], cnt;
struct SegmentTree{
	int mn[maxn << 1], add[maxn << 1];
	void pushUp(int p) {
		mn[p] = min(mn[ls], mn[rs]);
	}
	void build(int p, int l, int r) {
		mn[p] = INF;
		if(l == r)
			return;
		int mid = l + r >> 1;
		build(lson);
		build(rson);
		pushUp(p);
	}
	int query(int p, int l, int r, int x) {
		if(l == r)
			return mn[p];
		int mid = l + r >> 1;
		if(x <= mid) 
			return query(lson, x);
		else
			return query(rson, x);
	}
	void update(int p, int l, int r, int L, int R, int val) {
		if (L <= l && r <= R) {
			mn[p] ++;
			add[p] ++;
			
		}
	}
}tr;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	tr.build();
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if(a[i - 1] < a[i])
			dp[i] = dp[i - 1];
		int pos = lower_bound(b + 1, b + 1 + m, a[i]) - b - 1;
		if(i > 1)
			dp[i] = min(dp[i], tr.query(1, 1, m, pos));
		tr.update(1, 1, m, 1, m - (i - 1));

	}
	return 0;
}