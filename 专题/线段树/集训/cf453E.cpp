#include<bits/stdc++.h>
#define fi first
#define se second
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const int maxn=1e5+10;
const int N=maxn*32;
const int M=1e5;
int n,s[maxn],mi[maxn],ri[maxn],m,rt[maxn];
struct SegmentTree{ 
    int lc[N],rc[N],tot;
    ll sumM[N],sumR[N];
    void pushUp(int p){ 
        sumM[p]=sumM[ls]+sumM[rs];
        sumR[p]=sumR[ls]+sumR[rs];
    }
    void update(int q,int&p,int l,int r,int x,int val,int val2){ 
        p=++tot;
        ls=lc[q];rs=rc[q];sumM[p]=sumM[q];sumR[p]=sumR[q];
        if(l==r){ 
            sumM[p]+=val;sumR[p]+=val2;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lc[q],lson,x,val,val2);
        else update(rc[q],rson,x,val,val2);
        pushUp(p);
    }
    P query(int q,int p,int l,int r,int L,int R){ 
        if(L>R||(L>r||R<l))return { 0,0};
        if(!p)return { 0,0};
        if(L<=l&&r<=R){ 
            return {sumM[p]-sumM[q],sumR[p]-sumR[q]};
        }
        int mid=l+r>>1;
        P x1={ 0,0},x2={ 0,0};
        if(L<=mid)x1=query(lc[q],lson,L,R);
        if(R>mid)x2=query(rc[q],rson,L,R);
        return { x1.fi+x2.fi,x1.se+x2.se};   
    }
}tr;
struct Node{ 
    int l,r,t;
    bool is;
    bool operator<(const Node&x)const{ 
        return l<x.l;
    }
};
ll all(const Node&x,int t){ 
    ll ans=0;
    for(int i=x.l;i<=x.r;++i){ 
        ans+=min((ll)mi[i],s[i]+(ll)(t-x.t)*ri[i]);
        s[i]=0;
    }
    return ans;
}
ll Query(const Node&x,int t){ 
    if(!x.is)return all(x,t);
    t-=x.t;
    return tr.query(rt[x.l-1],rt[x.r],0,M,0,t).fi+(ll)t*tr.query(rt[x.l-1],rt[x.r],0,M,t+1,M).se;
}
set<Node>S;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>s[i]>>mi[i]>>ri[i];
    for(int i=1;i<=n;++i){ 
        if(!ri[i]){ 
            tr.update(rt[i-1],rt[i],0,M,0,0,0);
            continue;
        }
        tr.update(rt[i-1],rt[i],0,M,(mi[i]+ri[i]-1)/ri[i],mi[i],ri[i]);
    }
    S.insert({1,n,0,0});
    cin>>m;
    for(int i=1;i<=m;++i){ 
        int T,l,r;
        cin>>T>>l>>r;
        ll ans=0;
        auto it1=--S.upper_bound({l,0,0,0}),it2=--S.upper_bound({ r,0,0,0});
        if(it1==it2){//同区间 
            ans+=Query({l,r,it1->t,it1->is},T);
            Node x=*it1;
            S.erase(it1);
            if(l!=x.l)S.insert({x.l,l-1,x.t,x.is});
            S.insert({ l,r,T,1});
            if(r!=x.r)S.insert({ r+1,x.r,x.t,x.is});//记得特判一下插入
        }else{ 
            ans+=Query({ l,it1->r,it1->t,it1->is},T);
            Node x1=*it1,x2=*it2;
            for(auto it=S.erase(it1);it!=it2&&it!=S.end();it=S.erase(it)    )
                ans+=Query(*it,T);
            ans+=Query({it2->l,r,it2->t,it2->is},T);
            S.erase(it2);
            if(x1.l<=l-1)S.insert({ x1.l,l-1,x1.t,x1.is});
            if(x2.r>=r+1)S.insert({r+1,x2.r,x2.t,x2.is});
            S.insert({ l,r,T,1});
        }
        cout<<ans<<"\n";
    }
    return 0;
}

