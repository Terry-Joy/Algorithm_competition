#include<bits/stdc++.h>
#define N maxn*36
#define ls lc[p]
#define rs rc[p]
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
inline int read(){
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}
    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}
    return x*s;
}
inline void in(int&x){
    x=read();
}
int n,val;
ll ans1,ans2,ans;
struct SegmentTree{
    int tot,lc[N],rc[N],sum[N];
    void pushUp(int p){
        sum[p]=sum[ls]+sum[rs];
    }
    int update(int l,int r,int x){
        int pos=++tot;
        sum[pos]++;
        if(l==r)return pos;
        int mid=l+r>>1;
        if(x<=mid)
            lc[pos]=update(l,mid,x);
        else rc[pos]=update(mid+1,r,x);
        return pos;
    }
    int merge(int p,int q,int l,int r){
        if(!p||!q)return p+q;
        if(l==r){sum[p]+=sum[q];return p;}
        ans1+=1ll*sum[rs]*sum[lc[q]];
        ans2+=1ll*sum[ls]*sum[rc[q]];
        int mid=l+r>>1;
        ls=merge(ls,lc[q],l,mid);
        rs=merge(rs,rc[q],mid+1,r);
        pushUp(p);
        return p;
    }
}tr;
int dfs(){
    int rt;in(val);
    if(!val){
        int lc=dfs(),rc=dfs();
        ans1=0;ans2=0;
        rt=tr.merge(lc,rc,1,n);
        ans+=min(ans1,ans2);
    }else
        rt=tr.update(1,n,val);
    return rt;
}
int main(){
    in(n);
    dfs();
    cout<<ans<<"\n";
    return 0;
}