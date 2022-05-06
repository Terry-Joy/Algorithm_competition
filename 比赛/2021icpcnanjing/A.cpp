#include<bits/stdc++.h>

using namespace std;
int n, a, b;
int main() {
	cin >> n >> a >> b;
	int val = (n + 1) / 2;
	if (b <= val) {
		for (int i = 1; i <= n - 1; ++i) {
			cout << "L";
		}
		if (a <= val) {
			for (int i = 1; i <= n - 1; ++i) {
				cout << "U";
			}
			a--;
			b--;
			for (int i = 1; i <= a; ++i) {
				cout << "D";
			}
			for (int i = 1; i <= b; ++i) {
				cout << "R";
			}
		} else {
			for (int i = 1; i <= n - 1; ++i) {
				cout << "D";
			}
			b--;
			for (int i = 1; i <= n - a; ++i) {
				cout << "U";
			}
			for (int i = 1; i <= b; ++i) {
				cout << "R";
			}
		}
	} else {
		for (int i = 1; i <= n - 1; ++i) {
			cout << "R";
		}
		if (a <= val) {
			for (int i = 1; i <= n - 1; ++i) {
				cout << "U";
			}
			a--;
			for (int i = 1; i <= a; ++i) {
				cout << "D";
			}
			for (int i = 1; i <= n - b; ++i) {
				cout << "L";
			}
		} else {
			for (int i = 1; i <= n - 1; ++i) {
				cout << "D";
			}
			for (int i = 1; i <= n - a; ++i) {
				cout << "U";
			}
			for (int i = 1; i <= n - b; ++i) {
				cout << "L";
			}
		}
	}
	return 0;
}