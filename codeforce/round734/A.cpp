#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n % 3 == 0) {
			cout << n / 3 << " " << n / 3 << "\n";
		} else {
			if ((n + 1) % 3 == 0) {
				int y = (n + 1) / 3, x = y - 1;
				if (x >= 0 && y >= 0) {
					cout << x << " " << y << "\n";
				}
			} else if ((n - 1) % 3 == 0){
				int y = (n - 1) / 3, x = y + 1;
				if (x >= 0 && y >= 0) {
					cout << x << " " << y << "\n";
				}
			}
		}
	}
	return 0;
}