#include<bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int maxn=2e5+10;
int n,q,e[maxn],fa[maxn<<1],cnt,val[maxn<<1],f[maxn<<1][23],dep[maxn<<1],lg[maxn<<1],mxdfn[maxn],midfn[maxn],mxval[maxn],ti,id[maxn<<1],dfn[maxn<<1];
vector<int>G[maxn<<1];
struct Edge{
	int u,v,c,t;
};
struct Qu{
	int v,x,id;
};
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void dfs(int x,int fa){
	dfn[x]=++ti;id[ti]=x;
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=lg[dep[x]];++i)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto&v:G[x]){
		if(v==fa)continue;
		dfs(v,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])
		x=f[x][lg[dep[x]-dep[y]]-1];
	if(x==y)return x;
	for(int i=lg[dep[y]]-1;i>=0;--i)
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(mxval[xx]==mxval[yy]){
		mxdfn[xx]=max(mxdfn[xx],mxdfn[yy]);
		midfn[xx]=min(midfn[xx],midfn[yy]);
	}else{
		mxdfn[xx]=(mxval[xx]>=mxval[yy])?mxdfn[xx]:mxdfn[yy];
		midfn[xx]=(mxval[xx]>=mxval[yy])?midfn[xx]:midfn[yy];
	}
	mxval[xx]=max(mxval[xx],mxval[yy]);
	fa[yy]=xx;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>e[i];
	vector<Edge>edge(n-1);
	for(int i=0;i<n-1;++i){
		cin>>edge[i].u>>edge[i].v>>edge[i].c>>edge[i].t;
	}
	sort(edge.begin(), edge.end(),[&](Edge a,Edge b){
		return a.t<b.t;
	});	 	 
	cnt=n;
	for(int i=1;i<=2*n;++i)fa[i]=i;
	for(int i=0;i<n-1;++i){
		int xx=find(edge[i].u),yy=find(edge[i].v);
		val[++cnt]=edge[i].t;
		fa[xx]=fa[yy]=cnt;
		G[xx].eb(cnt);G[cnt].eb(xx);
		G[yy].eb(cnt);G[cnt].eb(yy);
	}
	for(int i=1;i<=2*n;++i)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	dfs(cnt,0);
	vector<Qu>Q;
	Q.resize(q);
	for(int i=0;i<q;++i){
		cin>>Q[i].v>>Q[i].x;
		Q[i].id=i;
	}
	sort(edge.begin(), edge.end(),[&](Edge a,Edge b){
		return a.c>b.c;
	});
	sort(Q.begin(), Q.end(),[&](Qu a,Qu b){
		return a.v>b.v;
	});
	for(int i=1;i<=n;++i)fa[i]=i,mxdfn[i]=midfn[i]=dfn[i],mxval[i]=e[i];
	int now=0;
	vector<pair<int,int> >ans;
	ans.resize(q);
	for(int i=0;i<q;++i){
		while(now<=n-2&&edge[now].c>=Q[i].v){
			merge(edge[now].u,edge[now].v);
			now++;
		}
		int xx=find(Q[i].x);
		ans[Q[i].id].fi=mxval[xx];
		ans[Q[i].id].se=max(val[lca(Q[i].x,id[mxdfn[xx]])],val[lca(Q[i].x,id[midfn[xx]])]);
	}
	for(auto &[u,v]:ans)
		cout<<u<<" "<<v<<"\n";
	return 0;
}