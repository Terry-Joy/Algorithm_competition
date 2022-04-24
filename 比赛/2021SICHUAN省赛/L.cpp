#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e5+5;
const int INF=2e9;
int d[105][maxn],n,m,q,w[maxn];
vector<int>G[maxn];
queue<int>qu;
void bfs(int val){
	for(int i=1;i<=n;++i){
		if(w[i]==val){
			d[val][i]=0;
			qu.push(i);
		}
	}
	while(!qu.empty()){
		int x=qu.front();qu.pop();
		for(auto&v:G[x]){
			if(d[val][v]!=INF)continue;
			d[val][v]=d[val][x]+1;
			qu.push(v);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)cin>>w[i];
	int a,b;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		G[a].pb(b);G[b].pb(a);
	}
	for(int i=1;i<=100;++i)
		for(int j=1;j<=n;++j)
			d[i][j]=INF;
	for(int i=1;i<=100;++i)bfs(i);
	for(int i=1;i<=n;++i){
		for(int j=2;j<=100;++j)
			d[j][i]=min(d[j-1][i],d[j][i]);
	}
	int pi,ai;
	for(int i=1;i<=q;++i){
		cin>>pi>>ai;
		if(d[ai][pi]==INF)cout<<"-1\n";
		else cout<<d[ai][pi]<<"\n";
	}
	return 0;
}