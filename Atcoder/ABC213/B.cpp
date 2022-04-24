#include<bits/stdc++.h>
#define fi first 
#define se second 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<int,int>>a(n);
	for(int i=0;i<n;++i)cin>>a[i].fi,a[i].se=i+1;
	sort(a.begin(),a.end());
	cout<<a[n-2].se;
	return 0;
}