#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
using ll=long long;
const int maxn=1e5+10;
int n,m,H[maxn];
struct SegmentTree{//求有多少个位置是前缀最大值
    int sum[maxn<<2],id[maxn<<2];//sum只考虑当前子树影响下 右子树的答案
    bool isBig(int id1,int id2){ //is id1 > id2
        if(!id2)return H[id1];
        return (ll)H[id1]*id2>(ll)H[id2]*id1;
    }
    int cal(int p,int l,int r,int mxid){ //p子树内 考虑了前缀最大值mxid后的答案
         if(l==r)return isBig(l,mxid);
         int mid=l+r>>1;
         if(isBig(id[ls],mxid))return cal(lson,mxid)+sum[p];
         else return 0+cal(rson,mxid);
    }
    void pushUp(int p,int l,int r,int mid){ 
        id[p]=isBig(id[rs],id[ls])?id[rs]:id[ls];
        sum[p]=cal(rson,id[ls]);
    }
    void build(int p,int l,int r){ 
        id[p]=l;sum[p]=1;//叶子节点下sum是什么随意
        if(l==r)return;
        int mid=l+r>>1;
        build(lson);
        build(rson);
    }
    void update(int p,int l,int r,int x){ 
        if(l==r) return;
        int mid=l+r>>1;
        if(x<=mid)update(lson,x);
        else update(rson,x);
        pushUp(p,l,r,mid);
    }
}tr;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    tr.build(1,1,n);
    for(int i=1;i<=m;++i){ 
        int x,y;
        cin>>x>>y;
        H[x]=y;
        tr.update(1,1,n,x);
        cout<<tr.cal(1,1,n,0)<<"\n";
    }
    return 0;
}
