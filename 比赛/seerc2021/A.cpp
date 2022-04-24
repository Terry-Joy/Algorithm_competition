#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1, s2;
	int n;
	cin >> n;
	cin >> s1 >> s2;
	vector<int> dp(n, 0);
	dp[0] = (s1[0] == s2[0]);
	for(int i = 1; i < n; i++) {
		if(s1[i] == s2[i]) {
			dp[i] = dp[i-1] + 1;
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(s1[i] < s2[i]) {
			if(!i || !dp[i-1]) {
				ans += n - i;
			}else
				ans += (ll)(dp[i-1] + 1) * (n - i);
		}
	}
	cout << ans;
	return 0;
}