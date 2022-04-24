#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
struct SementTree{
    ll sum[maxn*90],add[maxn*90];
    bool rev[maxn*90];
    int rt,tot,lc[maxn*90],rc[maxn*90];
    void pushUp(int p){
        sum[p]=sum[lc[p]]+sum[rc[p]];
    }
    void pushDown(int p,ll l,ll r){
        ll mid=l+r>>1;
        if(~add[p]){
            rev[ls]=rev[rs]=0;
            sum[ls]=(mid-l+1)*add[p];
            sum[rs]=(r-mid)*add[p];
            add[ls]=add[rs]=add[p];
            add[p]=-1;
        }
        if(rev[p]){
            rev[ls]^=1;rev[rs]^=1;
            sum[ls]=mid-l+1-sum[ls];sum[rs]=r-mid-sum[rs];
            rev[p]=0;
        }
    }
    void update(int&p,ll l,ll r,ll L,ll R,bool f,int val){
        if(!p)p=++tot;
        if(L<=l&&r<=R){
            if(f){
                sum[p]=(r-l+1)*val;
                add[p]=val;rev[p]=0;
            }else{
                sum[p]=r-l+1-sum[p];
                rev[p]^=1;
            }
            return;
        }
        pushDown(p,l,r);
        ll mid=l+r>>1;
        if(L<=mid)update(lson,L,R,f,val);
        if(R>mid)update(rson,L,R,f,val);
        pushUp(p);
    }
    ll query(int &p,ll l,ll r){
        if(!p)p=++tot;
        if(l==r)return l;
        pushDown(p,l,r);
        ll mid=l+r>>1;
        if(sum[ls]<mid-l+1)return query(lson);
        else return query(rson);
    }
}tr;
int n,k;
ll l,r;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%lld%lld",&k,&l,&r);
        if(k==1)tr.update(tr.rt,1,1000000000000000000,l,r,1,1);
        else if(k==2)tr.update(tr.rt,1,1000000000000000000,l,r,1,0);
        else tr.update(tr.rt,1,1000000000000000000,l,r,0,0);
        cout<<tr.query(tr.rt,1,1000000000000000000)<<"\n";
    }
    return 0;
}