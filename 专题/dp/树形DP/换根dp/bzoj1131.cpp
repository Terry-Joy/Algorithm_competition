#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using ll=long long;
const int maxn=1e6+5;
int n,u,v,d[maxn],sz[maxn];
ll f[maxn];
vector<int>G[maxn];
void dfs1(int x,int fa){
	sz[x]=1;
	for(auto &v:G[x]){
		if(v==fa)continue;
		d[v]=d[x]+1;
		dfs1(v,x);
		sz[x]+=sz[v];
	}
}
void dfs2(int x,int fa){
	for(auto&v:G[x]){
		if(v==fa)continue;
		f[v]=f[x]-sz[v]+n-sz[v];
		dfs2(v,x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		G[u].eb(v);
		G[v].eb(u);
	}
	dfs1(1,0);
	for(int i=1;i<=n;++i)f[1]+=d[i];
	dfs2(1,0);
	ll ans=1,mx=f[1];
	for(int i=2;i<=n;++i){
		if(f[i]>mx){
			mx=f[i];ans=i;
		}
	}
	cout<<ans;
	return 0;                                                                    
}