#include<bits/stdc++.h>
#define fi first 
#define se second 
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const int maxn=1e5+5;
map<ll,ll>mp;
int n,m,head[maxn],ver[maxn<<1],next1[maxn<<1],edge[maxn<<1],tot,sz[maxn],mxson[maxn],rt,S,cnttmp;
ll ans=0,p[maxn];
P tmp[maxn];
bool v[maxn];
inline int read(){
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
inline void in(int&x){
    x=read();
}
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
void exgcd(ll a,ll b,ll&x,ll&y){
    if(!b){x=1;y=0;return;}
    exgcd(b,a%b,x,y);
    ll z=x;x=y;y=z-y*(a/b);
}
ll inv(ll a){
    ll x,y;
    exgcd(a,m,x,y);
    return (x%m+m)%m;
}
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
void init(int x){
    mxson[rt=0]=maxn;
    S=sz[x];
    getRoot(x,0);
}
void getQue(int x,int f,ll x1,ll x2,int d){
    if(d>=0)++mp[x2],tmp[++cnttmp]={x1,d};
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y]||y==f)continue;
        getQue(y,x,(x1*10+edge[i])%m,(x2+1ll*edge[i]*p[d+1])%m,d+1);
    }
}
ll cal(int x,ll val){
    mp.clear();
    cnttmp=0;
    ll sum=0;
    if(!val)getQue(x,0,0,0,-1);//单个点不算所以不统计(u,u)
    else getQue(x,0,val%m,val%m,0);   
    for(int i=1;i<=cnttmp;++i){
        ll flag=(-tmp[i].fi*inv(p[tmp[i].se+1])%m+m)%m;
        sum+=mp[flag];
        if(!val&&!tmp[i].fi)sum++;//自顶向下的单条链%m==0
    }
    if(!val)sum+=mp[0];//自底向上单条链%m==0
    return sum;
}
void dfz(int x){
    v[x]=1;
    ans+=cal(x,0);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        ans-=cal(y,edge[i]);
        init(y);
        dfz(rt);
    }
    v[x]=0;
}

int main(){
    in(n);in(m);
    int a,b,c;
    for(int i=1;i<n;++i){
        in(a);in(b);in(c);
        a++;b++;
        add(a,b,c);add(b,a,c);
    }
    p[0]=1;
    for(int i=1;i<=n;++i){
        p[i]=p[i-1]*10%m;
    }
    mxson[rt=0]=maxn;
    S=n;
    getRoot(1,0);
    dfz(rt);
    cout<<ans<<"\n";
    return 0;
}