#include <bits/stdc++.h>
#define lson lc[p], l, mid
#define rson rc[p], mid + 1, r
#define ls lc[p]
#define rs rc[p]
using namespace std;
const int INF = 1e9;
const int maxn = 2.5e5 + 5;
const int N = 36 * maxn;

int rt[maxn], a[4][maxn], n, k, q, sum;
struct Persistent_SegmentTree {
    int mn[16][N], tag1[4][N], tag2[4][N], lc[N], rc[N], tot;
    int newNode(int x) {
        int p = ++tot;
        ls = lc[x];
        rs = rc[x];
        for (int i = 0; i < k; ++i) {
            tag1[i][p] = tag1[i][x];
            tag2[i][p] = tag2[i][x];
        }
		for(int i = 0; i < sum; ++i)
            mn[i][p] = mn[i][x];
        return p;
    }
    void pushUp(int p) {
        for (int i = 0; i < sum; ++i)
            mn[i][p] = min(mn[i][ls], mn[i][rs]);
    }
    void build(int &p, int l, int r) {
        p = ++tot;
        for (int i = 0; i < k; ++i) {
            tag2[i][p] = INF;
        }
        if (l == r) {
			for (int i = 0; i < sum; ++i) {
				for (int j = 0; j < k; ++j) {
					if (i & (1 << j)) {
						mn[i][p] += a[j][l];
					}
				}
			}
            return;
        }
        int mid = l + r >> 1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void add_Tag2(int p, int x, int val) {
        tag2[x][p] = val;
        tag1[x][p] = 0;
        for (int i = 1; i < sum; ++i) {
            if (i & (1 << x))
                mn[i][p] = mn[i ^ (1 << x)][p] + val;
        }
    }
    void add_Tag1(int p, int x, int val) {
        tag1[x][p] += val;
        for (int i = 0; i < sum; ++i)
            if (i & (1 << x))
                mn[i][p] += val;
    }
    void pushDown(int p) {
        ls = newNode(ls);
        rs = newNode(rs);
        for (int i = 0; i < k; ++i) {
            if (tag2[i][p] != INF) {
                add_Tag2(ls, i, tag2[i][p]);
                add_Tag2(rs, i, tag2[i][p]);
                tag2[i][p] = INF;
            }
            if (tag1[i][p]) {
                add_Tag1(ls, i, tag1[i][p]);
                add_Tag1(rs, i, tag1[i][p]);
                tag1[i][p] = 0;
            }
        }
    }
    void update(int &p, int l, int r, int L, int R, int op, int x,
                int val) {
        if (L <= l && r <= R) {
            if (op == 1) {
                add_Tag1(p, x, val);
            } else
                add_Tag2(p, x, val);
            return;
        }
        pushDown(p);
        int mid = l + r >> 1;
        if (L <= mid)
            update(lson, L, R, op, x, val);
        if (R > mid)
            update(rson, L, R, op, x, val);
        pushUp(p);
    }
    int query(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return mn[sum - 1][p];
        }
        pushDown(p);
        int ans = INF;
        int mid = l + r >> 1;
        if (L <= mid)
            ans = min(ans, query(lson, L, R));
        if (R > mid)
            ans = min(ans, query(rson, L, R));
        return ans;
    }
} tr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> n >> q;
    sum = (1 << k);
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    tr.build(rt[0], 1, n);
    for (int i = 1; i <= q; ++i) {
        int op, t, p, l, r, x;
        cin >> op >> t;
        if (op == 1) {
			rt[i] = tr.newNode(rt[t]);
            cin >> p >> l >> r >> x;
            tr.update(rt[i], 1, n, l, r, 1, p - 1, x);
        } else if (op == 2) {
			rt[i] = tr.newNode(rt[t]);
			cin >> p >> l >> r >> x;
            tr.update(rt[i], 1, n, l, r, 2, p - 1, x);
        } else {
			rt[i] = rt[t];
			cin >> l >> r;
            cout << tr.query(rt[i], 1, n, l, r) << "\n";
        }
    }
    return 0;
}