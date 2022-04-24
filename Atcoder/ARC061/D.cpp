#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<pair<int,int>,ll>mp;
int cnt[12];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int H,W,n;
	cin>>H>>W>>n;
	for(int i=1;i<=n;++i){
		int x,y;
		cin>>x>>y;
		for(int j=-1;j<=1;++j){
			for(int k=-1;k<=1;++k){
				if(y+j+1<=W&&y+j-1>=1&&x+k+1<=H&&x+k-1>=1){
					mp[{x+k,y+j}]++;
				}
			}
		}
	}
	for(auto &[u,v]:mp){
		cnt[v]++;
	}
	ll ans=(ll)(H-2)*(W-2);
	for(int i=1;i<=9;++i)ans-=cnt[i];
	cout<<ans<<"\n";
	for(int i=1;i<=9;++i)cout<<cnt[i]<<"\n";
	return 0;
}