#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>a(10,1);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<(n-1)/2<<" "<<n-1<<"\n";
	}
	return 0;
}