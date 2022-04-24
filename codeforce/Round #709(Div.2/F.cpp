#include<bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1005;
const ll INF=1e18;
typedef double db;
typedef pair<int,int>P;
vector<P> a[maxn];
ll d[maxn][maxn],e[maxn][maxn],del[maxn],ans=0;
int n,m,q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)d[i][j]=INF;
        d[i][i]=0;
    }
    for(int i=1;i<=m;++i){
        int x,y,z;
        cin>>x>>y>>z;
        e[x][y]=e[y][x]=z;
        d[x][y]=d[y][x]=min(d[x][y],1ll*z);
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    cin>>q;
    for(int i=1;i<=q;++i){
        int x,y,z;
        cin>>x>>y>>z;
        a[x].pb({y,z});
        a[y].pb({x,z});
    }
    for(int i=1;i<=n;++i){//w+dis[u][j]<=L-dis[i][x1]
        for(int j=1;j<=n;++j){
            del[j]=-INF;
            for(auto&b:a[j]){
                int x1=b.fi;ll x2=b.se;
                del[j]=max(del[j],x2-d[i][x1]);
            }
        }
        for(int j=i+1;j<=n;++j){
            if(!e[i][j])continue;
            for(int x=1;x<=n;++x){
                if(del[x]>=e[i][j]+d[j][x]){
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}