//区间内ki不同数，求第ki/2出现的位置
#include<bits/stdc++.h>
#define N maxn*36
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=2e5+5;
int rt[maxn],pre[maxn],t,n,m,L,R,a[maxn];
struct Persistable_SegmentTree{
    int tot,lc[N],rc[N],sum[N];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void update(int q,int &p,int l,int r,int x,int val){
        p=++tot;
        ls=lc[q];rs=rc[q];sum[p]=sum[q];
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
    int kth(int p,int l,int r,int k){
        if(l==r)return l;
        int mid=l+r>>1;
        if(sum[ls]>=k)return kth(lson,k);
        else return kth(rson,k-sum[ls]);
    }
}tr;
void init(){
    tr.tot=0;
    memset(pre,0,sizeof(pre));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    int T=0;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i)cin>>a[i];
        cout<<"Case #"<<++T<<":";
        for(int i=n;i;--i){
            if(pre[a[i]]){
                tr.update(rt[i+1],rt[i],1,n,pre[a[i]],-1);
                tr.update(rt[i],rt[i],1,n,i,1);
            }else
                tr.update(rt[i+1],rt[i],1,n,i,1);
            pre[a[i]]=i;
        }
        int preans=0;
        for(int i=1;i<=m;++i){
            cin>>L>>R;
            L=(L+preans>=(n))?(L+preans-n+1):(L+preans+1);//只是强制在线
            R=(R+preans>=(n)?R+preans-n+1:R+preans+1);
            if(L>R)swap(L,R);
            int num=tr.query(rt[L],1,n,1,R);
            preans=tr.kth(rt[L],1,n,(num+1)/2);
            cout<<" "<<preans;
        }
        cout<<"\n";
        init();
    }
    return 0;
}
