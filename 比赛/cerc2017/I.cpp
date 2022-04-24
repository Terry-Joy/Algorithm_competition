#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using P = pair<int, int>;
const int maxn = 1e5 + 5;
int n, m, a[maxn], p[maxn], l, r;

vector<P> G[maxn];
priority_queue<P> q;

struct SegmentTree {
#define lson p << 1, l, mid
#define rson p << 1 | 1, mid + 1, r
#define ls p << 1
#define rs p << 1 | 1
    int mx[maxn << 2], pos[maxn << 2], add[maxn << 2]; // mx维护a[i]+i
    void pushUp(int p) {
        mx[p] = max(mx[ls], mx[rs]);
        if (mx[ls] > mx[rs])
            pos[p] = pos[ls];
        else
            pos[p] = pos[rs];
    }
    void build(int p, int l, int r) {
        if (l == r) {
            mx[p] = pos[p] = l;
            return;
        }
        int mid = l + r >> 1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void pushDown(int p) {
        mx[ls] += add[p];
        mx[rs] += add[p];
        add[ls] += add[p];
        add[rs] += add[p];
        add[p] = 0;
    }
    void update(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            mx[p]++;
            add[p]++;
            return;
        }
        if (add[p])
            pushDown(p);
        int mid = l + r >> 1;
        if (L <= mid)
            update(lson, L, R);
        if (R > mid)
            update(rson, L, R);
        pushUp(p);
    }
    P query(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R)
            return {mx[p], pos[p]};
        if (add[p])
            pushDown(p);
        int mid = l + r >> 1;
        P a(0, 0), b(0, 0);
        if (L <= mid)
            a = query(lson, L, R);
        if (R > mid)
            b = query(rson, L, R);
        return (a.fi > b.fi) ? a : b;
    }
} tr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], p[a[i]] = i;
    cin >> m;
    vector<P> ans(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> l >> r;
        G[r].emplace_back(P(l, i));
    }
    tr.build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 1 && p[a[i] - 1] <= i)
            tr.update(1, 1, n, 1, p[a[i] - 1]);
        if (a[i] < n && p[a[i] + 1] <= i)
            tr.update(1, 1, n, 1, p[a[i] + 1]);
        for (auto &u : G[i])
            q.push(u);
        auto judge = [&](P a, int r) -> bool {
            P x = tr.query(1, 1, n, 1, a.fi);
            if (x.fi == r) {
                ans[a.se] = {x.se, r};
                return 1;
            }
            return 0;
        };
        while (!q.empty()) {
            if (judge(q.top(), i))
                q.pop();
            else
                break;
        }
    }
    for (int i = 1; i <= m; ++i)
        cout << ans[i].fi << " " << ans[i].se << "\n";
    return 0;
}