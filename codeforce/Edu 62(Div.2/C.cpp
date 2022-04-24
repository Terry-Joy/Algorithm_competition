#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 6;
int n, k;
pair<int, int> a[N];
priority_queue<int> q;
ll ans, now;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &a[i].second, &a[i].first);
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        now += a[i].second;
        q.push(-a[i].second);
        if ((int)q.size() > k) {
            now += q.top();
            q.pop();
        }
        ans = max(ans, now * a[i].first);
    }
    cout << ans << endl;
    return 0;
}