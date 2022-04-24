#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RG register
#define MAX 400000
const ll inf = 0x3f3f3f3f3f3f3f3fll;

inline int read()
{
    RG int x=0,t=1;RG char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
struct Line{int v,next,w;};
struct Link
{
    Line e[2 * MAX];
    int h[MAX],cnt;
    inline void Add(int u,int v,int w)
    {
        e[++cnt]=(Line){v,h[u],w};h[u]=cnt;
        e[++cnt]=(Line){u,h[v],w};h[v]=cnt;
    }
}T,G;
int n;
struct RST{ 
	ll dp[MAX][2], cir[MAX];
    bool zn[MAX];
    void dfs(int u, int ff) {
    	ll minrs = inf;
    	dp[u][0] = cir[u];
    	for(int i=T.h[u];i;i=T.e[i].next)
    	{
    		int v=T.e[i].v, w=T.e[i].w;
			if(v==ff)continue;
    		dfs(v, u);
    		if (u <= n)	{
				dp[u][0] += dp[v][0] + 2 * w;
				minrs = min(minrs, dp[v][1] - dp[v][0] - w); 
			}
    		else	{
    			dp[u][0] += dp[v][0];
    			minrs = min(minrs, w + dp[v][1] - dp[v][0]);
			}
		}
		if (minrs != inf)
			dp[u][1] = dp[u][0] + minrs; 
	}
}rst;
int dfn[MAX],low[MAX],tim,tp[MAX],dep[MAX];
int fa[MAX];
ll dis[MAX];
ll S[MAX],tot,m,Q;
vector<int> H[MAX];
void Build(int u,int y,int d){
    ll top = dep[y] - dep[u] + 1, sum = d, Dis=0;
    for(int i = y; i != u; i = fa[i]) S[top--] = i, sum += dis[i] - dis[fa[i]];
    ++tot; S[1] = u; top = dep[y] - dep[u] + 1; rst.cir[tot] = sum;
    for(int i = 1; i <= top; ++i)
    {
        ll D = min(Dis, sum - Dis);
        T.Add(tot, S[i], D);
        rst.zn[S[i]] = (D == Dis);
        Dis += dis[S[i+1]] - dis[S[i]];
    }
}
void Tarjan(int u,int in_edge)
{
    dfn[u]=low[u]=++tim;fa[u]=G.e[in_edge ^ 1].v;dep[u]=dep[fa[u]]+1;
    for(int i=G.h[u];i;i=G.e[i].next)
    {
        int v=G.e[i].v;if(i==(in_edge ^ 1))continue;
        if(!dfn[v])
        {
            dis[v]=dis[u]+G.e[i].w;
            Tarjan(v,i);low[u]=min(low[u],low[v]);
        }
        else
		{
			H[v].push_back(i ^ 1);
			low[u]=min(low[u],dfn[v]);
		}
        if(dfn[u]<low[v])T.Add(u,v,G.e[i].w);
    }
    for (int i : H[u])
    	Build(u, G.e[i].v, G.e[i].w);
}
int main()
{
    tot = n = read(); m = read();G.cnt = 1;
    for(int i=1;i<=m;++i)
    {
        int u=read(),v=read(),w=read();
        G.Add(u,v,w);
    }
    Tarjan(1,0);
    rst.dfs(1, 0);
    printf("%lld\n", rst.dp[1][1]);
    return 0;
}