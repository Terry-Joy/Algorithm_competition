
#include<bits/stdc++.h>
#define ls o<<1
#define rs o<<1|1
using namespace std;
struct tree{
    long long l,r,sum,tim,plu;
}tr[400005];
long long n,m,p,o,x,y,k,v[100005];
void build(long long o,long long l,long long r){
    tr[o].l=l,tr[o].r=r,tr[o].tim=1;
    if(l==r){
        tr[o].sum=v[l]%p;
        return;
    }
    long long mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    tr[o].sum=(tr[ls].sum+tr[rs].sum)%p;
}
void up(long long o){
	if(tr[o].plu==0&&tr[o].tim==1)return;
    tr[ls].sum=(tr[o].tim*tr[ls].sum+(tr[ls].r-tr[ls].l+1)*tr[o].plu%p)%p;
    tr[rs].sum=(tr[o].tim*tr[rs].sum+(tr[rs].r-tr[rs].l+1)*tr[o].plu%p)%p;
    tr[ls].tim=tr[ls].tim*tr[o].tim%p;//更新乘法标记 
    tr[rs].tim=tr[rs].tim*tr[o].tim%p; 
    tr[ls].plu=(tr[ls].plu*tr[o].tim+tr[o].plu)%p;//更新加法标记 ax+b与a'y+b' 
    tr[rs].plu=(tr[rs].plu*tr[o].tim+tr[o].plu)%p;
    tr[o].plu=0,tr[o].tim=1;
}
void time(long long o,long long l,long long r,long long k){
    if(tr[o].l>=l&&tr[o].r<=r){
        tr[o].plu=tr[o].plu*k%p; //乘法加法标记都要更新 
        tr[o].tim=tr[o].tim*k%p;
        tr[o].sum=tr[o].sum*k%p;
        return;
    }
    up(o);	//检查更新 
    long long mid=(tr[o].l+tr[o].r)>>1;
    if(l<=mid)time(ls,l,r,k);
    if(mid<r)time(rs,l,r,k);
    tr[o].sum=(tr[ls].sum+tr[rs].sum)%p;
}
void add(long long o,long long l,long long r,long long k){
    if(tr[o].l>=l&&tr[o].r<=r){
        tr[o].plu=(tr[o].plu+k)%p;
        tr[o].sum=(tr[o].sum+k*(tr[o].r-tr[o].l+1))%p;
        return;
    }
    up(o);
    long long mid=(tr[o].l+tr[o].r)>>1;
    if(l<=mid)add(ls,l,r,k);
    if(mid<r)add(rs,l,r,k);
    tr[o].sum=(tr[ls].sum+tr[rs].sum)%p;
}
long long ask(long long o,long long l,long long r){
    if(tr[o].l>=l&&tr[o].r<=r)return tr[o].sum;
    up(o);
    long long ans=0,mid=(tr[o].l+tr[o].r)>>1;
    if(l<=mid)ans=(ans+ask(ls,l,r))%p;
    if(mid<r)ans=(ans+ask(rs,l,r))%p;
    return ans;
}
int main(){
    scanf("%lld%lld",&n,&p);
    for(long long i=1;i<=n;i++)scanf("%lld",&v[i]);
    build(1,1,n);
    scanf("%lld",&m);
    for(long long i=1;i<=m;i++){
        scanf("%lld%lld%lld",&o,&x,&y);
        if(o==1){
            scanf("%lld",&k);
            time(1,x,y,k);
        }
        if(o==2){
            scanf("%lld",&k);
            add(1,x,y,k);
        }
        if(o==3)printf("%lld\n",ask(1,x,y));
    }
}

