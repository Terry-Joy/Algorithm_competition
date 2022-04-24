#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
unordered_map<int,int>mp,mp2;
int a[maxn],n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int l=1,r=n;
	while(l<=n){
		if(!mp.count(a[l])){
			mp[a[l]]++;
		}else
			break;
		l++;
	}
	l--;
	int ans=r-l;
	while(r>l){
		if(!mp2.count(a[r])){
			mp2[a[r]]++;
		}else
			break;
		while(mp.count(a[r])&&mp[a[r]]&&l>=1){
			mp[a[l]]--;
			l--;
		}
		ans=min(ans,r-l-1);
		r--;
	}
	cout<<ans<<"\n";
	return 0;
}