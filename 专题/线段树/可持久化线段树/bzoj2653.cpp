#include<bits/stdc++.h>
#define N maxn*30
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define fi first 
#define se second
using namespace std;
const int maxn=2e4+5;
int rt[maxn];
pair<int,int>a[maxn];
struct Persistable_SegmentTree{
    int tot,lc[N],rc[N],sum[N],lsum[N],rsum[N];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
        lsum[p]=max(lsum[ls],sum[ls]+lsum[rs]);
        rsum[p]=max(rsum[rs],sum[rs]+rsum[ls]);
    }
    void build(int&p,int l,int r){
        p=++tot;
        if(l==r){
            sum[p]=lsum[p]=rsum[p]=1;
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void update(int q,int&p,int l,int r,int x,int val){
        p=++tot;
        ls=lc[q];rs=rc[q];sum[p]=sum[q];lsum[p]=lsum[q];rsum[p]=rsum[q];
        if(l==r){
            sum[p]=lsum[p]=rsum[p]=-1;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lc[q],lson,x,val);
        else update(rc[q],rson,x,val);
        pushUp(p);
    }
    int queryS(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1,ans=0;
        if(L<=mid)ans+=queryS(lson,L,R);
        if(R>mid)ans+=queryS(rson,L,R);
        return ans;
    }
    int queryLS(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return lsum[p];
        int mid=l+r>>1;
        if(R<=mid)return queryLS(lson,L,R);
        else if(L>mid)return queryLS(rson,L,R);
        else{
            return max(queryS(lson,L,R)+queryLS(rson,L,R),queryLS(lson,L,R));
        }
    }
    int queryRS(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return rsum[p];
        int mid=l+r>>1;
        if(R<=mid)return queryRS(lson,L,R);
        else if(L>mid)return queryRS(rson,L,R);
        else{
            return max(queryS(rson,L,R)+queryRS(lson,L,R),queryRS(rson,L,R));
        }
    }
}tr;
int n,q,pre,qs[4];
bool check(int x,int a,int b,int c,int d){
    int ans=0;
    if(b+1<=c-1)ans+=tr.queryS(rt[x],1,n,b+1,c-1);
    ans+=tr.queryRS(rt[x],1,n,a,b);
    ans+=tr.queryLS(rt[x],1,n,c,d);
    return ans>=0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i].fi,a[i].se=i;
    sort(a+1,a+1+n);
    tr.build(rt[1],1,n);
    for(int i=2;i<=n;++i){
        tr.update(rt[i-1],rt[i],1,n,a[i-1].se,-1);
    }
    cin>>q;
    int pre=0;
    for(int i=1;i<=q;++i){
        for(int j=0;j<4;++j)cin>>qs[j],qs[j]=(qs[j]+pre)%n;
        sort(qs,qs+4);
        int l=0,r=n;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid,qs[0]+1,qs[1]+1,qs[2]+1,qs[3]+1))l=mid;
            else r=mid-1;
        }
        pre=a[l].fi;
        cout<<pre<<"\n";
    }
    return 0;
}