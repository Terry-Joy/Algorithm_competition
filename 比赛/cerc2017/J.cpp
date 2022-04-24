#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn=1e6+5;
vector<int>G[maxn];
int sz[maxn],cnt[maxn];
void dfs(int x,int fa){
	sz[x]=1;
	for(auto v:G[x]){
		if(v==fa)continue;
		dfs(v,x);
		sz[x]+=sz[v];
	}
	cnt[sz[x]]++;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].eb(v);
		G[v].eb(u);
	}
	dfs(1,0);
	vector<int>ans;
	for(int i=1;i<n;++i){
		int fac=i+1;
		if(n%fac)continue;
		int sum=0,num=n/fac;
		for(int j=num;j<=n;j+=num)
			sum+=cnt[j];
		if(sum>=fac)ans.push_back(i);
	}
	for(auto&v:ans)
		cout<<v<<" ";
	return 0;
}