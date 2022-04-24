#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const int maxn=1005;
const LD INF=0x3f3f3f3f3f3f3f3fLL,eps=1e-8;
struct edge { int obj,last; } e[maxn];
int n,E,P,cnt,point[maxn],cost[maxn],val[maxn];
LD ans;
bool vis[maxn];
void add_edge(int x,int y)
{
	cnt++;
	e[cnt].obj=y;
	e[cnt].last=point[x];
	point[x]=cnt;
}
void dfs(int u,int dep,LD base,LD es,LD ps)
{
	if(dep==1)base=1;
	else base=0.5;
	vis[u]=true;
	es+=cost[u]*base;
	ps+=val[u];
	LD eb=es/dep,pb=ps/dep;
	if(P*eb<=pb*E)
	{
		ans=0;
		return;
	}
	if (pb>eps) ans=min(ans,eb/pb*log(eb/pb/E*P));
	for (int i=point[u];i;i=e[i].last)
		dfs(e[i].obj,dep+1,base,es,ps);
}
int main()
{
	while (true)
	{
		scanf("%d%d%d",&n,&E,&P);
		if (!n && !E && !P) break;
		ans=INF;
		cnt=0;
		for (int i=1;i<=n;i++) point[i]=0,vis[i]=false;
		for (int i=1,x;i<=n;i++)
		{
			scanf("%d%d%d",&cost[i],&val[i],&x);
			if (x) add_edge(x,i);
		}
		for (int i=1;i<=n;i++) dfs(i,1,1,0,0);
		printf("%lld\n",(LL)ceil(ans));
	}
	return 0;
}
