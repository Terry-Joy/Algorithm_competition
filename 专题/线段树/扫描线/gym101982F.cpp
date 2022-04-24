#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls p<<1
#define rs p<<1|1
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
struct Line{
    int xL,xR,h;
    bool operator<(const Line&a){return h<a.h;}
}line[maxn<<1];
int X[maxn<<1],n,a,b,c,d;
struct SegmentTree{ 
    int cnt[maxn<<3],len[maxn<<3];
    void build(int p,int l,int r){ 
        cnt[p]=len[p]=0;
        if(l==r)return;
        int mid=l+r>>1;
        build(lson);
        build(rson);
    }
    void pushDown(int p,int l,int r){ 
        if(l==r)return;
        if(cnt[p]){ 
            cnt[ls]^=1;
            cnt[rs]^=1;
            int mid=l+r>>1;
            len[ls]=X[mid+1]-X[l]-len[ls];
            len[rs]=X[r+1]-X[mid+1]-len[rs];
            cnt[p]=0;
        }
    }
    void update(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            cnt[p]^=1;
            len[p]=X[r+1]-X[l]-len[p];
            return;
        }
        int mid=l+r>>1;
        pushDown(p,l,r);
        if(L<=mid)update(lson,L,R);
        if(R>mid)update(rson,L,R);
        len[p]=len[ls]+len[rs];
    }
}tr;
ll ans=0;
int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        ans=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a>>b>>c>>d;
            line[(i<<1)-1]={a,c,b};line[i<<1]={a,c,d};
            X[(i<<1)-1]=a;X[i<<1]=c;
        }
        sort(X+1,X+1+2*n);
        sort(line+1,line+1+2*n);
        int cnt=unique(X+1,X+1+2*n)-X-2;
        for(int i=1;i<=2*n;++i){
            int l1=lower_bound(X+1,X+1+cnt+1,line[i].xL)-X;
            int r1=lower_bound(X+1,X+1+cnt+1,line[i].xR)-X-1;
            ans+=1ll*tr.len[1]*(line[i].h-line[i-1].h);
            tr.update(1,1,cnt,l1,r1);
        }
        cout<<ans<<"\n";
        return 0;
}
