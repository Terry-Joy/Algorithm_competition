#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll pre[maxn];
int a,n,L,R;
struct SegmentTree{
    int rt,tot,lc[maxn*60],rc[maxn*60],sum[maxn*60];
    void pushUp(int p){
        sum[p]=sum[lc[p]]+sum[rc[p]];
    }
    int query(int&p,ll l,ll r,ll L,ll R){
        if(!p)p=++tot;
        if(L<=l&&r<=R)return sum[p];
        ll mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lc[p],l,mid,L,R);
        if(R>mid)ans+=query(rc[p],mid+1,r,L,R);
        return ans;
    }
    void update(int&p,ll l,ll r,ll x,int val){
        if(!p)p=++tot;
        if(l==r){
            sum[p]+=val;
            return;
        }
        ll mid=l+r>>1;
        if(x<=mid)update(lc[p],l,mid,x,val);
        else update(rc[p],mid+1,r,x,val);
        pushUp(p);
    }
}tr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>L>>R;
    for(int i=1;i<=n;++i){
        cin>>a;
        pre[i]=pre[i-1]+a;
    }
    ll ans=0;
    tr.update(tr.rt,-1e10,1e10,0,1);
    for(int i=1;i<=n;++i){
        ans+=1ll*tr.query(tr.rt,-1e10,1e10,pre[i]-R,pre[i]-L);
        tr.update(tr.rt,-1e10,1e10,pre[i],1);
    }
    cout<<ans<<"\n";
    return 0;
}