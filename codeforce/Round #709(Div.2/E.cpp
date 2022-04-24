#include<bits/stdc++.h>
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r 
#define ls p<<1 
#define rs p<<1|1
#define fi first 
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=3e5+5;
int n,t,h[maxn],q[maxn];
ll b[maxn],dp[maxn];
struct SegmentTree{
    ll mx[maxn<<2],add[maxn<<2];
    ll query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return mx[p];
        pushDown(p);
        int mid=l+r>>1;
        ll ans=-1e18;
        if(L<=mid)ans=max(ans,query(lson,L,R));
        if(R>mid)ans=max(ans,query(rson,L,R));
        return ans;
    }
    void pushUp(int p){
        mx[p]=max(mx[ls],mx[rs]);
    }
    void pushDown(int p){
        if(add[p]){
            mx[ls]+=add[p];mx[rs]+=add[p];
            add[ls]=add[rs]=add[p];
            add[p]=0;
        }
    }
    void update(int p,int l,int r,int L,int R,ll val){
        if(L<=l&&r<=R){
            add[p]+=val;
            mx[p]+=val;
            return;
        }
        pushDown(p);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
}tr;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&h[i]);
    for(int i=1;i<=n;++i)scanf("%lld",&b[i]);
    t=0;
    q[++t]=0;
    h[0]=-1;
    for(int i=1;i<=n;++i){
        while(h[q[t]]>h[i]&&t){
            tr.update(1,0,n,q[t-1],q[t]-1,-b[q[t]]);
            t--;   
        }
        tr.update(1,0,n,q[t],i-1,b[i]);
        dp[i]=tr.query(1,0,n,0,i-1);
        tr.update(1,0,n,i,i,dp[i]);
        q[++t]=i;
    }
    cout<<dp[n]<<"\n";
    return 0;
}