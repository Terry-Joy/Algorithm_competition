#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> s >> n;
	sort(s.begin(), s.end());
	vector<string> ans;
	do{
		ans.emplace_back(s);
	}while(next_permutation(s.begin(), s.end()));
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()),ans.end());
	cout << ans[n-1] << endl;
}