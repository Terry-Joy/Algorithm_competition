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
void cal(int x){
    d[0]=1;num=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        cnttmp=0;
        getQue(y,x,(1<<a[y]));//这样计算路径至少2个点 但是还要算单独的
        for(int j=1;j<=cnttmp;++j){
        	ans+=d[(1<<k)-1];
            int s0=tmp[j]|(1<<a[x]);
            for(int s=s0;s;s=(s-1)&s0){//不会枚举到空集
                ans+=d[((1<<k)-1)^s];
            }
        }
        for(int j=1;j<=cnttmp;++j){
            d[tmp[j]]++;all[++num]=tmp[j];
        }
    }
    for(int i=1;i<=num;++i)d[all[i]]=0;
    d[0]=0;

}
void dfz(int x){
    v[x]=1;
    cal(x);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
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
            cout<<n*n<<"\n";continue;
        }
        mxson[rt=0]=maxn;
        S=n;
        getRoot(1,0);
        dfz(rt);
        ans*=2;
        cout<<ans<<"\n";
    }
    return 0;
}