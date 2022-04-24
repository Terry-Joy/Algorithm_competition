#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn=2e5+5;
typedef long long ll;
typedef double db;
int t,n,q;
char s1[maxn],s2[maxn];
struct SegmentTree{ 
    int num[maxn<<2],add[maxn<<2];
    void pushUp(int p){ 
        num[p]=num[ls]+num[rs];
    }
    void build(int p,int l,int r){ 
        add[p]=-1;
        if(l==r){ 
            num[p]=(s2[l]=='1');
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    int query(int p,int l,int r,int L,int R){ 
        if(L<=l&&r<=R)return num[p];
        pushDown(p,l,r);
        int mid=l+r>>1,ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
    void pushDown(int p,int l,int r){ 
        if(add[p]==-1)return;
        int mid=l+r>>1;
        num[ls]=(mid-l+1)*add[p];
        num[rs]=(r-mid)*add[p];
        add[ls]=add[rs]=add[p];
        add[p]=-1;
    }
    void update(int p,int l,int r,int L,int R,int val){ 
        if(L<=l&&r<=R){ 
            num[p]=(r-l+1)*val;
            add[p]=val;
            return;
        }
        int mid=l+r>>1;
        pushDown(p,l,r);
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p);
    }
}tr;
int L[maxn],R[maxn],sum[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>t;
    while(t--){ 
        cin>>n>>q;
        cin>>(s1+1)>>(s2+1);
        for(int i=1;i<=n;++i)sum[i]=sum[i-1]+(s1[i]=='1');
        for(int i=1;i<=q;++i)cin>>L[i]>>R[i];
        tr.build(1,1,n);
        bool is=1;
        for(int i=q;i>=1;--i){ 
            int cnt1=tr.query(1,1,n,L[i],R[i]),cnt2=R[i]-L[i]+1-cnt1;
            if(cnt1==cnt2){ 
                is=0;break;
            }
            tr.update(1,1,n,L[i],R[i],cnt1>cnt2);
        }
        if(!is){ cout<<"NO"<<"\n";continue;}
        for(int i=1;i<=n;++i){ 
            if(sum[i]!=tr.query(1,1,n,1,i)){ 
                is=0;break;
            }
        }
        cout<<(is?"YES":"NO")<<"\n";
    }
    return 0;
}
