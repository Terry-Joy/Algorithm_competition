#include<bits/stdc++.h>
using namespace std;
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r 
#define ls p<<1 
#define rs p<<1|1 
typedef long long ll;
const int maxn=2e5+5;
struct Node{
    int mx,mn,res;
}tr[maxn<<2];
int n,q,cnt,a[maxn],b[maxn],k,pos[maxn];
bool is[maxn],op[maxn];
void pushUp(int p){
    tr[p].mx=max(tr[ls].mx,tr[rs].mx);
    if(tr[ls].mn==0||tr[rs].mn==0)tr[p].mn=max(tr[ls].mn,tr[rs].mn);//特判最小值是否存在
    else tr[p].mn=min(tr[ls].mn,tr[rs].mn);
    if(tr[ls].mx==0||tr[rs].mn==0)tr[p].res=max(tr[ls].res,tr[rs].res);//维护相邻差值的最大值的时候要注意相应是否存在
    else tr[p].res=max(max(tr[ls].res,tr[rs].res),tr[rs].mn-tr[ls].mx);
}
void build(int p,int l,int r){
    if(l==r){
        if(is[l])tr[p]={a[l],a[l],0};
        else tr[p]={0,0,0};//标记没出现
        return;
    }
    int mid=l+r>>1;
    build(lson);
    build(rson);
    pushUp(p);
}
void change(int p,int l,int r,int x,int val){
    if(l==r){
        if(val)tr[p]={a[l],a[l],0};
        else tr[p]={0,0,0};
        return; 
    }
    int mid=l+r>>1;
    if(x<=mid)change(lson,x,val);
    else change(rson,x,val);
    pushUp(p);
}
int query(){
    return tr[1].mx-tr[1].mn-tr[1].res;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=a[i];
    cnt=n;
    for(int i=1;i<=q;++i){
        scanf("%d%d",&op[i],&pos[i]);
        a[++cnt]=pos[i];   
    }
    sort(b+1,b+1+n);
    sort(a+1,a+1+cnt);
    int m=unique(a+1,a+1+cnt)-(a+1);
    for(int i=1;i<=q;++i)
        pos[i]=lower_bound(a+1,a+1+m,pos[i])-a;
    k=1;
    for(int i=1;i<=n;++i){
        while(b[i]!=a[k])k++;
        is[k]=1;
    }
    build(1,1,m);
    printf("%d\n",query());
    for(int i=1;i<=q;++i){
        change(1,1,m,pos[i],op[i]);
        printf("%d\n",query());
    }
    return 0;
}
