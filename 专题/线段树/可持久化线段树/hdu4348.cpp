//标记永久化 区间加区间和
#include<bits/stdc++.h>
using namespace std;
#define lson lc[p],l,mid 
#define rson rc[p],mid+1,r 
#define ls lc[p]
#define rs rc[p]
#define N maxn*32
typedef long long ll;
const int maxn=1e5+5;
int rt[maxn],last[maxn],n,m,L,R,nowtime,d,t;
char s[2];
struct Persistable_SegmentTree{
    int tot,lc[N],rc[N],add[N];
    ll sum[N];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    void update(int q,int&p,int l,int r,int L,int R,int val){
        p=++tot;
        ls=lc[q];rs=rc[q];sum[p]=sum[q];add[p]=add[q];
        sum[p]+=1ll*(min(R,r)-max(L,l)+1)*val;//非完全包含带着标记更新/pushUp 看情况
        if(L<=l&&r<=R){
            add[p]+=val;//完全包含就标记
            return;
        }
        int mid=l+r>>1;
        if(L<=mid)update(lc[q],lson,L,R,val);
        if(R>mid)update(rc[q],rson,L,R,val);
    }
    void build(int&p,int l,int r){
        p=++tot;
        add[p]=0;
        if(l==r){
            scanf("%lld",&sum[p]);return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    ll query(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1;
        ll ans=1ll*add[p]*(min(R,r)-max(L,l)+1);//查询的时候累积标记值下查
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
}tr;
int main(){
    while(~scanf("%d%d",&n,&m)){
        tr.tot=nowtime=0;
        tr.build(rt[0],1,n);
        for(int i=1;i<=m;++i){
            scanf("%s",s);
            if(s[0]=='C'){
                scanf("%d%d%d",&L,&R,&d);
                nowtime++;
                tr.update(rt[nowtime-1],rt[nowtime],1,n,L,R,d);
            }else if(s[0]=='Q'){
                scanf("%d%d",&L,&R);
                cout<<tr.query(rt[nowtime],1,n,L,R)<<"\n";
            }else if(s[0]=='H'){
                scanf("%d%d%d",&L,&R,&t);
                cout<<tr.query(rt[t],1,n,L,R)<<"\n";
            }else if(s[0]=='B'){
                scanf("%d",&nowtime);
            }
        }
    }
    return 0;
}