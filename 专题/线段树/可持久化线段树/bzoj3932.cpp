#include<bits/stdc++.h>
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define pb push_back
#define N maxn*72
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,m,si[maxn],ei[maxn],pi[maxn],b[maxn],cnt,rt[maxn];
vector<int>a[maxn];
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}//是符号
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}//是数字
    return x*s;
}
inline void in(int&x){
    x=read();
}
struct Persistable_SegmentTree{
    int tot,lc[N],rc[N],num[N];
    ll sum[N];
    void update(int q,int&p,int l,int r,int x,int val){
        p=++tot;
        ls=lc[q];rs=rc[q];sum[p]=sum[q]+b[x]*val;num[p]=num[q]+val;
        if(l==r)return;
        int mid=l+r>>1;
        if(x<=mid)update(lc[q],lson,x,val);
        else update(rc[q],rson,x,val);
    }
    ll query(int p,int l,int r,int k){
        if(l==r)return 1ll*k*b[l];
		if(num[p]==k)return sum[p];
        int mid=l+r>>1;
        if(num[ls]>=k)return query(lson,k);
        else return sum[ls]+query(rson,k-num[ls]);
    }
}tr;
int main(){
    in(m);in(n);
    for(int i=1;i<=m;++i){
        in(si[i]);in(ei[i]);in(pi[i]);b[i]=pi[i];
    }
    sort(b+1,b+1+m);
    cnt=unique(b+1,b+1+m)-(b+1);
    for(int i=1;i<=m;++i)
        pi[i]=lower_bound(b+1,b+1+cnt,pi[i])-b;
    for(int i=1;i<=m;++i){
        a[si[i]].pb(pi[i]);a[ei[i]+1].pb(-pi[i]);
    }
    int now=0;
    for(int i=1;i<=n;++i){
    	rt[i]=rt[i-1];
        for(auto&v:a[i]){
        	tr.update(rt[i],rt[i],1,cnt,abs(v),v>0?1:-1);
        }
    }
    int x,ai,bi,ci;
    ll pre=1;
    for(int i=1;i<=n;++i){
        in(x);in(ai);in(bi);in(ci);
        int ki=1+(pre*ai+bi)%ci;
        if(tr.num[rt[x]]<ki)pre=tr.sum[rt[x]];
        else pre=tr.query(rt[x],1,cnt,ki);
        cout<<pre<<"\n";
    }
    return 0;
}