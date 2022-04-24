#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int>a(n);
		for(int i=0;i<n;++i)cin>>a[i];
		sort(a.begin(),a.end());
		for(int i=n;i>(n+1)/2;--i){
			cout<<a[i-1]<<" "<<a[0]<<"\n";
		}
	}
	return 0;
}