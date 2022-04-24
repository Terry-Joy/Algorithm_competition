#include<bits/stdc++.h>
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r 
#define ls lc[p]
#define rs rc[p]
using namespace std;
#define N maxn*50
const int maxn=5e5+5;
int r,c,m,x,rt[maxn],cnt1,cnt2,rp,lp,insrp,inslp;
int xL,yL,xR,yR,H,num[205][205][1003],sum[205][205][1003],a[205][205];
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
    int tot,lc[N],rc[N],sum[N],num[N];
    void update(int q,int&p,int l,int r,int x,int val){
        p=++tot;
        lc[p]=lc[q];rc[p]=rc[q];sum[p]=sum[q]+val;num[p]=num[q]+1;
        if(l==r)return;
        int mid=l+r>>1;
        if(x<=mid)update(lc[q],lson,x,val);
        else update(rc[q],rson,x,val);
    }
    int query(int l,int r,int k){
        if(l==r){
            return k*l;
        }
        int tmp=num[rc[rp]]-num[rc[lp]];
        int mid=l+r>>1;
        if(tmp>=k){
            rp=rc[rp];
            lp=rc[lp];
            return query(mid+1,r,k);
        }
        else{
            int ans=0;
            ans+=sum[rc[rp]];
            ans-=sum[rc[lp]];
            lp=lc[lp];
            rp=lc[rp];
            return query(l,mid,k-tmp)+ans;
        }
    }
}tr;
bool check(int x){
    return tr.query(1,1000,x)>=H;
}
int getV(int a1,int b1,int a2,int b2,int k){
    return sum[a2][b2][k]-sum[a1-1][b2][k]-sum[a2][b1-1][k]+sum[a1-1][b1-1][k];
}
int getN(int a1,int b1,int a2,int b2,int k){
    return num[a2][b2][k]-num[a1-1][b2][k]-num[a2][b1-1][k]+num[a1-1][b1-1][k];
}
void solve(){
    int mx=0;
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j){
            in(a[i][j]);
            mx=max(mx,a[i][j]);
        }
    for(int k=0;k<=mx;++k)
        for(int i=1;i<=r;++i)
            for(int j=1;j<=c;++j){
                sum[i][j][k]=sum[i-1][j][k]+sum[i][j-1][k]-sum[i-1][j-1][k]+(a[i][j]>=k?a[i][j]:0);
                num[i][j][k]=num[i-1][j][k]+num[i][j-1][k]-num[i-1][j-1][k]+(a[i][j]>=k?1:0);
            }
    for(int i=1;i<=m;++i){
        in(xL);in(yL);in(xR);in(yR);in(H); 
        if(getV(xL,yL,xR,yR,0)<H){
            puts("Poor QLW");continue;
        }
        int l=-1,r=mx,ans=-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(getV(xL,yL,xR,yR,mid)>=H)l=mid;
            else r=mid-1;
        }
        cout<<getN(xL,yL,xR,yR,l)-(getV(xL,yL,xR,yR,l)-H)/l<<"\n";
    }
}
int main(){
    in(r);in(c);in(m);
    if(r==1){
        for(int i=1;i<=c;++i){
            in(x);
            tr.update(rt[i-1],rt[i],1,1000,x,x);
        }
        for(int i=1;i<=m;++i){
            in(xL);in(yL);in(xR);in(yR);in(H); 
            int mxans=0;
            mxans+=tr.sum[rt[yR]];mxans-=tr.sum[rt[yL-1]];
            if(mxans>=H){
            	int l=1,r=c+1;
                lp=rt[yL-1];rp=rt[yR];
                inslp=lp;insrp=rp;
                while(l<r){
                    int mid=l+r>>1;
                    if(check(mid)){
                        r=mid;
                    }else l=mid+1;
                    lp=inslp;rp=insrp;
                }
                cout<<r<<"\n";
            }else
                puts("Poor QLW");
        }
    }else{
        solve();
    }
    return 0;
}
