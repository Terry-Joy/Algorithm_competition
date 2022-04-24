#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=1005;
struct Line{
    int xL,xR,flag,h;
    bool operator<(const Line&a){return h<a.h;}
}line[maxn<<1];
int X[maxn<<1],Z[maxn<<1],t,n,T=0;
struct SegmentTree{
    int cnt[maxn<<3],len[maxn<<3][4];
    void build(int p,int l,int r){
        cnt[p]=0;
        for(int i=1;i<=3;++i)len[p][i]=0;
        len[p][0]=X[r+1]-X[l];
        if(l==r)return;
        int mid=l+r>>1;
        build(lson);
        build(rson);
    }
    void pushUp(int p,int l,int r){
        for(int i=0;i<=3;++i)len[p][i]=0;
        if(cnt[p]>=3)len[p][3]=X[r+1]-X[l];
        else if(l==r)len[p][cnt[p]]=X[r+1]-X[l];
        else{
            for(int i=0;i<=3;++i)
                len[p][min(3,i+cnt[p])]+=len[ls][i]+len[rs][i];
        }
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
struct Node{
    int X1,Y1,Z1,X2,Y2,Z2;
}node[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>node[i].X1>>node[i].Y1>>node[i].Z1>>node[i].X2>>node[i].Y2>>node[i].Z2;
            Z[(i<<1)-1]=node[i].Z1,Z[(i<<1)]=node[i].Z2;
        }
        if(n<=2){
            cout<<"Case "<<++T<<": 0\n";continue;
        }
        sort(Z+1,Z+1+2*n);
        int cntz=unique(Z+1,Z+1+2*n)-(Z+1),numline=0;
        ll ans=0;
        for(int i=2;i<=cntz;++i){
            int H=Z[i]-Z[i-1],cntX=0;
            numline=0;
            for(int j=1;j<=n;++j){
                if(node[j].Z2<=Z[i-1]||node[j].Z1>=Z[i])continue;
                line[++numline]={node[j].X1,node[j].X2,1,node[j].Y1};
                line[++numline]={node[j].X1,node[j].X2,-1,node[j].Y2};
                X[++cntX]=node[j].X1;X[++cntX]=node[j].X2;
            }
            sort(line+1,line+1+numline);
            sort(X+1,X+1+cntX);
            int m=unique(X+1,X+1+cntX)-(X+2);
            tr.build(1,1,m);
            for(int j=1;j<=numline;++j){
                ans+=1ll*H*(line[j].h-line[j-1].h)*tr.len[1][3];
                int l1=lower_bound(X+1,X+2+m,line[j].xL)-X;
                int r1=lower_bound(X+1,X+2+m,line[j].xR)-(X+1);
                tr.update(1,1,m,l1,r1,line[j].flag);
            }
        }
        cout<<"Case "<<++T<<": "<<ans<<"\n";
    }
    return 0;
}