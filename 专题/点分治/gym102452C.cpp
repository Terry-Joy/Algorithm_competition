#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
const int maxn=2e5+5;
P tmp[maxn];
int head[maxn],ver[maxn<<1],next1[maxn<<1],tot,S,sz[maxn],mxson[maxn],rt,a[maxn],t,cnttmp,n;
bool v[maxn];
ll d[maxn],ans;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct BIT{
    #define lowb(x) (x&(-x))
    ll c[maxn],N;
    void init(int x){
        N=x;
    }
    void add(int x,int val){
        while(x<=N){
            c[x]+=val;
            x+=lowb(x);
        }
    }
    ll ask(int x){
        ll ans=0;
        while(x){
            ans+=c[x];
            x-=lowb(x);
        }
        return ans;
    }
}bit;
void getRoot(int x,int f){
    sz[x]=1;mxson[x]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        getRoot(y,x);
        sz[x]+=sz[y];
        mxson[x]=max(mxson[x],sz[y]);
    }
    mxson[x]=max(mxson[x],S-mxson[x]);
    if(mxson[x]<mxson[rt])rt=x;
}
void getQue(int x,int f,int mx,ll val){
    tmp[++cnttmp]={mx,val};
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        getQue(y,x,max(mx,a[y]),val+a[y]);
    }
}
ll cal(int x,int mx,ll val,int rtval){
    cnttmp=0;
    ll sum=0;
    getQue(x,0,mx,val);
    for(int i=1;i<=cnttmp;++i)d[i]=tmp[i].se;
    sort(d+1,d+1+cnttmp);
    int num=unique(d+1,d+1+cnttmp)-(d+1);
    bit.init(num);
    sort(tmp+1,tmp+1+cnttmp);
    for(int i=1;i<=cnttmp;++i){
        ll dd=-tmp[i].se+2*tmp[i].fi;
        int pos=upper_bound(d+1,d+1+num,dd+rtval)-d;//查的时候得把根的贡献算进去
        if(pos<=num)
            sum+=bit.ask(num)-bit.ask(pos-1);
        int pos2=lower_bound(d+1,d+1+num,tmp[i].se)-d;
        bit.add(pos2,1);
    }
    for(int i=1;i<=cnttmp;++i){
        bit.add(lower_bound(d+1,d+1+num,tmp[i].se)-d,-1);
    }
    return sum;
}
void init(int x){
    mxson[rt=0]=maxn;
    S=sz[x];
    getRoot(x,0);
}
void dfz(int x){
    v[x]=1;
    ans+=cal(x,a[x],a[x],a[x]);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        ans-=cal(y,max(a[x],a[y]),a[x]+a[y],a[x]);
        init(y);
        dfz(rt);
    }
    v[x]=0;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        tot=ans=0;
        for(int i=1;i<=n;++i)head[i]=0;
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        int u,v;
        for(int i=1;i<n;++i){
            scanf("%d%d",&u,&v);
            add(u,v);add(v,u);
        }
        mxson[rt=0]=maxn;
        S=n;       
        getRoot(1,0);
        dfz(rt);
        cout<<ans<<"\n";
    }
    return 0;
}