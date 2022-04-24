#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<vector<int>>b(n+1,vector<int>(n+1,0));
		for(int i=1;i<=n;++i)cin>>b[0][i];
		for(int i=1;i<=n;++i){
			vector<int>cnt(n+1,0);
			for(int j=1;j<=n;++j){
				++cnt[b[i-1][j]];
			}
			for(int j=1;j<=n;++j)b[i][j]=cnt[b[i-1][j]];
		}
		int q;
		cin>>q;
		for(int i=1;i<=q;++i){
			int x,k;
			cin>>x>>k;
			cout<<b[min(k,n)][x]<<"\n";
		}
	}
	return 0;
}