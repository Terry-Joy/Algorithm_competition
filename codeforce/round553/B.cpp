#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int k = 0; k < 10; ++k) {
		int sum1 = 0, sum2 = 0;
    	vector<vector<int>> pos(n + 1), pos2(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if ((1 << k) & a[i][j]) {
                    pos[i].eb(j);
                } else {
                    pos2[i].eb(j);
                }
            }
        }
		for (int i = 1; i <= n; ++i) {
			if (pos2[i].empty()) {
				sum1 ^= 1;
			} else if (!pos[i].empty()) {
				sum2 = 1;
			}
		}
		if (sum1 & 1) {
			cout << "TAK\n";
			for (int i = 1; i <= n; ++i) {
				if (pos2[i].empty()) {
					cout << pos[i][0] << " ";
				} else {
					cout << pos2[i][0] << " ";
				}
			}
			return 0;
		} else if (sum2){
			cout << "TAK\n";
			bool flag = false;
			for (int i = 1; i <= n; ++i) {
				if (pos2[i].empty()) {
					cout << pos[i][0] << " ";
				} else if (!pos[i].empty() && !flag) {
					cout << pos[i][0] << " ";
					flag = true;
				} else {
					cout << pos2[i][0] << " ";
				}
			}
			return 0;
		}
    }
    cout << "NIE";
    return 0;
}