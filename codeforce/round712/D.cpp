#include<bits/stdc++.h>
#define eb emplace_back
#define fi first  
#define se second
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> odd, even;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((i + j) & 1) {
				even.eb(i, j);
			} else {
				odd.eb(i, j);
			}
		}
	}
	auto Print = [&](int col, int x, int y) {
		cout << col << " " << x << " " << y << endl;
	};
	for (int i = 1; i <= n * n; ++i) {
		int col;
		cin >> col;
		if (col == 1) { 
			if (even.size()) {
				auto it = even.back();
				even.pop_back();
				Print(2, it.fi, it.se);
			} else {
				auto it = odd.back();
				odd.pop_back();
				Print(3, it.fi, it.se);
			}
		} else if (col == 2) {
			if (odd.size()) {
				auto it = odd.back();
				odd.pop_back();
				Print(1, it.fi, it.se); 
			} else {
				auto it = even.back();
				even.pop_back();
				Print(3, it.fi, it.se);
			}
		} else {
			if (even.size()) {
				auto it = even.back();
				even.pop_back();
				Print(2, it.fi, it.se);
			} else {
				auto it = odd.back();
				odd.pop_back();
				Print(1, it.fi, it.se);
			}
		}
	}
	return 0;
}