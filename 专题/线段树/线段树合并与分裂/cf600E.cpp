//子树各众数值之和
#include<bits/stdc++.h>
#define pb push_back
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define N maxn*36
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,a[maxn],s,e,mx;
ll ans[maxn];
vector<int>G[maxn];
struct SegmentTree{
    int rt[maxn],lc[N],rc[N],tot,cnt[N];//cnt区间权值线段树中最大值
    ll sum[N];//各个众数之和
    void pushUp(int p){
        cnt[p]=max(cnt[ls],cnt[rs]);
        if(cnt[ls]==cnt[rs])sum[p]=sum[ls]+sum[rs];
        else sum[p]=cnt[ls]>cnt[rs]?sum[ls]:sum[rs];
    }
    void update(int &p,int l,int r,int x,int val){
        if(!p)p=++tot;
        if(l==r){
            cnt[p]+=val;sum[p]=l;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int merge(int p,int q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){
            cnt[p]+=cnt[q];
            sum[p]=l;return p;
        }
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        pushUp(p);
        return p;
    }
}tr;
void dfs(int x,int fa){
    for(auto&v:G[x]){
        if(v==fa)continue;
        dfs(v,x);
        tr.rt[x]=tr.merge(tr.rt[x],tr.rt[v],1,mx);   
    }
    tr.update(tr.rt[x],1,mx,a[x],1);
    ans[x]=tr.sum[tr.rt[x]];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],mx=max(a[i],mx);
    for(int i=1;i<n;++i){
        cin>>s>>e;
        G[s].pb(e);
        G[e].pb(s);
    }
    dfs(1,-1);
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}