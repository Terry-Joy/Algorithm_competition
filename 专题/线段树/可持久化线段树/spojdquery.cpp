//在线求区间不同数个数 和对应位置1改为值即可
#include<bits/stdc++.h>
#define N maxn*36
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=3e4+5;
const int maxm=1e6+5;   
int rt[maxn],a[maxn],pre[maxm],q,L,R,n,b[maxn];
struct Persistable_SegmentTree{//记录[1,i]中数最后一次出现的位置
    int lc[N],rc[N],sum[N],tot;
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void update(int q,int&p,int l,int r,int x,int val){
        p=++tot;
        ls=lc[q],rs=rc[q],sum[p]=sum[q];
        if(l==r){
            sum[p]+=val;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lc[q],lson,x,val);
        else update(rc[q],rson,x,val);
        pushUp(p);
    }
    int query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
}tr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    cin>>q;
    for(int i=1;i<=n;++i){
        if(pre[a[i]]){
            tr.update(rt[i-1],rt[i],1,n,pre[a[i]],-1);//可离散化x
            tr.update(rt[i],rt[i],1,n,i,1);
        }
        else tr.update(rt[i-1],rt[i],1,n,i,1);
        pre[a[i]]=i;
    }
    for(int i=1;i<=q;++i){
        cin>>L>>R;
        cout<<tr.query(rt[R],1,n,L,n)<<"\n";
    }
    return 0;
}