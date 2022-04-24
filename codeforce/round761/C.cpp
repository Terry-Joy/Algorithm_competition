#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int>a(n+1,0),vis(n+1,0),c,d;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			if(a[i]<=n&&!vis[a[i]]){
				vis[a[i]]=1;
			}else
				c.push_back(a[i]);
		}
		for(int i=1;i<=n;++i){
			if(!vis[i])
				d.push_back(i);
		}
		sort(c.begin(),c.end());
		bool is=1;
		for(int i=0;i<d.size();++i){
			if(d[i]*2>=c[i]){
				is=0;break;
			}
		}
		if(!is)cout<<-1<<'\n';
		else cout<<c.size()<<"\n";
	}
	return 0; 
}