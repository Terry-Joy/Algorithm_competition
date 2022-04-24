#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 5;
const int M = 65536;
int n, q, a[maxn];
struct SegmentTree {
#define lson p << 1, l, mid
#define rson p << 1 | 1, mid + 1, r
#define ls p << 1
#define rs p << 1 | 1
    int has[maxn << 2], add[maxn << 2], pw[maxn + 5], base, mod, mx[maxn << 2],
        sum[maxn + 5];
    void pushUp(int p, int l, int r, int mid) {
        has[p] = ((ll)has[ls] * pw[r - mid] + has[rs]) % mod;
        mx[p] = max(mx[ls], mx[rs]);
    }
    void pushDown(int p, int l, int r, int mid) {
        has[ls] = (has[ls] + (ll)add[p] * sum[mid - l + 1]) % mod;
        has[rs] = (has[rs] + (ll)add[p] * sum[r - mid]) % mod;
        mx[ls] += add[p];
        mx[rs] += add[p];
        add[ls] += add[p];
        add[rs] += add[p];
        add[p] = 0;
    }
    void update_mod(int p, int l, int r) {
        if (mx[p] < M)
            return;
        if (l == r) {
            has[p] -= M;
            mx[p] -= M;
            return;
        }
        int mid = l + r >> 1;
        if (add[p])
            pushDown(p, l, r, mid);
        if (mx[ls] >= M)
            update_mod(lson);
        if (mx[rs] >= M)
            update_mod(rson);
        pushUp(p, l, r, mid);
    }
    void update(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            has[p] = (has[p] + sum[r - l + 1]) % mod;
            add[p]++;
            mx[p]++;
            return;
        }
        int mid = l + r >> 1;
        if (add[p])
            pushDown(p, l, r, mid);
        if (L <= mid)
            update(lson, L, R);
        if (R > mid)
            update(rson, L, R);
        pushUp(p, l, r, mid);
    }
    void build(int p, int l, int r) {
        add[p] = 0;
        if (l == r) {
            has[p] = a[l];
            mx[p] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(lson);
        build(rson);
        pushUp(p, l, r, mid);
    }
    int query(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R)
            return has[p];
        int mid = l + r >> 1;
        if (add[p])
            pushDown(p, l, r, mid);
        int ans = 0;
        if (L <= mid)
            ans = (ans + query(lson, L, R)) % mod;
        if (R > mid)
            ans = ((ll)ans * pw[min(r, R) - mid] + query(rson, L, R)) % mod;
        return ans;
    }
} tr[2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    tr[0].base = 131;
    tr[1].base = 13331;
    tr[0].mod = 1e9 + 7;
    tr[1].mod = 1e9 + 9;
    for (int j = 0; j < 2; ++j)
        tr[j].pw[0] = 1, tr[j].sum[1] = 1;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j < 2; ++j) {
            tr[j].pw[i] = (ll)tr[j].pw[i - 1] * tr[j].base % tr[j].mod;
            tr[j].sum[i + 1] = (tr[j].sum[i] + tr[j].pw[i]) % tr[j].mod;
        }
    }
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int j = 0; j < 2; ++j)
        tr[j].build(1, 1, n);
    int op, l, r, c;
    for (int i = 1; i <= q; ++i) {
        cin >> op >> l >> r;
        if (op == 1) {
            for (int j = 0; j < 2; ++j) {
                tr[j].update(1, 1, n, l, r);
                tr[j].update_mod(1, 1, n);
            }
        } else {
            cin >> c;
            int y1 = l + c - 1, y2 = r + c - 1;
            int x[4], f = 0;
            for (int j = 0; j < 2; ++j) {
                x[f++] = tr[j].query(1, 1, n, l, y1);
                x[f++] = tr[j].query(1, 1, n, r, y2);
            }
            if (x[0] == x[1] && x[2] == x[3]) {
                cout << "yes\n";
            } else
                cout << "no\n";
        }
    }
    return 0;
}