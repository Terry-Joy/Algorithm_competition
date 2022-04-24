#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5 + 5;
const ll mod = 998244353;
ll fac[maxn], facinv[maxn];
ll mypow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    int n, m, k;
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto init = [&]() {
        fac[0] = fac[1] = 1;
        for (int i = 2; i < maxn; ++i)
            fac[i] = (ll)fac[i - 1] * i % mod;
        facinv[maxn - 1] = mypow(fac[maxn - 1], mod - 2);
        for (int i = maxn - 2; i >= 0; --i)
            facinv[i] = (ll)facinv[i + 1] * (i + 1) % mod;
    };
    init();
    auto C = [&](int n, int m) -> ll {
        if (n < m || n < 0 || m < 0)
            return 0;
        return fac[n] * facinv[n - m] % mod * facinv[m] % mod;
    };
    auto f = [&](int n, int m, int k) {
        ll res = 0;
        for (int i = 0; i <= n; ++i) {
            ll op = (i & 1) ? -1 : 1;
            res = (res + op * C(n, i) * C(m + n - i * (k + 1) - 1, n - 1));
            if (op == -1)
                res = (res + mod) % mod;
            else
                res %= mod;
        }
        return res;
    };
    cin >> n >> m >> k;
    n = n - m + 1;
    if (k)
        cout << (f(n, m, k) - f(n, m, k - 1) + mod) % mod;
    else
        cout << f(n, m, k);
    return 0;
}