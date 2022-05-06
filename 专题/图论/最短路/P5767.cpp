#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn = 505;
int g[maxn][maxn], d[maxn],stop[maxn];
int m, n;
void bfs(int s) {
	fill(d + 1, d + 1 + n, 0x3f3f3f3f);
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= n; ++i) {
			if (g[x][i] && d[i] > d[x] + 1) {
				d[i] = d[x] + 1;
				q.push(i);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	string line;
    getline(cin, line);  // 读完前面的回车
    while (m--) {
        getline(cin, line);
        stringstream ssin(line);
        int cnt = 0, p;
        while (ssin >> p) stop[cnt++] = p;
        for (int i = 0; i < cnt; i++)
            for (int j = i + 1; j < cnt; j++)
                g[stop[i]][stop[j]] = 1;
    }
	bfs(1);
	if (d[n] == 0x3f3f3f3f) {
		cout << "NO";
	} else {
		cout << max(d[n] - 1, 0);
	}
	return 0;
}