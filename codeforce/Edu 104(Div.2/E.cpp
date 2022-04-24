#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=150005;
const int INF=1e9;
int t,n,ni[5],m[5],a[5][maxn],cnt=0;
vector<int>G[5][maxn];
pair<int,int>pre[maxn];
struct SegmentTree{
    int mx[maxn<<2];
    void pushUp(int p){
        mx[p]=min(mx[ls],mx[rs]);
    }
    void update(int p,int l,int r,int x,int val){
        if(l==r){
            if(val==INF)mx[p]=val;
            else mx[p]=min(mx[p],val);return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    void build(int p,int l,int r){
        if(l==r){
            mx[p]=INF;return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    int query(int p,int l,int r,int x){
        if(l==r)return mx[p];
        int mid=l+r>>1;
        if(x<=mid)return query(lson,x);
        else return query(rson,x);
    }
}tr[5];
void init(int id){
    int x,y;
    cin>>m[id];
    for(int i=1;i<=m[id];++i){
        cin>>x>>y;
        G[id][y].pb(x);
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=4;++i)cin>>ni[i];
    for(int i=1;i<=4;++i)
    	tr[i].build(1,1,ni[i]);
    for(int i=1;i<=ni[1];++i){
        cin>>a[1][i];
        tr[1].update(1,1,ni[1],i,a[1][i]);
    }
    for(int i=2;i<=4;++i)
		for(int j=1;j<=ni[i];++j)cin>>a[i][j]; 
    for(int i=2;i<=4;++i)
        init(i);
    for(int i=2;i<=4;++i){
        for(int j=1;j<=ni[i];++j){
            cnt=0;
            for(int k=0;k<G[i][j].size();++k){
                pre[++cnt]={G[i][j][k],tr[i-1].query(1,1,ni[i-1],G[i][j][k])};
                tr[i-1].update(1,1,ni[i-1],G[i][j][k],INF);
            }
            int now=min(tr[i-1].mx[1]+a[i][j],INF);
            tr[i].update(1,1,ni[i],j,now);
            for(int k=1;k<=cnt;++k)
                tr[i-1].update(1,1,ni[i-1],pre[k].fi,pre[k].se);
        }
    }
    int ans=tr[4].mx[1];
    if(ans==INF)cout<<-1<<"\n";
    else cout<<ans<<"\n";
    return 0;
}
