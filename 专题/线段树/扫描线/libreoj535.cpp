#include<bits/stdc++.h>
#define eb emplace_back
#define ls p << 1
#define rs p << 1 | 1
#define lson p << 1, l, mid
#define rson p << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
const int maxn = 3e5 + 5;
struct Line {
	int l, r, op, y;
	Line(int m_l, int m_r, int m_op, int m_y) : l(m_l), r(m_r), op(m_op), y(m_y) { }
	bool operator<(const Line& x) const {
		if (y == x.y) 
			return op > x.op;
		return y < x.y;
	}
};	
struct BIT{
	#define lowb(x) (x&(-x))
	vector<int> c;
	int N;
	void init(int n) {
		N = n;
		c.resize(n + 1);
	}
	void add(int x, int val) {
		for (int i = x; i <= N; i += lowb(i)) {
			c[i] += val;
		}
	}
	int ask(int x) {
		int ans = 0;
		for (int i = x; i; i -= lowb(i)) {
			ans += c[i];
		}
		return ans;
	}
}bit;
struct SegmentTree {
	int mx[maxn << 2], add[maxn << 2];
	void pushUp(int p) {
		mx[p] = max(mx[ls], mx[rs]);
	}
	void pushDown(int p) {
		mx[ls] += add[p];
		mx[rs] += add[p];
		add[ls] += add[p];
		add[rs] += add[p];
		add[p] = 0;
	}
	void update(int p, int l, int r, int L, int R, int val) {
		if (L <= l && r <= R) {
			mx[p] += val;
			add[p] += val;
			return;
		}
		if (add[p])
			pushDown(p);
		int mid = l + r >> 1;
		if (L <= mid) 
			update(lson, L, R, val);
		if (R > mid)
			update(rson, L, R, val);
		pushUp(p);
	}
}tr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> lmx(n + 1), rmn(n + 1), h(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	ll ans = 0;
	bit.init(n);
	for (int i = n; i; --i) {
		ans += bit.ask(h[i]);
		bit.add(h[i], 1);
	}
	lmx[1] = h[1];
	for (int i = 2; i <= n; ++i) {
		lmx[i] = max(lmx[i - 1], h[i]);
	}
	rmn[n] = h[n];
	for (int i = n - 1; i; --i) {
		rmn[i] = min(rmn[i + 1], h[i]);
	}
	vector<Line> line;
	for (int i = 1; i <= n; ++i) {
		int l = lower_bound(lmx.begin() + 1, lmx.end(), h[i]) - lmx.begin();
		int r = upper_bound(rmn.begin() + 1, rmn.end(), h[i]) - rmn.begin() - 1;
		if (l >= r || r <= i || l >= i)
			continue;
		//cout << l << " " << i - 1 << " " << r << endl;
		line.eb(l, i - 1, 1, i + 1);
		line.eb(l, i - 1, -1, r);
	}
	sort(line.begin(), line.end());
	int mx = 0;
	for (auto [l, r, op, y] : line) {
		mx = max(tr.mx[1], mx);
		tr.update(1, 1, n, l, r, op);
	}
	cout << ans - 2 * mx;
	return 0;
}