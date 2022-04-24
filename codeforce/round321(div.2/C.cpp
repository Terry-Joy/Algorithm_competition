#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,a[maxn],ans;
vector<int>G[maxn];
bool vis[maxn];
void dfs(int x,int num){
	if(num>m)return;
	vis[x]=1;
	if(G[x].size()==1&&vis[G[x][0]]){
		ans++;
		return;
	}
	for(auto&v:G[x]){
		if(vis[v])continue;
		if(!a[v]){
			dfs(v,0);
		}else
			dfs(v,num+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	dfs(1,a[1]);
	cout<<ans;
	return 0;
}