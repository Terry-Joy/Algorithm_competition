#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=3005;
const int ninf=0xcfcfcfcf;
int n,m,head[maxn],a[maxn],cnt,dp[maxn][maxn],num[maxn];

struct node{
    int v,w,nex;
}edge[maxn];

void adde(int u,int v,int w){
    edge[++cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].nex=head[u];
    head[u]=cnt;
}

void dfs(int u){
    if(!head[u]){
        dp[u][1]=a[u];
        num[u]=1;
        return;
    }
    for(int i=head[u];i;i=edge[i].nex){
        int v=edge[i].v;
        dfs(v);
        num[u]+=num[v];
    }
    for(int i=head[u];i;i=edge[i].nex){
        int v=edge[i].v;
        for(int j=num[u];j>=1;--j)		//j从1开始因为不选的时候完全可以不建,不用考虑 
            for(int k=1;k<=j;++k)
                if(dp[u][j-k]!=ninf&&dp[v][k]!=ninf)
                    dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]-edge[i].w);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dp[i][j]=ninf;
    for(int i=1;i<=n-m;++i){
        int k,t1,t2;
        scanf("%d",&k);
        for(int j=1;j<=k;++j){
            scanf("%d%d",&t1,&t2);
            adde(i,t1,t2);
        }
    }
    for(int i=n-m+1;i<=n;++i)
        scanf("%d",&a[i]);
    dfs(1);
    for(int i=m;i>=0;--i)
        if(dp[1][i]>=0){
            printf("%d\n",i);
            break;
        }
    return 0;
}
