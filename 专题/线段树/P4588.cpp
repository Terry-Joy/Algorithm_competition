#include<bits/stdc++.h>
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r
#define ls p<<1 
#define rs p<<1|1
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll mul[maxn<<2];
int q,mod;
void pushUp(int p){ 
    mul[p]=mul[ls]*mul[rs]%mod;
}
void update(int p,int l,int r,int pos,ll val){ 
    if(l==r){ 
        mul[p]=val;return;
    }
    int mid=l+r>>1;
    if(pos<=mid)update(lson,pos,val);
    else update(rson,pos,val);
    pushUp(p);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){ 
        scanf("%d%d",&q,&mod);
        int op;
        ll m;
        for(int i=1;i<=4*q;++i)mul[i]=1;
        for(int i=1;i<=q;++i){ 
            scanf("%d%lld",&op,&m);
            if(op==1)update(1,1,q,i,m);
            else update(1,1,q,m,1);
            cout<<mul[1]<<"\n";
        } 
    }
    return 0;
}
