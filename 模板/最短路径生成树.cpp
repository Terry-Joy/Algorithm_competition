#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=(1<<31)-1;
const int N=1e3+10;
int g[N][N],dis[N],n,m,vis[N],hx[N];
void dijkstra()
{
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    for(int i=1;i<=n;i++)
    {
        int u=-1;
        for(int j=1;j<=n;j++)if(!vis[j])
            if(u==-1||dis[j]<dis[u])u=j;
        vis[u]=true;
        for(int j=1;j<=n;j++)if(!vis[j])
            dis[j]=min(dis[j],dis[u]+g[u][j]);
    }
}
bool cmp(const int &a,const int &b)
{
    return dis[a]<dis[b];
}
int main()
{
    //freopen("in.txt","r",stdin);
    memset(g,0x3f,sizeof(g));
    scanf("%d%d",&n,&m);
    int u,w,v;ll ans=1;
    for(int i=1;i<=n;i++)g[i][i]=0,hx[i]=i;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        g[u][v]=g[v][u]=min(g[u][v],w);
    }
    dijkstra();
    sort(hx+1,hx+n+1,cmp);
    for(int i=2;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<i;j++)
            if(dis[hx[j]]+g[hx[j]][hx[i]]==dis[hx[i]])
                cnt++;
        ans=(ans*cnt)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
