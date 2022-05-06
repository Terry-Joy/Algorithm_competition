#include<bits/stdc++.h>

using namespace std;

int main() {
	int n = 200000, cnt = 0;
	cout << n << "\n";
	int edge = 1;
	bool flag = true;
	for (int i = 1; i + 2 <= n; i += 2) {
		cout << i << " " << i + 2 << " " << edge << "\n";
		edge += 2;
		cnt++;
	}
	edge = 2e5;
	for (int i = n; i - 2 >= 1; i -= 2) {
		cnt++;
		cout << i << " " << i - 2 << " " << edge << "\n";
		edge -= 2;
	}
	cout << n << " " << 1 << " " << n;
	//cout << cnt + 1 <<endl;
	return 0;
}