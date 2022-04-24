#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
struct Line{
    int xL,xR,flag,h;
    bool operator<(const Line&a){return h<a.h;}
}line[maxn<<1];
int add[maxn<<3],n,X[maxn<<1],a,b,c,d;//当前线段覆盖次数 长度 
int len[maxn<<3];
ll ans=0;
void pushUp(int p,int l,int r){
    len[p]=add[p]?len[p]:(l==r?0:len[ls]+len[rs]);//叶子是[L,L+1]
}
void update(int p,int l,int r,int L,int R,int val){
    if(L<=l&&r<=R){
        add[p]+=val;
        if(add[p])len[p]=X[r+1]-X[l];
        else len[p]=0;
        pushUp(p,l,r);
        return;
    }
    int mid=l+r>>1;
    if(L<=mid)update(lson,L,R,val);
    if(R>mid)update(rson,L,R,val);
    pushUp(p,l,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a>>b>>c>>d;
        line[(i<<1)-1]={a,c,1,b};line[i<<1]={a,c,-1,d};
        X[(i<<1)-1]=a;X[i<<1]=c;
    }
    sort(X+1,X+1+2*n);
    sort(line+1,line+1+2*n);
    int cnt=unique(X+1,X+1+2*n)-X-2;
    for(int i=1;i<=2*n;++i){
        int l1=lower_bound(X+1,X+1+cnt+1,line[i].xL)-X;
        int r1=lower_bound(X+1,X+1+cnt+1,line[i].xR)-X-1;
        ans+=1ll*len[1]*(line[i].h-line[i-1].h);
        update(1,1,cnt,l1,r1,line[i].flag);
    }
    cout<<ans;
    return 0;
}