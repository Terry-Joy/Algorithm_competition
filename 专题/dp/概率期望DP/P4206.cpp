#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e3+5;
const int INF=0x3f3f3f3f;
int p[maxn][maxn],head[maxn],next1[maxn<<1],ver[maxn<<1],d[maxn][maxn],tot;
int n,m,s,t,a,b,ti[maxn];
double dp[maxn][maxn];
void add(int x,int y){ 
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;ti[x]++;
}
double dfs(int x,int y){ 
    if(dp[x][y])return dp[x][y];
    if(x==y)return 0;
    if(p[x][y]==y||p[p[x][y]][y]==y)return dp[x][y]=1.0;
    double cnt=dfs(p[p[x][y]][y],y);
    for(int i=head[y];i;i=next1[i]){ //原地不动
        int z=ver[i];
        cnt+=dfs(p[p[x][y]][y],z);
    }
    return dp[x][y]=cnt/(ti[y]+1)+1;
}
void bfs(int x){ 
    queue<int>q;
    d[x][x]=0;
    q.push(x);
    while(!q.empty()){ 
        int u=q.front();q.pop();
        int tmp=p[x][u];
        for(int i=head[u];i;i=next1[i]){ 
            int y=ver[i];
            if(d[x][y]==INF||(d[x][y]==d[x][u]+1&&tmp<p[x][y])){ //第一次经过 满足最短路更新编号
                d[x][y]=d[x][u]+1;
                p[x][y]=tmp;
                if(!tmp)p[x][y]=y;
                q.push(y);
            }
        }
    }
}
int main(){ 
    memset(d,0,sizeof(d));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>s>>t;
    for(int i=1;i<=m;++i){ 
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;++i)bfs(i);
    printf("%.3lf",dfs(s,t));
    return 0;
}
