#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; string t; cin >> n >> t;
    string s;
    while (s.size() < n + 3) s += "110";
    cout<<s<<endl;
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        if (t != s.substr(i, n)) continue;
        ans += (ll) 1e10 - (n + i - 1) / 3;
    }
    cout << ans << endl;
}
