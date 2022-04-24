#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int>a(n+1, 0);
	vector<bool>vis(100005, 0);
	vector<bool>v(100005, 0);
	for(int i = 1; i <= n; ++i) 
		cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		for(int j = 2; j*j <= a[i]; ++j) {
			if(a[i] % j == 0) {
				vis[j] = 1;
				vis[a[i]/j] = 1;
				while(a[i] % j == 0) 
					a[i] /= j;
			}
		}
		if(a[i] > 1) {
			vis[a[i]] = 1;
		}
	}
	for(int i = 2; i <= m; ++i) {
		if(vis[i])
			for(int j = i; j <= m; j += i) {
				v[j] = 1;
			}
	}
	vector<int> ans;
	for(int i = 1; i <= m; ++i) {
		if(!v[i])
			ans.emplace_back(i);
	}
	cout << ans.size() <<'\n';
	for(auto u: ans) {
		cout << u << "\n";
	}
	return 0;
}