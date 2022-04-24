
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#define LL long long
#define N 500010
using namespace std;
 
struct Linear_Basis
{
    LL b[63],nb[63],tot;
 
    void init()
    {
        tot=0;
        memset(b,0,sizeof(b));
        memset(nb,0,sizeof(nb));
    }
 
    bool ins(LL x)
    {
        for(int i=62;i>=0;i--)
            if (x&(1LL<<i))
            {
                if (!b[i]) {b[i]=x;break;}
                x^=b[i];
            }
        return x>0;
    }
 
    LL Max(LL x)
    {
        LL res=x;
        for(int i=62;i>=0;i--)
            res=max(res,res^b[i]);
        return res;
    }
 
    LL Min(LL x)
    {
        LL res=x;
        for(int i=62;i>=0;--i)
            res=min(res,res^b[i]);
        return res;
    }
 
    void rebuild()
    {
        for(int i=62;i>=0;i--)
            for(int j=i-1;j>=0;j--)
                if (b[i]&(1LL<<j)) b[i]^=b[j];
        for(int i=0;i<=62;i++)
            if (b[i]) nb[tot++]=b[i];
    }
 
    LL Kth_Max(LL k)
    {
        LL res=0;
        for(int i=62;i>=0;i--)
            if (k&(1LL<<i)) res^=nb[i];
        return res;
    }
 
} LB;
 
struct Edge{int y;LL w;};
LL s[N],w[N],loop[N];
vector<Edge> g[N];
int n,m,tot;
bool v[N];
 
void dfs(int x)
{
    v[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i].y;
        LL w=g[x][i].w;
        if (!v[y]) s[y]=s[x]^w,dfs(y);
         else loop[++tot]=s[y]^s[x]^w;
    }
}
 
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		LB.init();
		for(int i=1;i<=m;i++)
        {
            int u,v; LL p;
            scanf("%d%d%lld",&u,&v,&p);
            g[u].push_back(Edge{v,p});
            g[v].push_back(Edge{u,p});
        }
        tot=0; dfs(1);
        for(int i=1;i<=tot;i++)
            LB.ins(loop[i]);
        printf("%lld\n %lld",LB.Max(100)^LB.Max(5),LB.Min(100^5));
	}
}
