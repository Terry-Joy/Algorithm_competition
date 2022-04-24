#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		int val[3]={a,b,a^b};
		cout<<val[n%3]<<"\n";
	}
	return 0;
}