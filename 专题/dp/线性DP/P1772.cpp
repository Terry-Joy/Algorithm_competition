#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
int n,m;
ll dp[105],k,e,cost[105][105];
struct Edge{
    int ed,val;
};
vector<Edge>G[25];
bool vis[25],li[22][105],noto[25];
int d[25];
void spfa(){
    for(int i=1;i<=m;++i)vis[i]=0,d[i]=1e9;
    queue<int>q;
    d[1]=0;q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int x=q.front();q.pop();
        vis[x]=0;
        for(auto&e:G[x]){
            int y=e.ed,z=e.val;
            if(noto[y])continue;
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                if(!vis[y]){
                    q.push(y);vis[y]=1;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k>>e;
    int a,b,c;
    for(int i=1;i<=e;++i){
        cin>>a>>b>>c;
        G[a].pb({b,c});
        G[b].pb({a,c});
    }
    int x;cin>>x;
    for(int i=1;i<=x;++i){
        cin>>a>>b>>c;
        for(int j=b;j<=c;++j)li[a][j]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            memset(noto,0,sizeof(noto));
            for(int k=i;k<=j;++k)
                for(int f=1;f<=m;++f)
                    if(li[f][k])noto[f]=1;
            spfa();
            cost[i][j]=d[m];
        }
    }
    for(int i=1;i<=n;++i)dp[i]=1e18;
    for(int i=1;i<=n;++i){
        dp[i]=cost[1][i]*i;      //无转折点 
        for(int j=1;j<=i-1;++j)
            dp[i]=min(dp[i],dp[j]+cost[j+1][i]*(i-j)+k);//必有转折点
    }
    cout<<dp[n];
    return 0;
}