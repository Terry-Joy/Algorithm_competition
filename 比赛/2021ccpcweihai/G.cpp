#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e4 + 5;
const int mod = 998244353;
int n, m, fac[maxn], facinv[maxn];
int mypow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ll)ans * a % mod;
        }
        a = (ll)a * a % mod;
        b >>= 1;
    }
    return ans; 
}
int main() {
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
    cin >> n >> m;
    vector<int> cnt(1e5 + 1, 0), a;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
        if (cnt[x] == 1)
            a.emplace_back(x);
    }
    vector<int> ans(m + 1, 1);
    auto C = [&](int n, int m) {
        if (n < m)
            return 0ll;
        return (ll)fac[n] * facinv[n - m] % mod * facinv[m] % mod;
    };
    for (int i = 1; i <= m; ++i) {
        for (auto &u : a) {
            ans[i] = (ll)ans[i] * mypow(C(i, u), cnt[u]) % mod;
        }
    }
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << "\n";
    return 0;
}