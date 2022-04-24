#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int INF=2e9;
int head[maxn],ver[maxn<<1],next1[maxn<<1],mxson[maxn],sz[maxn],d[maxn],cnt,q[maxn],rt,S,ans,tot,n,k,edge[maxn<<1];
bool v[maxn];
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
void getRoot(int x,int f){//求重心
    sz[x]=1;mxson[x]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        getRoot(y,x);
        sz[x]+=sz[y];
        mxson[x]=max(mxson[x],sz[y]);
    }
    mxson[x]=max(mxson[x],S-sz[x]);
    if(mxson[x]<mxson[rt])rt=x;
}
void getQue(int x,int f){//将某重心子树的距离丢进队列中
    q[++cnt]=d[x];
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        d[y]=d[x]+edge[i];
        getQue(y,x);
    }
}
int cal(int x,int cost){
    d[x]=cost;cnt=0;
    getQue(x,0);        //获取离当前点的距离
    sort(q+1,q+1+cnt);
    int l=1,r=cnt,sum=0;
    while(l<r){
        if(q[l]+q[r]<=k){
            sum+=r-l;l++;
        }else r--;
    }
    return sum;
}
void init(int x){
    S=sz[x];
    rt=0;
    getRoot(x,0);
}
void dfz(int x){
    ans+=cal(x,0);
    v[x]=1;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        ans-=cal(y,edge[i]);
        init(y);
        dfz(rt);
    }
}
int main(){
    while(~scanf("%d%d",&n,&k)&&n&&k){
        int a,b,c;
        tot=rt=ans=0;
        for(int i=1;i<=n;++i)v[i]=head[i]=0;
        for(int i=1;i<n;++i){
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);add(b,a,c);
        }
        mxson[0]=INF;S=n;
        getRoot(1,0);
        dfz(rt);
        cout<<ans<<"\n";
    }
}