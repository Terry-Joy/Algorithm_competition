#include<bits/stdc++.h> 
using namespace std;

const int N = 52;
int n, m;
int p[N][N], pref[N][N], dp[N][N][N][N];

int getSum(int x1, int y1, int x2, int y2) {
	return pref[x2][y2]-pref[x2][y1-1]-pref[x1-1][y2]+pref[x1-1][y1-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> p[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			pref[i][j] = p[i][j];
			if (i > 0) {
				pref[i][j] += pref[i - 1][j];
			}
			if (j > 0) {
				pref[i][j] += pref[i][j - 1];
				if (i > 0) {
					pref[i][j] -= pref[i - 1][j - 1];
				}
			}
		}
	}
	for (int sizeR = 1; sizeR <= n; ++sizeR) {
		for (int sizeC = 1; sizeC <= m; ++sizeC) {
			for (int x1 = 1; x1 + sizeR - 1 <= n; ++x1) {
				int x2 = x1 + sizeR - 1;
				for (int y1 = 1; y1 + sizeC - 1 <= m; ++y1) {
					int y2 = y1 + sizeC - 1;

					dp[x1][x2][y1][y2] = getSum(x1, y1, x2, y2);
					if (sizeR > 1) {
						dp[x1][x2][y1][y2] = max(dp[x1][x2][y1][y2], dp[x1 + 1][x2][y1][y2]);
						dp[x1][x2][y1][y2] = max(dp[x1][x2][y1][y2], dp[x1][x2 - 1][y1][y2]);
					}
					if (sizeC > 1) {
						dp[x1][x2][y1][y2] = max(dp[x1][x2][y1][y2], dp[x1][x2][y1 + 1][y2]);
						dp[x1][x2][y1][y2] = max(dp[x1][x2][y1][y2], dp[x1][x2][y1][y2 - 1]);
					}
				}
			}
		}
	}

	int ans =-1e9;
	for (int r1 = 1; r1 < n; ++r1) {
		for (int r2 = r1 + 1; r2 < n; ++r2) {
			ans = max(ans, dp[1][r1][1][m] + dp[r1 + 1][r2][1][m] + dp[r2 + 1][n][1][m]);
		}
	}
	for (int c1 = 1; c1 < m; ++c1) {
		for (int c2 = c1 + 1; c2 < m; ++c2) {
			ans = max(ans, dp[1][n][1][c1] + dp[1][n][c1 + 1][c2] + dp[1][n][c2 + 1][m]);
		}
	}
	for (int r = 1; r < n; ++r) {
		for (int c = 1; c < m; ++c) {
			ans = max(ans, dp[1][r][1][c] + dp[1][r][c + 1][m] + dp[r + 1][n][1][m]);//上二右一
			ans = max(ans, dp[1][r][1][m] + dp[r + 1][n][1][c] + dp[r + 1][n][c + 1][m]);//上一右二
			ans = max(ans, dp[1][r][1][c] + dp[r + 1][n][1][c] + dp[1][n][c + 1][m]);//左二右一
			ans = max(ans, dp[1][n][1][c] + dp[1][r][c + 1][m] + dp[r + 1][n][c + 1][m]);//左一右二
		}
	}
	cout << ans << endl;
	return 0;
}
