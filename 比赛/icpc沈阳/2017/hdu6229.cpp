
#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, a, b)    for (int i(a); i <= (b); ++i)
#define dec(i, a, b)    for (int i(a); i >= (b); --i)
#define MP      make_pair
#define fi      first
#define se      second
 
typedef long long LL;
typedef pair <int, int> PII;
 
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
 
int T;
int n, m;
 
map < pair <int, int>  , LL > mp;
int ca = 0;
 
 
inline LL judge(int x, int y){
    if ((x == 0 && y == 0) || (x == 0 && y == n - 1) || (x == n - 1 && y == 0) || (x == n - 1 && y == n - 1)) return 3;
    if (x == 0 || x == n - 1 || y == 0 || y == n - 1) return 4;
    return 5;
}
 
inline bool check(int x, int y){
    return (x + y) >= (n - 1);
}
 
inline bool ok(int x, int y){
    return x >= 0 && y >= 0 && x <= n - 1 && y <= n - 1;
}
 
LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}
 
int main(){
 
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        LL all = 4 * 3 + (n - 2) * 4 * 4 + 5 * (n - 2) * (n - 2);
        LL xx1 = 3, xx2 = 2 * (n - 2);
        LL xx3 = n * (n + 1) / 2 - xx1 - xx2;
        LL sum = xx1 * 3 + xx2 * 4 + xx3 * 5;
 
        mp.clear();
        while (m--){
            int x, y;
            scanf("%d%d", &x, &y);
            mp[MP(x, y)] = judge(x, y);
            rep(i, 0, 3){
                int nx = x + dx[i], ny = y + dy[i];
                if (ok(nx, ny)){
                    ++mp[MP(nx, ny)];
                    mp[MP(nx, ny)] = min(mp[MP(nx, ny)], judge(nx, ny));
                }
            }
             
        }
 
 
        for (auto cnt : mp){
            int x = cnt.fi.fi, y = cnt.fi.se;
            LL  z = cnt.se;
            if (check(x, y)) sum -= z;
            all -= z;
        }
 
        LL a1 = sum, a2 = all;
        LL g = gcd(a1, a2);
        a1 /= g, a2 /= g;
        printf("Case #%d: %lld/%lld\n", ++ca, a1, a2);
    }
 
    return 0;
}