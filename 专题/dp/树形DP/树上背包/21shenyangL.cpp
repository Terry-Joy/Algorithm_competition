#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using ll=long long;
const int maxn=2e3+5;
const int mod=998244353;
int n,sz[maxn<<1],dp[maxn<<1][maxn][2],g[maxn];
vector<int>G[maxn<<1];
void dfs(int x,int fa){
	sz[x]=1;
	dp[x][0][0]=1;
	for(auto&v:G[x]){
		if(v==fa)continue;
		dfs(v,x);
		for(int j=sz[x]/2;j>=0;--j)
			for(int k=sz[v]/2;k>=0;--k){
				if(k){
					dp[x][j+k][0]=(dp[x][j+k][0]+(ll)dp[x][j][0]*(dp[v][k][0]+dp[v][k][1]))%mod;
					dp[x][j+k][1]=(dp[x][j+k][1]+(ll)dp[x][j][1]*(dp[v][k][0]+dp[v][k][1]))%mod;
				}
				if(j+k+1<=(sz[x]+sz[v])/2)
					dp[x][j+k+1][1]=(dp[x][j+k+1][1]+(ll)dp[x][j][0]*dp[v][k][0])%mod;
			}
		sz[x]+=sz[v];
	}
}
int sub(int x,int y){
	x-=y;
	if(x<0)x+=mod;
	return x;
}
int mul(int x,int y){
	return (ll)x*y%mod;
}
int add(int x,int y){
	x+=y;
	if(x>=mod)x-=mod;
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int u,v;
	for(int i=1;i<2*n;++i){
		cin>>u>>v;
		G[u].eb(v);
		G[v].eb(u);
	}
	dfs(1,0);
	g[0]=g[1]=1;
	for(int i=2;i<=n;++i)g[i]=(ll)(2*i-1)*g[i-1]%mod;
	int ans=g[n];
	// for(int i=1;i<=2*n;++i) 
	// 	cout<<g[i]<<" ";
	for(int i=1;i<=n;++i){
		if(i&1)
			ans=sub(ans,mul(g[n-i],add(dp[1][i][0],dp[1][i][1])));
		else
			ans=add(ans,mul(g[n-i],add(dp[1][i][0],dp[1][i][1])));
	}
	cout<<ans;
	return 0;
}