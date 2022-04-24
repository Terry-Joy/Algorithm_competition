#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=1e5+5;
int a[maxn],n,m;
struct Node{ 
    int sum,lsum,rsum;
}tr[maxn<<2];
void pushUp(int p,int l,int r,int mid){ 
    bool flag=(a[mid]<a[mid+1])?1:0;
    tr[p].sum=max(tr[ls].sum,tr[rs].sum);
    if(flag)tr[p].sum=max(tr[p].sum,tr[ls].rsum+tr[rs].lsum);
    tr[p].lsum=tr[ls].lsum;
    tr[p].rsum=tr[rs].rsum;
    if(flag&&tr[p].lsum==mid-l+1)tr[p].lsum+=tr[rs].lsum;
    if(flag&&tr[p].rsum==r-mid)tr[p].rsum+=tr[ls].rsum;
}
void build(int p,int l,int r){ 
    if(l==r){ tr[p].sum=tr[p].lsum=tr[p].rsum=1;return;}
    int mid=l+r>>1;
    build(lson);
    build(rson);
    pushUp(p,l,r,mid);
}
void change(int p,int l,int r,int x,int val){ 
    if(l==r){ a[x]=val;return;}
    int mid=l+r>>1;
    if(x<=mid)change(lson,x,val);
    else change(rson,x,val);
    pushUp(p,l,r,mid);
}
int query(int p,int l,int r,int L,int R){ 
    if(L<=l&&r<=R)return tr[p].sum;
    int mid=l+r>>1;
    bool flag=(a[mid]<a[mid+1])?1:0;
    int ans=0;
    if(L<=mid)ans=max(ans,query(lson,L,R));
    if(R>mid)ans=max(ans,query(rson,L,R));
    if(flag)ans=max(ans,min(tr[ls].rsum,mid-L+1)+min(tr[rs].lsum,R-mid));//注意不能超过区间范围
    return ans;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    char s[4];
    while(t--){ 
        cin>>n>>m;
        for(int i=0;i<n;++i)
            cin>>a[i];
        build(1,0,n-1);
        int x,y;
        for(int i=1;i<=m;++i){ 
            cin>>s>>x>>y;
            if(s[0]=='U')change(1,0,n-1,x,y);
            else cout<<query(1,0,n-1,x,y)<<"\n";
        }
    }
    return 0;
}

