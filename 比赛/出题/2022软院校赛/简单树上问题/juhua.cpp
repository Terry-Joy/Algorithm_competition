#include<bits/stdc++.h>

using namespace std;

int main() {
	int n = 200000;
	srand(time(NULL));
	cout << n << "\n";
	int root = 1;
	for (int i = 2; i <= n; ++i) {
		cout << root << " " << i << " " << rand() % 200 + 1;
		if (i!= n) {
			cout << "\n";
		}
	}
	return 0;
}