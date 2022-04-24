#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	ll ans=0;
	int len=s.length();
	for(int i=0;i<(1<<(len-1));++i){
		int now=0;
		for(int j=0;j<len-1;++j){
			if((1<<j)&i){
				string str=s.substr(now,j-now+1);
				ll x=stoll(str);
				ans+=x;
				now=j+1;
			}
		}
		if(now!=len){
			string str=s.substr(now,len-now);
			ll x=stoll(str);
			ans+=x;
		}
	}
	cout<<ans;
	return 0;
}