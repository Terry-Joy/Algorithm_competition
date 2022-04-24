#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn=3e5+10;
vector<int>G[maxn];
vector<int>mp[maxn];
vector<int>res,ans;
bool vis[maxn];
void dfs(int x){
	vis[x]=1;
	for(auto&v:G[x]){
		if(vis[v])continue;
		dfs(v);
		mp[x].eb(v);
		mp[v].eb(x);	
	}
}
void dfs2(int u,int end,int fa){
	res.eb(u);
	if(u==end){
		ans=res;
		return;
	}
	for(auto&v:mp[u]){
		if(v==fa)continue;
		dfs2(v,end,u);
	}	
	res.pop_back();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		G[a].eb(b);
		G[b].eb(a);
	}
	int q;
	cin>>q;
	vector<bool>f(n+1,0);
	vector<int>u(q+1,0);
	vector<int>v(q+1,0);
	for(int i=1;i<=q;++i){
		cin>>u[i]>>v[i];
		f[u[i]]=f[u[i]]^1,f[v[i]]=f[v[i]]^1;
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		cnt+=f[i];
	}
	if(!cnt){
		cout<<"YES\n";
		dfs(1);
		for(int i=1;i<=q;++i){
			res.clear();
			dfs2(u[i],v[i],0);
			cout<<ans.size()<<" ";
			for(auto&v:ans){
				cout<<v<<" ";
			}
			cout<<"\n";
		}
	}else{
		cout<<"NO"<<"\n"<<cnt/2;
	}
	return 0;
}