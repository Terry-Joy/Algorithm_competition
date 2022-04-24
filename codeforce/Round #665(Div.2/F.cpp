
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=1<<18;
const int maxm=20;
struct Node{
    int l,r;
    ll sum;
}tr[maxn<<2];
bool rev[maxm];
void pushUp(int p){
    tr[p].sum=tr[ls].sum+tr[rs].sum;
}
void build(int p,int l,int r){
    if(l==r){scanf("%lld",&tr[p].sum);return;}
    int mid=l+r>>1;
    build(lson);
    build(rson);
    pushUp(p);
}
void change(int p,int l,int r,int x,int val,int dep){
    if(l==r){tr[p].sum=val;return;}
    int mid=l+r>>1;
    if(x<=mid)change(p<<1|rev[dep],l,mid,x,val,dep-1);
    else change((p<<1|1)-(rev[dep]==1),mid+1,r,x,val,dep-1);
    pushUp(p);
}
ll ask(int p,int l,int r,int L,int R,int dep){
    if(L<=l&&r<=R)return tr[p].sum;
    int mid=l+r>>1;
    ll ans=0;
    if(L<=mid)ans+=ask(p<<1|rev[dep],l,mid,L,R,dep-1);
    if(R>mid)ans+=ask(2*p+1-(rev[dep]==1),mid+1,r,L,R,dep-1);
    return ans;
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    build(1,1,1<<n);
    while(q--){
        int d,k,l,r;
        scanf("%d",&d);
        switch(d){
            case 1:{
                int x,val;
                scanf("%d%d",&x,&val);
                change(1,1,1<<n,x,val,n); break;
            }
            case 2:{
                scanf("%d",&k);
                for(int i=0;i<=k;++i)rev[i]^=1;break;
            }
            case 3:{
                scanf("%d",&k);
                rev[k+1]^=1;break;
            }
            case 4:{
                scanf("%d%d",&l,&r);
                printf("%lld\n",ask(1,1,1<<n,l,r,n));       
            }
        }
    }
    return 0;
}