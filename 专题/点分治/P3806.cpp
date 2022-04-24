#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int M=1e7+5;
int head[maxn],ver[maxn<<1],next1[maxn<<1],edge[maxn<<1],tot,tmp[maxn],cnttmp,sz[maxn],mxson[maxn],S,rt,val[maxn],Q[105],m,d[maxn];
int n,a,b,c;
bool judge[M],v[maxn],ans[105];
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
void getRoot(int x,int f){
    sz[x]=1;mxson[x]=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y]||y==f)continue;
        getRoot(y,x);
        sz[x]+=sz[y];
        mxson[x]=max(mxson[x],sz[y]);
    }
    mxson[x]=max(mxson[x],S-mxson[x]);
    if(mxson[x]<mxson[rt])rt=x;
}
void init(int x){
    S=sz[x];
    mxson[rt=0]=M;
    getRoot(x,0);
}
void getQue(int x,int f){
    tmp[++cnttmp]=d[x];
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y]||y==f)continue;
        d[y]=d[x]+edge[i];
        getQue(y,x);
    }
}
void cal(int x){
    int num=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        d[y]=edge[i];
        cnttmp=0;
        getQue(y,x);
        for(int j=cnttmp;j;--j)
            for(int k=1;k<=m;++k)
                if(Q[k]>=tmp[j])ans[k]|=judge[Q[k]-tmp[j]];
        for(int j=cnttmp;j;--j)
            if(tmp[j]<M)//防止越界 边权和最多1e8
                val[++num]=tmp[j],judge[tmp[j]]=1;
    }
    for(int i=num;i;--i)
        judge[val[i]]=0;
}
void dfz(int x){
    v[x]=judge[0]=1;
    cal(x);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        init(y);
        dfz(rt);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<n;++i){
        cin>>a>>b>>c;
        add(a,b,c);add(b,a,c);
    }
    for(int i=1;i<=m;++i)cin>>Q[i];
    S=n;
    rt=0;
    mxson[0]=M;
    getRoot(1,0);
    dfz(rt);
    for(int i=1;i<=m;++i){
        cout<<((ans[i])?"AYE":"NAY")<<"\n";
    }
    return 0;
}