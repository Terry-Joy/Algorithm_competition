#include<bits/stdc++.h>
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define ls lc[p]
#define rs rc[p]
#define N maxn*40
using namespace std;
const int maxn=1e6+5;
int a[maxn];
struct Persistable_SegmentTree{
    int tot,rt[maxn],val[N],lc[N],rc[N];
    void build(int&p,int l,int r){
        p=++tot;
        if(l==r){
            val[p]=a[l];return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
    }
    void update(int pre,int&p,int l,int r,int x,int w){
        p=++tot;
        ls=lc[pre];rs=rc[pre];val[p]=val[pre];//复制结点备用
        if(l==r){
            val[p]=w;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lc[pre],lson,x,w);
        else update(rc[pre],rson,x,w);
    }
    int query(int p,int l,int r,int x){
        if(l==r)return val[p]; 
        int mid=l+r>>1;
        if(x<=mid)return query(lson,x);
        else return query(rson,x);
    }
}tr;
int n,m;
int main(){
    int pre,op,pos,w;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    tr.build(tr.rt[0],1,n);
    for(int i=1;i<=m;++i){
        cin>>pre>>op>>pos;
        if(op==2){
            cout<<tr.query(tr.rt[pre],1,n,pos)<<"\n";
            tr.rt[i]=tr.rt[pre];
        }else{
            cin>>w;
            tr.update(tr.rt[pre],tr.rt[i],1,n,pos,w);
        }
    }
    return 0;
}