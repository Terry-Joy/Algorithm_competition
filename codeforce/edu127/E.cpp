#include<bits/stdc++.h>
#define ls x << 1
#define rs x << 1 | 1
using namespace std;
using ll = long long;
const int maxn = 1e6;
string s[maxn], str;
int dp[maxn], m, a[maxn];
const int mod = 998244353;

void dfs(int x) {
	if (ls > m) {
		if (str[x] == 'A') {	
			s[x] = "0";
		} else {
			s[x] = "1";
		}
		dp[x] = 1;
		return;
	}
	dfs(ls);
	dfs(rs);
	if (s[ls] > s[rs]) 
		swap(s[ls], s[rs]);
	if (str[x] == 'A')
		s[x] = "0";
	else
		s[x] = "1";
	s[x] += s[ls] + s[rs];
	if (s[ls] == s[rs]) 
		dp[x] = (ll)dp[ls] * dp[rs] % mod;
	else
		dp[x] = (ll)dp[ls] * dp[rs] % mod * 2 % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	m = (1 << n) - 1;
	cin >> str;
	str = " " + str;
 	dfs(1);
	cout << dp[1];
	return 0;
}