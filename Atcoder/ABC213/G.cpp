
#include <bits/stdc++.h>
#define cbit(x) __builtin_popcount(x)
using namespace std;
using ll = long long;
const int maxn = (1 << 18) + 100;
const int mod = 998244353;
int f[20][maxn], g[20][maxn], c[20][maxn], cnt[maxn], n, m, G[19][19],
    pw2[18 * 18], h[maxn], ans[maxn];
int mul(int x, int y) { return (ll)x * y % mod; }
int Add(int x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}
int Sub(int x, int y) {
    x -= y;
    if (x < 0)
        x += mod;
    return x;
}
void fwt(int a[], bool f, int lim) {
    for (int l = 2, m = 1; l <= lim; l <<= 1, m <<= 1) {
        for (int j = 0; j < lim; j += l) {
            for (int i = 0; i < m; ++i) {
                if (!f)
                    a[i + j + m] = Add(a[i + j + m], a[i + j]);
                else
                    a[i + j + m] = Sub(a[i + j + m], a[i + j]);
            }
        }
    }
}
int getlim(int x) {
    int lim = 1;
    while (lim < x)
        lim <<= 1;
    return lim;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> m;
    int lim = (1 << n), u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        G[u][v] = G[v][u] = 1;
    }
    pw2[0] = 1;
    for (int i = 1; i <= m; ++i) {
        pw2[i] = mul(pw2[i - 1], 2);
    }
    for (int i = 1; i < lim; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((G[j][k] || G[k][j]) &&
                    ((i & (1 << j) && (i & (1 << k))))) {
                    cnt[i]++;
                }
            }
        }
    }
    for (int i = 1; i < lim; ++i)
        f[cbit(i)][i] = g[cbit(i)][i] = pw2[cnt[i]];
    for (int i = 1; i <= n; ++i)
        fwt(g[i], 0, lim), fwt(f[i], 0, lim);
    for (int i = 1; i <= n; ++i) {
        fwt(f[i], 1, lim);
        for (int j = 1; j < lim; ++j) { //进来的时候第i层子集和已经算完，统计答案
            if (cbit(j) == i) {
                h[j] = f[i][j];
            }
        }
        if (i == n) break;
        for (int j = 1; j < lim; ++j) { //保证有1，不重不漏
            if (!(1 & j))
                f[i][j] = 0;
        }
        fwt(f[i], 0, lim);
        for (int j = 0; j + i <= n; ++j) {
            for (int S = 0; S < lim; ++S) {
                f[i + j][S] = Sub(f[i + j][S], mul(f[i][S], g[j][S]));
            }
        }
    }
    for (int j = 1; j < lim; ++j)
        h[j] = mul(h[j], pw2[cnt[(lim - 1) ^ j]]);
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < lim; ++j) {
            if ((j & 1) && (j & (1 << (i - 1))))
                ans[i] = Add(ans[i], h[j]);
        }
    }
    for (int i = 2; i <= n; ++i)
        cout << ans[i] << "\n";
    return 0;
}
