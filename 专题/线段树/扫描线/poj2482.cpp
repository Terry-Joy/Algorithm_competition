#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
int n,w,h;
const int maxn=1e4+5;
struct Line{
    ll xL,xR,h;
    int c;
    bool operator<(const Line&a)const{
        if(h==a.h)return c>a.c;
        return h<a.h;
    }
}line[maxn<<1];
int mx[maxn<<3],add[maxn<<3],c;
ll X[maxn<<1],x,y;
void pushUp(int p){
    mx[p]=max(mx[ls],mx[rs]);
}
void pushDown(int p,int l,int r){
    if(l==r){ add[p]=0;return;}
    if(add[p]){
        add[ls]+=add[p];
        add[rs]+=add[p];
        mx[ls]+=add[p];
        mx[rs]+=add[p];
        add[p]=0;
    }
}
void update(int p,int l,int r,int L,int R,int val){
    if(L<=l&&r<=R){
        mx[p]+=val;
        add[p]+=val;
        return;
    }
    int mid=l+r>>1;
    pushDown(p,l,r);
    if(L<=mid)update(lson,L,R,val);
    if(R>mid)update(rson,L,R,val);
    pushUp(p);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>w>>h){
        for(int i=1;i<=8*n;++i)add[i]=mx[i]=0;
        for(int i=1;i<=n;++i){
            cin>>x>>y>>c;
            line[(i<<1)-1]={x,x+w-1,y,c};
            line[i<<1]={x,x+w-1,y+h-1,-c};
            X[(i<<1)-1]=x;
            X[(i<<1)]=x+w-1;
        }
        sort(X+1,X+1+2*n);
        sort(line+1,line+1+2*n);
        int cnt=unique(X+1,X+1+2*n)-(X+1);
        int ans=0;
        for(int i=1;i<=2*n;++i){
            int l1=lower_bound(X+1,X+1+cnt,line[i].xL)-X;
            int r1=lower_bound(X+1,X+1+cnt,line[i].xR)-X;
            update(1,1,cnt,l1,r1,line[i].c);
            ans=max(ans,mx[1]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
