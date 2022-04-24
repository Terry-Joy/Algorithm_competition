#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
#define mst(a) memset(a,0,sizeof a)
vector<int>e[N];
int n,m,ans[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v),e[v].push_back(u);
	}
	ans[1]=1;
	queue<int>q;
	q.push(1);
	while(q.size()){
		int u=q.front();q.pop();
		for(auto v:e[u])
			if(!ans[v]) ans[v]=u,q.push(v); 
	}
	puts("Yes");
	for(int i=2;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
} 
