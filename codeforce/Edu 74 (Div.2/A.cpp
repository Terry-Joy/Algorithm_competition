#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 300005;
char s[maxn];
int main()
{
    ll n, i;
    scanf("%lld", &n);
    scanf("%s", s);
    ll ans = n * (n - 1) / 2; //假设字符串中只有一种字母，所有情况都满足
    ll cnt = 1;
    for (i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
        {
            ans -= cnt;
            cnt = 1;
        }
    }
    cnt = 1;
    for (i = n - 2; i >= 0; i--)
    {
        if (s[i] == s[i + 1])
            cnt++;
        else
        {
            ans -= cnt;
            cnt = 1;
        }
    }
    for (i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
            ans++;
    }
    printf("%lld\n", ans);
}

