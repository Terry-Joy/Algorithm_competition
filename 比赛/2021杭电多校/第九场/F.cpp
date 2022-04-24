#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll>P;
const int M=2e5;
const int maxn=2e5+5;
int x,cnt[maxn];
struct SegmentTree{ 
    int sum[maxn<<2];
    ll sum2[maxn<<2];
    void pushUp(int p){ 
        sum[p]=sum[ls]+sum[rs];
        sum2[p]=sum2[ls]+sum2[rs]+(ll)sum[ls]*sum[rs];
    }
    void build(int p,int l,int r){ 
        if(l==r){ 
            sum[p]=cnt[l];
            sum2[p]=(ll)cnt[l]*(cnt[l]-1);
            return;
        }
        int mid=l+r>>1;
        build(lson);
        build(rson);
        pushUp(p);
    }
    void update(int p,int l,int r,int x,int val){ 
        if(l==r){ 
            sum2[p]+=(ll)val*(val-1);
            sum2[p]+=2ll*val*sum[p];
            sum[p]+=val;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int queryS(int p,int l,int r,int L,int R){ 
        if(l>R||r<L)return 0;
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=queryS(lson,L,R);
        if(R>mid)ans+=queryS(rson,L,R);
        return ans;
    }
    int query_mid(int p,int l,int r,int x){ 
        if(l==r)return l;
        int mid=l+r>>1;
        if(sum[ls]>=x)return query_mid(lson,x);
        else return query_mid(rson,x-sum[ls]);
    }
    P query_ans(int p,int l,int r,int L,int R){ 
        if(l>R||r<L)return P(0,0);
        if(L<=l&&r<=R)return P(sum2[p],sum[p]);
        int mid=l+r>>1;
        P x1={ 0,0},x2={ 0,0};
        if(L<=mid)x1=query_ans(lson,L,R);
        if(R>mid)x2=query_ans(rson,L,R);
        return make_pair(x1.fi+x2.fi+(ll)x1.se*x2.se,x1.se+x2.se);
    }
}tr;
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){ 
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=M;++i)cnt[i]=0;
        for(int i=1;i<=n;++i){ 
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }
        tr.build(1,1,M);
        int s=n;
        for(int i=1;i<=q;++i){ 
            int op,x,y;
            scanf("%d",&op);
            if(op==1){ 
                scanf("%d%d",&x,&y);
                tr.update(1,1,M,y,x);
                s+=x;
            }else{ 
                int pmid=tr.query_mid(1,1,M,s/2);
                int sum=tr.queryS(1,1,M,1,pmid-1),sum2=tr.queryS(1,1,M,pmid+1,M);
                if(sum>=sum2)pmid--;//pmid喊小
                P x1=tr.query_ans(1,1,M,1,pmid),x2=tr.query_ans(1,1,M,pmid+1,M);
                ll inv=1ll*s*(s-1);
                ll num=inv;
                inv-=x1.fi;inv-=x2.fi;
                ll g=__gcd(num,inv);
                num/=g;inv/=g;
                printf("%lld/%lld\n",inv,num);
            }
        }
    }
    return 0;
}

