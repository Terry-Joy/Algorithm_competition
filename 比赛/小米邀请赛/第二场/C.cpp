#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
struct Node{
    ll mx,add;
}tr[maxn<<2];
ll a[maxn],b[maxn],c[maxn],s[maxn];
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m;
ll ask(int x){
    ll ans=0; 
    while(x>0){
        ans+=s[x];
        x-=x&-x;
    }
    return ans;
}
void pushUp(int p){
    tr[p].mx=max(tr[ls].mx,tr[rs].mx);
}
void pushDown(int p){
    if(tr[p].add){ 
        tr[ls].add+=tr[p].add;tr[rs].add+=tr[p].add;
        tr[ls].mx+=tr[p].add;tr[rs].mx+=tr[p].add;
        tr[p].add=0;
    }
}
void build(int p,int l,int r){
    tr[p].add=0;
    if(l==r){
        tr[p].mx=a[l]-c[l];return;
    }
    int mid=l+r>>1;
    build(lson);
    build(rson);
    pushUp(p);
}
void add(int x,ll val){
    while(x<=n){ 
        s[x]+=val; 
        x+=x&-x;
    }
}

void change(int p,int l,int r,int L,int R,ll val){
    if(L<=l&&r<=R){
        tr[p].mx+=val;tr[p].add+=val;
        return;
    }
    pushDown(p);
    int mid=l+r>>1;
    if(L<=mid)change(lson,L,R,val);
    if(R>mid)change(rson,L,R,val);
    pushUp(p);
}
ll query(int p,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        return tr[p].mx;
    }
    pushDown(p);
    int mid=l+r>>1;
    ll ans=-INF;
    if(L<=mid)ans=max(ans,query(lson,L,R));
    if(R>mid)ans=max(ans,query(rson,L,R));
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m){
        for(int i=1;i<=n;++i)s[i]=0;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i){ 
            cin>>b[i];
            add(i,b[i]);
            c[i]=b[i];
        }
        for(int i=1;i<=n;++i)c[i]+=c[i-1];
        build(1,1,n);
        int x,y;ll z;
        while(m--){
            cin>>x>>y;
            if(x==1){
                cin>>z;
                ll t=z-a[y];
                change(1,1,n,y,y,t);
                a[y]=z;
            }else if(x==2){ 
                cin>>z;
                ll t=z-b[y];
                add(y,t);
                change(1,1,n,y,n,-t);
                b[y]=z;
            }else{ 
                 ll s1=ask(y);
                 ll s2=max(0ll,query(1,1,n,1,y));
                 s2+=s1;
                 cout<<s2<<"\n";
            }
        }
    }
    return 0;
}
