#include<bits/stdc++.h>
#define fi first  
#define se second
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int M=1e6+5;
int n,k,head[maxn],ver[maxn<<1],next1[maxn<<1],edge[maxn<<1],tot,sz[maxn],mxson[maxn],rt,S,d[maxn],judge[M],cnttmp,a,b,c,ans=maxn;
pair<int,int>tmp[maxn];
int val[maxn];
bool v[maxn];
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
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
    S=sz[x];
    mxson[rt=0]=maxn;
    getRoot(x,0);
}
void getQue(int x,int f,int dd){
    if(d[x]>k)return;
    tmp[++cnttmp]={d[x],dd};
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y]||y==f)continue;
        d[y]=d[x]+edge[i];
        getQue(y,x,dd+1);
    }
}
void cal(int x){
    int num=0;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        d[y]=edge[i];
        cnttmp=0;
        getQue(y,x,1);
        for(int j=cnttmp;j;--j)
            if(judge[k-tmp[j].fi]!=maxn)
                ans=min(ans,judge[k-tmp[j].fi]+tmp[j].se);
        for(int j=cnttmp;j;--j)
                val[++num]=tmp[j].fi,judge[tmp[j].fi]=min(judge[tmp[j].fi],tmp[j].se);
    }
    for(int i=num;i;--i)
        judge[val[i]]=maxn;
}
void dfz(int x){
    v[x]=1;judge[0]=0;
    cal(x);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        init(y);
        dfz(rt);//点分治一定是跳根!!
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;++i){
        cin>>a>>b>>c;
        a++;b++;
        add(a,b,c);add(b,a,c);
    }   
    S=n;
    mxson[rt=0]=maxn;
    for(int i=1;i<M;++i)judge[i]=maxn;
    getRoot(1,0);
    dfz(rt);
    if(ans==maxn)cout<<"-1"<<"\n";
    else cout<<ans<<"\n";
    return 0;
}