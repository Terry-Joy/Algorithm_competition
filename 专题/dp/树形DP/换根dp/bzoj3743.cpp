#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+10;
ll f[maxn],d[maxn][2],g[maxn],up[maxn],n,k;//最长次长不是同一子树下
vector<pair<int,int>>G[maxn];
int sz[maxn];
void dfs1(int x,int fa){
	for(auto&[v,w]:G[x]){
		if(v==fa)continue;
		dfs1(v,x);
		sz[x]+=sz[v];
		if(sz[v]){
			f[x]+=f[v]+2ll*w;
			if(d[v][0]+w>d[x][0]){
				d[x][1]=d[x][0];
				d[x][0]=d[v][0]+w;
			}else if(d[v][0]+w>d[x][1])
				d[x][1]=d[v][0]+w;
		}
	}
}
void dfs2(int x,int fa){
	for(auto&[v,w]:G[x]){
		if(v==fa)continue;
		if(k-sz[v]){
			g[v]=g[x]+f[x]-f[v];
			if(!sz[v])g[v]+=2ll*w;
			if(d[v][0]+w==d[x][0]){
				up[v]=max(up[x],d[x][1])+w;
			}else
				up[v]=max(up[x],d[x][0])+w;
		}
		dfs2(v,x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	int u,v,w;
	for(int i=1;i<n;++i){
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;++i){
		int x;
		cin>>x;sz[x]++;
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)
		cout<<f[i]+g[i]-max(d[i][0],up[i])<<"\n";	
	return 0;
}