#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
using P=tuple<int,int,int>;
const int maxn=1e5+10;
int n,dfn[maxn],d[maxn],st[maxn<<1][21],lg[maxn<<1],ti,S,rt,fa[maxn],sz[maxn],mxson[maxn];
vector<tuple<int,int>>G[maxn];
vector<P>que[maxn];
bool vis[maxn];
void dfs(int x,int f,int c){
	dfn[x]=++ti;d[x]=d[f]+c;st[ti][0]=x;
	for(auto [v,w]:G[x]){
		if(v==f)continue;
		dfs(v,x,w);
		st[++ti][0]=x;	
	}
}
void RMQ(){
	for(int i=2;i<=ti;++i)lg[i]=lg[i>>1]+1;
	for(int j=1;j<=lg[ti];++j)
		for(int i=1;(i+(1<<j)-1)<=ti;++i){
			int r=i+(1<<(j-1));
			st[i][j]=d[st[i][j-1]]<d[st[r][j-1]]?st[i][j-1]:st[r][j-1];
		}
}
int query(int l,int r){
	if(l>r)swap(l,r);
	int k=lg[r-l+1];
	return d[st[l][k]]<d[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}
int LCA(int x,int y){
	return query(dfn[x],dfn[y]);
}
int dis(int x,int y){
	return d[x]+d[y]-2*d[LCA(x,y)];
}
void getRoot(int x,int f){
	sz[x]=1;mxson[x]=0;
	for(auto [v,w]:G[x]){
		if(v==f||vis[v])continue;
		getRoot(v,x);
		sz[x]+=sz[v];
		mxson[x]=max(mxson[x],sz[v]);
	}
	mxson[x]=max(mxson[x],S-sz[x]);
	if(mxson[x]<mxson[rt])rt=x;
}
void init(int x){
	mxson[rt=0]=maxn;
	S=sz[x];
	getRoot(x,0);
}
void dfz(int x){
	vis[x]=1;
	for(auto [v,w]:G[x]){
		if(vis[v])continue;
		init(v);
		fa[rt]=x;
		dfz(rt);
	}
}
void update(int time,int u,int d,int c){
	for(int i=u;i;i=fa[i]){
		int dd=dis(u,i);
		if(dd>d)continue;
		while(!que[i].empty()&&(get<1>(que[i].back()))<=d-dd)
			que[i].pop_back();
		que[i].eb(time,d-dd,c);
	}
}
int Query(int x){
	P ans(0,0,0);
	for(int i=x;i;i=fa[i]){
		int dd=dis(x,i);
		if(que[i].empty()||(!que[i].empty()&&(get<1>(que[i][0]))<dd))continue;
		int l=0,r=que[i].size()-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(get<1>(que[i][mid])>=dd)l=mid;
			else r=mid-1;
		}
		ans=max(ans,que[i][l]);
	}
	return get<2>(ans);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int u,v,w;
	for(int i=1;i<=n-1;++i){
		cin>>u>>v>>w;
		G[u].eb(v,w);
		G[v].eb(u,w);
	}
	dfs(1,0,0);
	RMQ();
	mxson[rt=0]=maxn;
	S=n;
	getRoot(1,0);
	fa[rt]=0;
	dfz(rt);
	int q;
	cin>>q;
	int op,d,c;
	for(int i=1;i<=q;++i){
		cin>>op>>v;
		if(op==1){
			cin>>d>>c;
			update(i,v,d,c);
		}else{
			cout<<Query(v)<<"\n";
		}
	}
	return 0;
}