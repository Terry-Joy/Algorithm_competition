#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int>sumW(n+1,0),sumE(n+1,0);
	for(int i=1;i<=n;++i){
		sumW[i]=sumW[i-1]+(s[i-1]=='W');
		sumE[i]=sumE[i-1]+(s[i-1]=='E');
	}
	int ans=1e9;
	for(int i=1;i<=n;++i){
		if(s[i-1]=='E'){
			ans=min(ans,sumW[i-1]+sumE[n]-sumE[i]);
		}else
			ans=min(ans,sumW[i-1]+sumE[n]-sumE[i]);
	}
	cout<<ans;
	return 0;
}