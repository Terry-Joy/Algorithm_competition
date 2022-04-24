#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int sz[maxn],mxson[maxn],S,d[maxn],tot,head[maxn],ver[maxn<<1],next1[maxn<<1],edge[maxn<<1],rt,cnt[3],tmp[3],ans=0,n;
bool v[maxn];
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
void add(int x,int y,int z){
    ver[++tot]=y,next1[tot]=head[x],edge[tot]=z,head[x]=tot;
}
void init(int x){
    S=sz[x];
    mxson[rt=0]=maxn;
    getRoot(x,0);
}
void getQue(int x,int f){
    tmp[d[x]%3]++;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y]||y==f)continue;
        d[y]=d[x]+edge[i];
        getQue(y,x);
    }
}
void cal(int x){
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        d[y]=edge[i];
        memset(tmp,0,sizeof(tmp));
        getQue(y,x);
        for(int j=1;j<3;++j){
            ans+=2*cnt[j]*tmp[3-j];//两个点互换
        }
        ans+=2*cnt[0]*tmp[0];//这里没有自己和自己的
        for(int i=0;i<3;++i)cnt[i]+=tmp[i];
    }
    memset(cnt,0,sizeof(cnt));
}
void dfz(int x){
    v[x]=1;
    cnt[0]++;
    cal(x);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        init(y);
        dfz(rt);
    }
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int a,b,c;
    for(int i=1;i<n;++i){
        cin>>a>>b>>c;
        add(a,b,c);add(b,a,c);
    }
    S=n;
    mxson[rt=0]=maxn;
    getRoot(1,0);
    dfz(rt);
    ans+=n;//加上自己和自己的
    int g=gcd(ans,n*n);
    n=n*n;
    n/=g;ans/=g;
    cout<<ans<<"/"<<n<<"\n";
    return 0;
}