#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
int t,n;
ll dis(ll X1,ll Y1,ll X2,ll Y2){ 
    return (X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2);
}
pair<int,int>P[5050];
int ans[5050],cnt=0;
bool vis[5050];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>n;
    for(int i=1;i<=n;++i)cin>>P[i].fi>>P[i].se;
    ans[++cnt]=1;
    vis[1]=1;
    int now=1,nex=1;
    while(cnt<n){ 
        ll mx=0;
        for(int j=1;j<=n;++j){ 
            if(vis[j])continue;
            if(dis(P[now].fi,P[now].se,P[j].fi,P[j].se)>mx){ 
                mx=dis(P[now].fi,P[now].se,P[j].fi,P[j].se);
                nex=j;
            }
        }
        ans[++cnt]=nex;
        vis[nex]=1;
        now=nex;
    }
    for(int i=1;i<=cnt;++i)cout<<ans[i]<<" ";
    return 0;
}
