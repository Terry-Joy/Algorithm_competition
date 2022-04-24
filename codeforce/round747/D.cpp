#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int fa[maxn],sum[maxn][2],n,m;
bool col[maxn];
int find(int x){
	if(x==fa[x])return x;
	else{
		int rt=find(fa[x]);
		col[x]^=col[fa[x]];
		return fa[x]=rt;
	}
}
void init(){
	for(int i=1;i<=n;++i)fa[i]=i,col[i]=0,sum[i][0]=1,sum[i][1]=0; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		init();
		string s;
		int u,v;
		bool f=1;
		for(int i=1;i<=m;++i){
			cin>>u>>v>>s;
			int xx=find(u),yy=find(v);
			bool val=(s[0]=='i');
			if(xx==yy){
				if(val!=(col[u]^col[v]))f=0;
			}else{
				fa[xx]=yy;
				col[xx]=val^col[u]^col[v];
				sum[yy][0]+=sum[xx][col[xx]];
				sum[yy][1]+=sum[xx][col[xx]^1];
			}
		}
		if(!f)cout<<"-1\n";
		else{
			int ans=0;
			for(int i=1;i<=n;++i){
				if(find(i)==i)ans+=max(sum[i][0],sum[i][1]);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}