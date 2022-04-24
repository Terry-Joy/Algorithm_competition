#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
int solve(int x){
	if(mp[x])return mp[x];
	int ans=1;
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			ans+=solve(i);
			if(x/i!=i)
				ans+=solve(x/i);
		}
	}
	mp[x]=ans;
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<solve(n);
	return 0;
}