#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using db=double;
const int maxn=3e5+5;
vector<int>G[maxn];
priority_queue<pair<db,int>>q;
bool vis[maxn];
int deg[maxn],cnt[maxn],n,m;
db dp[maxn],sum[maxn];
void dij(){
	q.push(make_pair(0,n));
	while(!q.empty()) {
		auto [w,v]=q.top();q.pop();
		if(vis[v])continue;
		vis[v]=1;
		for(auto&nxt:G[v]){
			if(vis[nxt])continue;
			cnt[nxt]++;
			sum[nxt]+=dp[v];
			dp[nxt]=(deg[nxt]+sum[nxt])/cnt[nxt];
			q.push(make_pair(-dp[nxt],nxt));
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].eb(v);G[v].eb(u);
		deg[u]++;deg[v]++;
	}
	dij();
//	for(int i=1;i<=n;++i)cout<<deg[i]<<"\n";
//	printf("%.07f\n",dp[1]);
	// for(int i=1;i<=n;++i)
	// 		cout<<fixed<<setprecision(10)<<dp[i]<<" ";	
	cout<<fixed<<setprecision(10)<<dp[1];
	return 0;
}