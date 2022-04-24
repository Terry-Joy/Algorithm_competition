#include<bits/stdc++.h>
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r
#define ls p<<1 
#define rs p<<1|1
using namespace std;
const int maxn=3.5e4+5;
const int INF=2e9;
int pre[maxn],pos[maxn],dp[maxn],n,k,a[maxn];
struct SegmentTree{
    int add[maxn<<2],mn[maxn<<2];
    void pushUp(int p){
        mn[p]=min(mn[ls],mn[rs]);
    }
    void build(int p,int l,int r){
        add[p]=0;
        if(l==r){
            mn[p]=dp[l];return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void pushDown(int p){
        mn[ls]+=add[p];mn[rs]+=add[p];
        add[ls]+=add[p];add[rs]+=add[p];
        add[p]=0;
    }
    int query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return mn[p];
        if(add[p])pushDown(p);
        int mid=l+r>>1,ans=INF;
        if(L<=mid)ans=min(ans,query(lson,L,R));
        if(R>mid)ans=min(ans,query(rson,L,R));
        return ans;
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            mn[p]+=val;add[p]+=val;return;
        }
        if(add[p])pushDown(p);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
}tr;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i){
        pre[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;++i)dp[i]=INF;
    dp[0]=0;
    for(int j=1;j<=k;++j){
        for(int i=0;i<j-1;++i)dp[i]=INF;
        tr.build(1,0,n);
        for(int i=j;i<=n;++i){
            int val=(pre[i]?i-pre[i]:0);
            if(pre[i]&&val)tr.update(1,0,n,0,pre[i]-1,val);
            dp[i]=tr.query(1,0,n,0,i-1);
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}