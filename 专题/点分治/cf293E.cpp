#include<bits/stdc++.h>
#define fi first 
#define se second 
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const int maxn=1e5+5;
bool v[maxn];
int sz[maxn],mxson[maxn],rt,S,edge[maxn<<1],ver[maxn<<1],tot,head[maxn],next1[maxn<<1],n,l,w,cnt;
int mxL,cnttmp;
P tmp[maxn];
ll ans=0;
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
struct BIT{
    #define lowb(x) (x&(-x))
    int c[maxn];
    void add(int x,int val){
        x++;
        for(int i=x;i<=n+1;i+=lowb(i))c[i]+=val;
    }
    int ask(int x){
        x++;
        int ans=0;
        for(int i=x;i;i-=lowb(i))ans+=c[i];
        return ans;
    } 
}bit;
void getRoot(int x,int f){
    sz[x]=1;mxson[x]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y]||y==f)continue;
        getRoot(y,x);
        sz[x]+=sz[y];
        mxson[x]=max(mxson[x],sz[y]);
    }
    mxson[x]=max(mxson[x],S-sz[x]);
    if(mxson[x]<mxson[rt])rt=x;
}
void init(int x){
    mxson[rt=0]=maxn;
    S=sz[x];
    getRoot(x,0);
}
void getQue(int x,int f,ll val,int d){
    tmp[++cnttmp]={val,d};
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y]||y==f)continue;
        getQue(y,x,val+edge[i],d+1);
    }
}
ll cal(int x,ll val,int d){
    ll sum=0;
    cnttmp=0;
    getQue(x,0,val,d);
    sort(tmp+1,tmp+1+cnttmp);
    int h=1,t=cnttmp;
    while(h<t&&tmp[h].fi+tmp[t].fi>w){
        t--;
    }
    if(h<t){
        for(int i=h+1;i<=t;++i)bit.add(tmp[i].se,1);
        while(h<t){
            if(tmp[h].fi+tmp[t].fi<=w){
                if(l-tmp[h].se>=0)
                    sum+=bit.ask(l-tmp[h].se);
                h++;
                bit.add(tmp[h].se,-1);
            }else{
                bit.add(tmp[t].se,-1);
                t--;
            }
        }
    }
    return sum;
}
void dfz(int x){
    v[x]=1;
    ans+=cal(x,0,0);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        ans-=cal(y,edge[i],1);
        init(y);
        dfz(rt);
    }
}
int main(){
    scanf("%d%d%d",&n,&l,&w);
    int a,b;
    for(int i=2;i<=n;++i){
        scanf("%d%d",&a,&b);
        add(i,a,b);add(a,i,b);
    }
    S=n;
    mxson[rt=0]=maxn;
    getRoot(1,0);
    dfz(rt);
    cout<<ans<<"\n";
    return 0;
}