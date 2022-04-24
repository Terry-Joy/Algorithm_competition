#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using P = pair<int, int>;
deque<P> q;
const int maxn = 505;
const int INF = 0x3f3f3f3f;
int dx[] = {1, 0, 0, -1, -2, -2, -2, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 2, 2, 2};
int dy[] = {0, 1, -1, 0, -1, 0, 1, -2, -1, 1, 2, -2, 2, -2, -1, 1, 2, -1, 0, 1};
int dis[maxn][maxn];
char mp[maxn][maxn];
int h, w;

void bfs(int x, int y) {
    q.push_back({x, y});
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j)
            dis[i][j] = INF;
    }
    dis[x][y] = 0;
    auto check = [&](int x, int y) {
        return x <= h && x >= 1 && y <= w && y >= 1;
    };
    while (!q.empty()) {
        P u = q.front();
        q.pop_front();
        for (int i = 0; i < 4; ++i) {
            int xx = u.fi + dx[i], yy = u.se + dy[i];
            if (!check(xx, yy) || mp[xx][yy] == '#')
                continue;
            if (dis[xx][yy] > dis[u.fi][u.se]) {
                dis[xx][yy] = dis[u.fi][u.se];
                q.push_front({xx, yy});
            }
        }
        for (int i = 0; i < 20; ++i) {
            int xx = u.fi + dx[i], yy = u.se + dy[i];
            if (!check(xx, yy))
                continue;
            if (dis[xx][yy] > dis[u.fi][u.se] + 1) {
                dis[xx][yy] = dis[u.fi][u.se] + 1;
                q.push_back({xx, yy});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
        cin >> (mp[i] + 1);
    }
    bfs(1, 1);
    cout << dis[h][w];
    return 0;
}