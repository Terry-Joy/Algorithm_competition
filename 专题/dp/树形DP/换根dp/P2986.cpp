#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using ll=long long;
using P=pair<int,int>;
const int maxn=1e5+10;
vector<P>G[maxn];
int sz[maxn],d[maxn],n,num[maxn];
ll f[maxn];
void dfs1(int x,int fa){
	for(auto &[v,w]:G[x]){
		if(v==fa)continue;
		d[v]=d[x]+w;
		dfs1(v,x);
		sz[x]+=sz[v];
	}
}
void dfs2(int x,int fa){
	for(auto&[v,w]:G[x]){
		if(v==fa)continue;
		f[v]=f[x]+(ll)w*(sz[1]-2*sz[v]);
		dfs2(v,x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>sz[i],num[i]=sz[i];
	for(int i=1;i<n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].eb(v,w);
		G[v].eb(u,w);
	}
	dfs1(1,0);
	for(int i=2;i<=n;++i)f[1]+=(ll)d[i]*num[i];
	dfs2(1,0);
	ll ans=9e18;
	for(int i=1;i<=n;++i)ans=min(ans,f[i]);
	cout<<ans;
	return 0;
}