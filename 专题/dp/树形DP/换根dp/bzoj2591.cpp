#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn=1e5+10;
int f[maxn][22],u,v,c[maxn],k,n;
vector<int>G[maxn];
void dfs1(int x,int fa){
	f[x][0]=c[x];
	for(auto&v:G[x]){
		if(v==fa)continue;
		dfs1(v,x);
		for(int j=1;j<=k;++j)
			f[x][j]+=f[v][j-1];
	}
}
void dfs2(int x,int fa){
	for(auto&v:G[x]){
		if(v==fa)continue;
		for(int j=k;j>=1;--j){//倒序
			f[v][j]=f[v][j]+f[x][j-1]-(j>=2?f[v][j-2]:0);
		}
		dfs2(v,x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		G[u].eb(v);
		G[v].eb(u);
	}
	for(int i=1;i<=n;++i)cin>>c[i];
	dfs1(1,0);
	//cout<<f[1][k]<<">>";
	dfs2(1,0);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k;++j)
			f[i][j]+=f[i][j-1];
	for(int i=1;i<=n;++i)cout<<f[i][k]<<"\n";
	return 0;
}