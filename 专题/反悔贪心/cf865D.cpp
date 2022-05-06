#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	ll ans = 0;
	priority_queue<int, vector<int>,greater<int> >q;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (!q.empty() && q.top() < a) {
			ans += (a - q.top()); //对于当前的卖出，找最小的
			q.pop();
			q.push(a);//反悔物品
		}
		q.push(a); //可选物品
	}
	cout << ans;
	return 0;
}