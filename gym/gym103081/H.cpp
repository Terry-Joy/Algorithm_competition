#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=1e5+10;
const int N=maxn*60;
int d[maxn],n,c,tot,sum[N],rt[maxn],lc[N],rc[N];
char a,b;
void pushUp(int p){ 
    sum[p]=sum[ls]+sum[rs];
}
int query(int p,int l,int r,int L,int R){ 
    if(!p)return 0;
    if(L>R)return 0;
    if(L<=l&&r<=R)return sum[p];
    int mid=l+r>>1,ans=0;
    if(L<=mid)ans+=query(lson,L,R);
    if(R>mid)ans+=query(rson,L,R);
    return ans;
}
void update(int&p,int q,int l,int r,int x,int val){ 
    p=++tot;
    lc[p]=lc[q];sum[p]=sum[q];
    rc[p]=rc[q];
    if(l==r){ 
        sum[p]+=val;return;
    }
    int mid=l+r>>1;
    if(x<=mid)update(lc[p],lc[q],l,mid,x,val);
    else update(rc[p],rc[q],mid+1,r,x,val);
    pushUp(p);
}
int main(){ 
    scanf("%d%*c",&n);
    for(int i=1;i<=n;++i){ 
        rt[i]=rt[i-1];
        do{ 
            scanf("%c",&a);
            if(a=='\n')break;
            scanf("%d%c",&c,&b);
            update(rt[i],rt[i],0,n-1,c,(a=='+')?1:-1);
        }while(b==' ');
    }
    int x,ans=0;
    for(int i=0;i<n;++i){ 
        scanf("%d",&x);
        ans=(ans+query(rt[x],0,n-1,ans,n-1))%n;
    }
    cout<<ans;
    return 0;
}
