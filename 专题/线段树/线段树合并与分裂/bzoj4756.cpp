#include<bits/stdc++.h>
#define pb push_back
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define N maxn*50
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],x,ans[maxn],mx;
vector<int>G[maxn];
struct SegmentTree{
    int rt[maxn],tot,num[N],lc[N],rc[N];
    void pushUp(int p){
        num[p]=num[ls]+num[rs];
    }
    void update(int&p,int l,int r,int x){
        if(!p)p=++tot;
        if(l==r){
            num[p]++;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x);
        else update(rson,x);
        pushUp(p);
    }
    int query(int&p,int l,int r,int L,int R){
        if(R<L)return 0;
        if(L<=l&&r<=R)return num[p];
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
    int merge(int p,int q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){
            num[p]+=num[q];return p;
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
    tr.update(tr.rt[x],1,mx,a[x]);
    ans[x]=tr.query(tr.rt[x],1,mx,a[x]+1,mx);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],mx=max(mx,a[i]);
    for(int i=2;i<=n;++i){
        cin>>x;
        G[x].pb(i);
        G[i].pb(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i)cout<<ans[i]<<"\n";    
    return 0;
}