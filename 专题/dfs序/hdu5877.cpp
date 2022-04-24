//4次LL,a,b,ans,k,ask里面的ll,deg初始化,scanf的ll
#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll INF=2e18;
int t,ver[maxn<<1],head[maxn],next1[maxn<<1],tot,n,m,deg[maxn];
ll a[maxn<<1],b[maxn<<1],ans=0,k;
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
int ask(ll x){
    return lower_bound(b+1,b+1+m,x)-b;
}
struct BIT{
    int c[maxn<<1],N;
    void init(int x){
        this->N=x;
        for(int i=0;i<=x;++i)c[i]=0;
    }
    int query(int x){
        int ans=0;
        while(x){
            ans+=c[x];
            x-=lowbit(x);
        }
        return ans;
    }
    void add(int x,int val){
        while(x<=N){
            c[x]+=val;
            x+=lowbit(x);
        }
    }
}bit;
void dfs(int x,int fa){
    int pos=(a[x]?ask(k/a[x]):m),pos2=ask(a[x]);
    ans+=bit.query(pos);
    bit.add(pos2,1);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa)continue;
        dfs(y,x);
    }
    bit.add(pos2,-1);
}
int main(){
    scanf("%d",&t);
    while(t--){
        ans=0;
        tot=0;
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;++i)head[i]=0,deg[i]=0;
        for(int i=1;i<=n;++i){
            scanf("%lld",&a[i]);
            if(!a[i])a[i+n]=INF;
            else a[i+n]=k/a[i];
            b[i]=a[i];
            b[i+n]=a[i+n];
        }
        for(int i=1;i<n;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
            deg[y]++;
        }
        int rt=0;
        for(int i=1;i<=n;++i){
            if(!deg[i]){rt=i;break;}
        }
        sort(b+1,b+1+2*n);
        m=unique(b+1,b+1+2*n)-(b+1);
        bit.init(m);
        dfs(rt,0);
        cout<<ans<<'\n';
    }
    return 0;
}