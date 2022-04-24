#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const db Pi=acos(-1.0);
const int maxn=1e5+5;
const int mod=1e9+7;
int head[maxn],ver[maxn<<1],next1[maxn<<1],tot,sz[maxn],mxson[maxn],S,rt,n,tmp[maxn],cnttmp;
ll a[maxn*2],cnt[maxn*2];
bool v[maxn];
void add(int x,int y){
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
struct FFT{
    struct CP{
        CP(db xx=0,db yy=0){x=xx,y=yy;}
        db x,y;
        CP operator+(CP const&B)const{return CP(x+B.x,y+B.y);}
        CP operator-(CP const&B)const{return CP(x-B.x,y-B.y);}
        CP operator*(CP const&B)const{return CP(x*B.x-y*B.y,x*B.y+y*B.x);}
    }f[maxn*4];
    int n,m,tr[maxn*4];
    void fft(CP*f,bool flag){
        for(int i=0;i<n;++i)
            if(i<tr[i])swap(f[i],f[tr[i]]);
        for(int p=2;p<=n;p<<=1){
            int len=p>>1;
            CP tG(cos(2*Pi/p),sin(2*Pi/p));
            if(!flag)tG.y*=-1;
            for(int k=0;k<n;k+=p){
                CP buf(1,0);
                for(int l=k;l<k+len;l++){
                    CP tt=buf*f[len+l];
                    f[len+l]=f[l]-tt;
                    f[l]=f[l]+tt;
                    buf=buf*tG;
                }
            }
        }
    }
    void init(int nn,int mm,ll aa[]){
        n=nn;m=mm;
        int len;
    	for(len=1;len<=n+m;len<<=1);
    	for(int i=0;i<len;++i)f[i]={0,0};
        for(int i=0;i<=n;++i)f[i]={aa[i],0};
        for(m+=n,n=1;n<=m;n<<=1);
        for(int i=0;i<n;++i)
            tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
       
    }
    void work(ll c[]){
        fft(f,1);
        for(int i=0;i<n;++i)f[i]=f[i]*f[i];
        fft(f,0);   
        for(int i=0;i<=m;++i)c[i]=(ll)((f[i].x)/n+0.5);
    }
}fft;
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
    mxson[rt=0]=maxn;
    S=sz[x];
    getRoot(x,0);
}
void getQue(int x,int f,int d){
    tmp[++cnttmp]=d;   
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f||v[y])continue;
        getQue(y,x,d+1);
    }
}
void cal(int x,int flag,int d){
    cnttmp=0;
    getQue(x,0,d);
    int mx=*max_element(tmp+1,tmp+1+cnttmp);
    for(int i=0;i<=mx;++i)a[i]=0;
    for(int i=1;i<=cnttmp;++i)a[tmp[i]]++;
    fft.init(mx,mx,a);
    fft.work(a);
    for(int i=0;i<=min(n,2*mx);++i)cnt[i]+=flag*a[i];
}
void dfz(int x){
    v[x]=1;
    cal(x,1,0);
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(v[y])continue;
        cal(y,-1,1);
        init(y);
        dfz(rt);
    }
    v[x]=0;
}
ll mypow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    mxson[rt=0]=maxn;
    S=n;
    getRoot(1,0);
    dfz(rt);
    ll ans=0;
    for(int i=0;i<n;++i){
        ans=(ans+cnt[i]%mod*mypow(i+1,mod-2))%mod;
    }
    for(int i=1;i<=n;++i)ans=ans*i%mod;
    cout<<ans<<"\n";
    return 0;
}