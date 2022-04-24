#include<bits/stdc++.h>

#define fp(i, a, b) for(int i = (a), _##i = (b) + 1; i < _##i; ++i)
#define fd(i, a, b) for(int i = (a), _##i = (b) - 1; i > _##i; --i)
using namespace std;
using ll = int64_t;
const int N = 1e5 + 5;
struct qry { int l, r, id; } q[N];
int a[N], b[N], pr[N], nx[N];
vector<int> f1[N], f2[N], f3[N], p1[315], p2[315];
int main() {
    int n, m, B, S, T; ll val = 0;
    scanf("%d%d", &n, &m), B = sqrt(n) + 1, S = n / sqrt(m) + 1, T = n / B + 1;
    vector<int> pos(n); vector<ll> ans(m);
    fp(i, 1, n) scanf("%d", a + i), --a[i];
    fp(i, 0, m - 1) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
    sort(q, q + m, [&](qry a, qry b) { return a.l / S == b.l / S ? (a.l / S & 1 ? a.r > b.r : a.r < b.r) : a.l < b.l; });
    fp(t, 0, T - 1) {
        int L = t * B + 1, R = min(n, L + B - 1);
        p1[t].assign(n, 0), p2[t] = p1[t];
        fp(i, L, R) {
            auto &f = f2[i];
            pr[i] = pos[a[i]], pos[a[i]] = i, b[i] = t;
            f.assign(R - i + 1, 0), f[0] = 1, p2[t][a[i]] = i;
            fp(j, i + 1, R) f[j - i] = f[j - i - 1] + (a[j] == a[i] + f[j - i - 1]);
            f1[i].assign(T + 1, 0), f1[i][t + 1] = f[R - i];
        }
        fd(i, R, L) {
            auto &f = f3[i];
            f.assign(i - L + 1, 0), f[0] = 1, p1[t][a[i]] = i;
            fd(j, i - 1, L) f[i - j] = f[i - j - 1] + (a[j] == a[i] - f[i - j - 1]);
            f1[i][t] = f[i - L];
            fd(k, b[i] - 1, 0) f1[i][k] = f1[i][k + 1] + (a[i] >= f1[i][k + 1] && p2[k][a[i] - f1[i][k + 1]] ? f3[p2[k][a[i] - f1[i][k + 1]]].back() : 0);
        }
    }
    pos.assign(n, n + 1);
    fd(i, n, 1) {
        nx[i] = pos[a[i]], pos[a[i]] = i;
        fp(k, b[i] + 1, T - 1) f1[i][k + 1] = f1[i][k] + (a[i] + f1[i][k] < n && p1[k][a[i] + f1[i][k]] ? f2[p1[k][a[i] + f1[i][k]]].back() : 0);
    }
    auto f = [&](int L, int R) {
        if (L > R) return 0;
        if (b[L] == b[R]) return f2[L][R - L];
        int w = f1[L][b[R]], nx = a[L] + w, p;
        if (nx < n && (p = p1[b[R]][nx]) && p <= R) w += f2[p][R - p];
        return w;
    };
    auto g = [&](int L, int R) {
        if (L > R) return 0;
        if (b[L] == b[R]) return f3[R][R - L];
        int w = f1[R][b[L] + 1], nx = a[R] - w, p;
        if (nx >= 0 && (p = p2[b[L]][nx]) && p >= L) w += f3[p][p - L];
        return w;
    };
    int L = 1, R = 0;
    fp(i, 0, m - 1) {
        int ql = q[i].l, qr = q[i].r;
        while (L > ql) --L, val += f(L, R) - f(nx[L], R);
        while (R < qr) ++R, val += g(L, R) - g(L, pr[R]);
        while (L < ql) val -= f(L, R) - f(nx[L], R), L++;
        while (R > qr) val -= g(L, R) - g(L, pr[R]), R--;
        ans[q[i].id] = val;
    }
    for (auto w: ans) printf("%lld\n", w);
    return 0;
}
