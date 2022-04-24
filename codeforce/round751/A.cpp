#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string s2=s;
		sort(s2.begin(), s2.end());
		string x="";
		bool f=0;
		for(auto u:s){
			if(!f&&u==s2[0]){
				f=1;
				continue;
			}
			x+=u;
		}
		cout<<s2[0]<<" "<<x<<"\n";
	}
	return 0;
}