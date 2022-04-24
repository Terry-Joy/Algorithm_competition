#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		string s[2];
		vector<bool>vis[2];
		for(int i=0;i<2;++i)vis[i].resize(n);
		cin>>s[0]>>s[1];
		for(int i=0;i<n;++i){
			if(s[1][i]=='0')continue;
			bool f=0,f1=0;
			if(i>0){
				if(s[0][i-1]=='1'&&!vis[0][i-1]){
					vis[0][i-1]=1;ans++;
					f1=1;
				}
			}
			if(!f1)
				if(s[0][i]=='0'&&!vis[0][i]){
					ans++;
					vis[0][i]=1;
					f=1;
				}
			if(!f&&!f1)
				if(i+1<n&&s[1][i]=='1'&&s[0][i+1]=='1'){
					ans++;
					vis[0][i+1]=1;
				}		
		}
		cout<<ans<<"\n";
	}
	return 0;
}