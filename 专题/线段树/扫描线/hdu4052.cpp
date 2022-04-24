#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int w,h,n,m;
struct Line{
    int xL,xR,h,flag;
    bool operator<(const Line&a){return h<a.h;}
}line1[maxn<<1],line2[maxn<<1];
int X1[maxn<<1],X2[maxn<<1];
struct SegmentTree{
    int cnt[maxn<<3],len[maxn<<3];
    void build(int p,int l,int r){
        cnt[p]=len[p]=0;
        if(l==r)return;
        int mid=l+r>>1;
        build(lson);
        build(rson);
    }
    void pushUp(int p,int l,int r,bool f){
        if(cnt[p])len[p]=(f?X1[r+1]-X1[l]:X2[r+1]-X2[l]);
        else if(l==r)len[p]=0;
        else len[p]=len[ls]+len[rs];
    }
    void update(int p,int l,int r,int L,int R,int val,bool f){
        if(L<=l&&r<=R){
            cnt[p]+=val;
            return pushUp(p,l,r,f);
        }
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val,f);
        if(R>mid)update(rson,L,R,val,f);
        pushUp(p,l,r,f);
    }
}tr;
int main(){
    int a,b,c,d;
    while(~scanf("%d%d%d%d",&w,&h,&n,&m)){
        for(int i=1;i<=n;++i){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            int k=max(1,a-m+1),e=min(c+(m-1),w),f=max(1,e-(m-1))+1,g=d+1,z=c+1,q=max(min(d+m-1,h)-(m-1),1)+1;
            line1[(i<<1)-1]={k,f,b,1};line1[(i<<1)]={k,f,g,-1};
            line2[(i<<1)-1]={a,z,max(1,b-m+1),1};line2[(i<<1)]={a,z,q,-1};
            X1[(i<<1)-1]=k;X1[(i<<1)]=f;
            X2[(i<<1)-1]=a;X2[(i<<1)]=z;
        }
        if(!n){ 
            ll ans=1ll*h*(w-(m-1));
            ans+=1ll*w*(h-(m-1));
            if(m==1)ans/=2;
            cout<<ans<<"\n";continue;
        }
        sort(X1+1,X1+1+2*n);
        sort(X2+1,X2+1+2*n);
        sort(line1+1,line1+1+2*n);sort(line2+1,line2+1+2*n);
        int cnt1=unique(X1+1,X1+1+2*n)-(X1+2),cnt2=unique(X2+1,X2+1+2*n)-(X2+2);
        ll ans=1ll*h*(w-(m-1));
        ans+=1ll*w*(h-(m-1));
        tr.build(1,1,cnt1);
        if(m==1)ans-=1ll*w*h;
        for(int i=1;i<=2*n;++i){
            ans-=1ll*tr.len[1]*(line1[i].h-line1[i-1].h);
            int l1=lower_bound(X1+1,X1+2+cnt1,line1[i].xL)-X1;
            int r1=lower_bound(X1+1,X1+2+cnt1,line1[i].xR)-(X1+1);
            tr.update(1,1,cnt1,l1,r1,line1[i].flag,1);
        }
        if(m==1){ cout<<ans<<"\n";continue;}
        tr.build(1,1,cnt2);
        for(int i=1;i<=2*n;++i){
            ans-=1ll*tr.len[1]*(line2[i].h-line2[i-1].h);
            int l1=lower_bound(X2+1,X2+2+cnt2,line2[i].xL)-X2;
            int r1=lower_bound(X2+1,X2+2+cnt2,line2[i].xR)-(X2+1);
            tr.update(1,1,cnt2,l1,r1,line2[i].flag,0);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
