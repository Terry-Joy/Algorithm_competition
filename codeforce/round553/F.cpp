#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

struct Matrix {
	vector<vector<int>> mat;
	void init(int n) { 
		mat.resize(n + 1); 
		for (int i = 0; i <= n; ++i)
			mat[i].resize(n + 1, 0); 
	}
	Matrix operator*(Matrix const &b) const { 
		Matrix res;
		int n = this->mat.size() - 1;
		res.init(n);
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k <= n; ++k) {
					res.mat[i][j] = (res.mat[i][j] + (ll)this->mat[i][k] * b.mat[k][j]) % mod;
				}
			}
		}
		return res;
	}
};

Matrix mypow(Matrix a, int b) {
	Matrix res;
	int n = a.mat.size() - 1;
	res.init(n);
	for (int i = 0; i <= n; ++i) {
		res.mat[i][i] = 1;
	}
	while (b) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int pow(int a, int b) {
	int ans = 1;
	while(b) {
		if (b & 1)
			ans = (ll) ans * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1, 0);
	int m = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!a[i]) 
			m++;
	}
	vector<int> A(m + 1, 0), B(m + 1, 0), C(m + 1, 0);
	for (int i = 0; i <= m; ++i) {
		A[i] = max((m - i) * (m - i), 0);	//1
		B[i] = max(i * (n - 2 * m + i), 0); //-1
		C[i] = max(n * (n - 1) / 2 - B[i] - A[i], 0); //0
	}

	int x = 0;
	for (int i = 1; i <= m; ++i) {
		if (!a[i]) {
			x++;
		}
	}
	
	Matrix base, fi;
	base.init(m);
	fi.init(m);
	fi.mat[x][0] = 1;
	int now = -1, pos = -1;
	auto check = [&](int now, int pos) {
		return now <= m && now >= 0 && pos >= 0  && pos <= m;
	};
	for (int i = 0; i <= m; ++i) {
		if (check(now, pos))
			base.mat[i][pos] = A[now];
		if (check(now + 1, pos + 1))
			base.mat[i][pos + 1] = C[now + 1];
		if (check(now + 2, pos + 2))
			base.mat[i][pos + 2] = B[now + 2];
		now++;
		pos++;
	}
	base = mypow(base, k);
	int sum = 0;
	for (int i = 0; i <= m; ++i) {
		sum = (sum + base.mat[i][x]) % mod;
	}
	cout << (ll)base.mat[m][x] * pow(sum, mod - 2) % mod;
	return 0;
}