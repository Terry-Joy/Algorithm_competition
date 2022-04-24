#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define eb emplace_back
using namespace std;
using ll=long long;
const int N=101;
const int maxn=1e5+5;
const int mod=998244353;
int prime[N],v[N],cnt,n,m,mp[102];
vector<int>pr[N];
inline int Add(int x,int y){ 
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
inline int MUL(int x,int y){ 
    return (ll)x*y%mod;
}
void init(){ 
    for(int i=2;i<N;++i){ 
        if(!v[i])prime[++cnt]=i,v[i]=i;
        for(int j=1;j<=cnt&&prime[j]*i<N;++j){ 
            v[i*prime[j]]=prime[j];
            if(i%prime[j]==0)break;
        }
    }
    for(int i=2;i<=100;++i){ 
        int now=i;
        while(now>1){ 
            int x=v[now];
            while(now>1&&now%x==0){ 
                pr[i].eb(v[now]);
                now/=x;
            }
        }
    }
    for(int i=1;i<=cnt;++i){ 
        mp[prime[i]]=i;
    }
}
struct SegmentTree{ 
    int mul[maxn<<2],sum[maxn<<2];
    bool v[26][maxn<<2];
    void build(int p,int l,int r){ 
        if(l==r){ 
            sum[p]=1;return;
        }
        int mid=l+r>>1;
        mul[p]=1;
        build(lson);
        build(rson);
        sum[p]=sum[ls]+sum[rs];
    }
    void pushDown(int p){ 
        sum[ls]=MUL(sum[ls],mul[p]);
        sum[rs]=MUL(sum[rs],mul[p]);
        mul[ls]=MUL(mul[ls],mul[p]);
        mul[rs]=MUL(mul[rs],mul[p]);
        mul[p]=1;
    }
    void pushUp(int p,int o){ 
        sum[p]=Add(sum[ls],sum[rs]);
        v[o][p]=v[o][ls]&v[o][rs];
    }
    void update(int p,int l,int r,int L,int R,int o){ 
        if(L<=l&&r<=R&&v[o][p]){ 
            sum[p]=MUL(sum[p],prime[o]);
            mul[p]=MUL(mul[p],prime[o]);
            return;
        }
        if(l==r){ 
            sum[p]=MUL(sum[p],prime[o]-1);
            v[o][p]=1;
            return;
        }
        if(mul[p]>1)
            pushDown(p);
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,o);
        if(R>mid)update(rson,L,R,o);
        pushUp(p,o);
    }
    int query(int p,int l,int r,int L,int R){ 
        if(L<=l&&r<=R)return sum[p];
        if(mul[p]>1)pushDown(p);
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans%mod;
    }
}tr;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin>>n>>m;
    tr.build(1,1,n);
    int x;
    for(int i=1;i<=n;++i){ 
        cin>>x;
        if(x!=1)
            for(auto u:pr[x]){ 
                tr.update(1,1,n,i,i,mp[u]);
            }
    }
    int op,l,r,w;
    for(int i=1;i<=m;++i){ 
        cin>>op>>l>>r;
        if(!op){ 
            cin>>w;
            if(w!=1)
            for(auto u:pr[w])
                tr.update(1,1,n,l,r,mp[u]);
        }else
            cout<<tr.query(1,1,n,l,r)<<"\n";
    }
    return 0;
}
