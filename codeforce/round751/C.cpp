#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int>a(n+1,0);
		vector<int>sum(40,0);
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int j=0;j<=29;++j){
			for(int i=1;i<=n;++i){
				if((1<<j)&a[i]){
					sum[j]++;
				}
			}
		}
		cout<<1<<" ";
		for(int i=2;i<=n;++i){
			bool f=1;
			for(int j=0;j<=29;++j){
				if(sum[j]%i==0)continue;
				f=0;
			}
			if(f)cout<<i<<" ";
		}
		cout<<"\n";
	}
	return 0;
}