#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=3e4+5;
struct Line{
    int xL,xR,flag,h;
    bool operator<(const Line&a)const{return h<a.h;}
}line[maxn<<1];
int n,m,t,val[5],T=0,X[maxn<<1],hi[5];
struct RC{
    int X1,Y1,X2,Y2,Z;
}rec[maxn];
struct SegmentTree{
    int cnt[maxn<<3],len[maxn<<3];
    void build(int p,int l,int r){
        cnt[p]=len[p]=0;
        if(l==r)return;
        int mid=l+r>>1;
        build(lson);
        build(rson);
    }
    void pushUp(int p,int l,int r){
        if(cnt[p])len[p]=X[r+1]-X[l];
        else if(l==r)len[p]=0;
        else len[p]=len[ls]+len[rs];
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            cnt[p]+=val;
            return pushUp(p,l,r);
        }
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p,l,r);
    }
}tr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=m;++i)cin>>val[i],hi[i]=val[i];
        val[++m]=0;
        for(int i=1;i<=n;++i){
            cin>>rec[i].X1>>rec[i].Y1>>rec[i].X2>>rec[i].Y2>>rec[i].Z;
        }
        sort(val+1,val+1+m);
        int cntz=unique(val+1,val+1+m)-(val+1);
        ll ans=0;
        for(int i=2;i<=cntz;++i){
            int h=val[i]-val[i-1],cntx=0,cntline=0;
            for(int j=1;j<=n;++j){
                if(hi[rec[j].Z]<=val[i-1]||0>=val[i])continue;
                X[++cntx]=rec[j].X1,X[++cntx]=rec[j].X2;
                line[++cntline]={rec[j].X1,rec[j].X2,1,rec[j].Y1};
                line[++cntline]={rec[j].X1,rec[j].X2,-1,rec[j].Y2};
            }
            sort(X+1,X+1+cntx);
            sort(line+1,line+1+cntline);
            int numx=unique(X+1,X+1+cntx)-(X+2);
            tr.build(1,1,numx);
            for(int j=1;j<=cntline;++j){
                ans+=1ll*tr.len[1]*h*(line[j].h-line[j-1].h);
                int l1=lower_bound(X+1,X+2+numx,line[j].xL)-X;
                int r1=lower_bound(X+1,X+2+numx,line[j].xR)-(X+1);
                tr.update(1,1,numx,l1,r1,line[j].flag);
            }
        }
        cout<<"Case "<<++T<<": "<<ans<<"\n";
    }
    return 0;
}
