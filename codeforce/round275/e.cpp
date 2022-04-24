#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int maxn=1e5+10;
vector<int>G[maxn];
int deg[maxn];
vector<int>ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,m,n;
	cin>>t;
	while(t--){
		
		cin>>n>>m;
		for(int i=1;i<=m;++i){
			int x,y,z;
			cin>>x>>y>>z;
			G[x].push_back(y);
			G[z].push_back(y);
			deg[y]+=2;
		}
		queue<int>q;
		for(int i=1;i<=n;++i)
			if(!deg[i])q.push(i);
		
		while(!q.empty()){
			int x=q.front();ans.push_back(x);q.pop();
			for(auto&v:G[x]){
				deg[v]--;
				if(!deg[v])q.push(v);
			}
		}
		for(int i=0;i<ans.size()-1;++i){
			cout<<ans[i]<<" "<<ans[i+1]<<"\n";
		}
	}
	return 0;
}