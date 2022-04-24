#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
vector<string>mp;
int sum[maxn*5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	mp.resize(n+1);
	for(int i=1;i<=n;++i){
		cin>>mp[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j){
			if(i+1<=n&&j+1<m)
				if(mp[i+1][j]=='X'&&mp[i][j+1]=='X')
					sum[j+2]++;
		}
	}
	for(int i=2;i<=m;++i)sum[i]+=sum[i-1];
	int q,l,r;
	cin>>q;
	for(int i=1;i<=q;++i){
		cin>>l>>r;
		cout<<((sum[r]-sum[l])?"NO":"YES")<<"\n";
	}
	return 0;
}