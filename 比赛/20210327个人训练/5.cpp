//可持久化左偏树求k短路
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
const int N = 8e5 + 5, M = N * 4;
long long inf = 1e18 + 7;
int n, m, i, S, T, K, x, y, z;
int g[N], v[M], u[M], w[M], nxt[M], f[N], h[N], tot;
bool is[M], vis[N];
long long d[N];
struct Node {
	int l, r, d;
	P v;
	Node(){}
	Node(int _l, int _r, int _d, P _v){l = _l, r = _r, d = _d, v = _v;}
}pool[M * 5];
int build(P v) {
	pool[++tot]=Node(0,0,0,v);
	return tot;
}
int merge(int a, int b) {
	if(!a || !b)
		return a + b;
	if(pool[a].v > pool[b].v)
		swap(a, b);
	int x = ++ tot;
	pool[x] = pool[a];
	pool[x].r = merge(pool[a].r, b);
	if(pool[pool[x].l].d < pool[pool[x].r].d)
		swap(pool[x].l, pool[x].r);
	pool[x].d = pool[x].r ? pool[pool[x].r].d + 1 : 0;
	return x;
}
void getdis() {
	int i, x;
	priority_queue<P, vector<P>, greater<P> >q;
	for(int i=1;i<=T;++i)
		d[i] = inf, f[i] = 0;
	q.push(P(d[T]=0,T));
	while(!q.empty()) {
		P t = q.top();q.pop();
		if(t.first > d[x=t.second])
			continue;
		for(i=g[x];i;i=nxt[i])
			if(d[v[i]]>d[x]+w[i])
				f[v[i]]=i,q.push(P(d[v[i]]=d[x]+w[i],v[i]));
	}
}
void dfs(int x) {
	if(!f[x]||vis[x])
		return;
	vis[x]=1;
	dfs(u[f[x]]);
	h[x]=merge(h[x],h[u[f[x]]]);
}
void add(int x, int y, int z) {
	// cerr << "Add " << x << " -> " << y << ": " << z << endl;
	v[++m] = x;
	u[m] = y;
	w[m] = z;
	nxt[m] = g[y];
	g[y] = m;
}
int Getid(int x, int y) {
	return (x - 1) * 3 + y + 1;
}
int val[N];
int main() {
	memset(g, 0, sizeof g), m = 0;
	scanf("%d%d", &n, &K);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &val[i]);
	for(i = 2; i <= n; ++ i) {
		add(Getid(i - 1, 0), Getid(i, 0), val[i]);
		add(Getid(i - 1, 0), Getid(i, 1), 0);
		add(Getid(i - 1, 1), Getid(i, 0), val[i]);
		add(Getid(i - 1, 1), Getid(i, 2), 0);
		add(Getid(i - 1, 2), Getid(i, 0), val[i]);
	}
	S = n * 3 + 1, T = S + 1;
	add(S, Getid(1, 0), val[1]);
	add(S, Getid(1, 2), 0);
	add(Getid(n, 0), T, 0);
	add(Getid(n, 1), T, 0);

	getdis();
	// for(int i = 0; i <= T; ++ i)
	// 	cerr << d[i] << " ";
	// cerr << endl;
	printf("%lld\n", d[S]);
	K --;
	for(i = 1; i <= m; ++ i)
		is[i] = 0;
	for(tot = 0, i = 1; i <= T; ++ i)
		is[f[i]] = 1, h[i] = vis[i] = 0;
	for(i = 1; i <= m; ++ i)
		if(!is[i]&&d[u[i]]<inf)
			h[v[i]]=merge(h[v[i]],build(P(w[i]-d[v[i]]+d[u[i]],u[i])));
	for(i = 1; i <= T; ++ i)
		dfs(i);
	priority_queue<P,vector<P>,greater<P> >q;
	long long ans, x, y;
	y = h[S];
	if(y)
		q.push(P(d[S]+pool[y].v.first,y));
	while(!q.empty()&&K) {
		-- K;
		P t = q.top();
		q.pop();
		printf("%lld\n", ans = t.first);
		x=t.second,y=pool[x].l;
		if(y)
			q.push(P(ans-pool[x].v.first+pool[y].v.first,y));
		y=pool[x].r;
		if(y)
			q.push(P(ans-pool[x].v.first+pool[y].v.first,y));
		y=h[pool[x].v.second];
		if(y)
			q.push(P(ans+pool[y].v.first,y));
	}
	while(K--)
		printf("%d\n", -1);
}