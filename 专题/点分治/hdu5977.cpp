#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+5;
int n,k,a[maxn],rt,S,mxson[maxn],sz[maxn],head[maxn],ver[maxn<<1],next1[maxn<<1],tot,cnttmp,tmp[maxn],d[1030],num,all[maxn];
ll ans=0;
bool v[maxn];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
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
void getQue(int x,int f,int val){
    tmp[++cnttmp]=val;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y]||y==f)continue;
        getQue(y,x,val|(1<<a[y]));
    }
}
ll cal(int x,int val){
    ll sum=0;
    cnttmp=0;
    getQue(x,0,val);
    for(int i=1;i<=cnttmp;++i)d[tmp[i]]++;
    for(int i=1;i<=cnttmp;++i){
        d[tmp[i]]--;
        for(int s=tmp[i];s;s=(s-1)&tmp[i]){//包含根的路径满足的话，不包含也满足，因为当前包含
            sum+=d[((1<<k)-1)^s];//枚举不到空集所以要加
        }
        sum+=d[(1<<k)-1];//这样计算要特判k=1，因为d中没有存储所有单点贡献的情况
        d[tmp[i]]++;
    }
    for(int i=1;i<=cnttmp;++i)d[tmp[i]]--;
    return sum;
}
void dfz(int x){
    v[x]=1;
    ans+=cal(x,(1<<a[x]));
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        ans-=cal(y,(1<<a[x])|(1<<a[y]));
        init(y);
        dfz(rt);
    }
    v[x]=0;
}
int main(){
    while(~scanf("%d%d",&n,&k)){
        tot=ans=0;
        for(int i=1;i<=n;++i)head[i]=0;
        for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]--;
        int u,v;
        for(int i=1;i<n;++i){
            scanf("%d%d",&u,&v);
            add(u,v);add(v,u);
        }
        if(k==1){
            cout<<n*n<<"\n";
            continue;
        }
        mxson[rt=0]=maxn;
        S=n;
        getRoot(1,0);
        dfz(rt);
        cout<<ans<<"\n";
    }
    return 0;
}