#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=2e5+10000;
const int INF=1e9;
int n,r,dist[maxn],dist2[maxn],a,b,c;
struct edge
{
	int to,cost;
	edge(int x,int y):to(x),cost(y){}
};
typedef pair<int,int>P;
vector<edge>G[maxn];
void dijkstra(int x)
{
	priority_queue<P,vector<P>,greater<P> >q;
	fill(dist,dist+n+1,INF);
	fill(dist2,dist2+n+1,INF);
	dist[x]=0;
	q.push(P(0,1));
	while(!q.empty())
	{
		P p=q.top();
		q.pop();
		int v=p.second,d=p.first;
		if(d>dist2[v])continue;
		for(int i=0;i<G[v].size();++i)
		{
			edge e=G[v][i];
			int d2=d+e.cost;
			if(dist[e.to]>d2)
			{
				swap(dist[e.to],d2);
				q.push(P(dist[e.to],e.to));
			}
			if(dist2[e.to]>d2&&dist[e.to]<d2)
			{
				dist2[e.to]=d2;
				q.push(P(dist2[e.to],e.to));
			}
		}
	}
}
int main()
{
	while(scanf("%d%d",&n,&r)!=EOF)
	{
		while(r--)
		{
			scanf("%d%d%d",&a,&b,&c);
			G[a].push_back(edge(b,c));
			G[b].push_back(edge(a,c));
		}
		dijkstra(1);
		printf("%d\n",dist2[n]);
	}
	return 0;
}
 
