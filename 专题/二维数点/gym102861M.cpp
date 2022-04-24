#include<bits/stdc++.h>
#define pb push_back
#define fi first  
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int maxn=1e5+5;
const int mod=1e9+7;
int n,q,cntx,cnty,X[maxn];
ll Y[maxn];
pair<int,ll> p[maxn];
void add(int&x,int y){
    x+=y;
    if(x>=mod)x-=mod;
}
int mul(int x,int y){
    return 1ll*x*y%mod;
}
struct BIT{
    #define lowb(x) (x&(-x))
    vector<P>c[maxn];
    void Add(int x,int y,int id){
        while(x<=cntx){
            c[x].pb({y,id});
            x+=lowb(x);
        }
    }
    int ask(int x,int y){
        vector<int>q;
        while(x){
            for(auto&v:c[x]){
                if(v.fi<y){
                    q.pb(v.se);
                }else break;
            }
            x-=lowb(x);
        }
        sort(q.begin(),q.end());
        int ans=0,now=1,M=5782344;
        for(auto&v:q){
            add(ans,mul(now,v));
            now=mul(now,M);
        }
        return ans;
    }
}bit;
inline int read(){
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';c=getchar();
    }
    return x;
}
inline void in(int&x){
    x=read();
}
int main(){
    in(n);in(q);
    int x,y;
    for(int i=1;i<=n;++i){
        in(x);in(y);
        ll xx=2ll*y-x;
        ll yy=-1ll*2*y-1ll*x;
        X[++cntx]=xx;Y[++cnty]=yy;
        p[i]={xx,yy};
    }
    sort(X+1,X+1+cntx);
    sort(Y+1,Y+1+cnty);
    cntx=unique(X+1,X+1+cntx)-(X+1);
    cnty=unique(Y+1,Y+1+cnty)-(Y+1);
    for(int i=1;i<=n;++i){
        p[i].fi=lower_bound(X+1,X+1+cntx,p[i].fi)-X;
        p[i].se=lower_bound(Y+1,Y+1+cnty,p[i].se)-Y;
        bit.Add(p[i].fi,p[i].se,i);
    }
    for(int i=1;i<=cntx;++i)
        sort(bit.c[i].begin(),bit.c[i].end());
    int pre=0;
    for(int i=1;i<=q;++i){
        int dd=pre,dw=pre;
        in(x);in(y);
        add(dd,x);add(dw,y);
        x=-1-dd;
        y=dw;
        ll xx=2ll*y-1ll*x;
        ll yy=-1ll*x-2ll*y;
        int L=upper_bound(X+1,X+1+cntx,xx)-X;
        int R=upper_bound(Y+1,Y+1+cnty,yy)-Y;
        cout<<(pre=bit.ask(L-1,R))<<"\n";
    }
    return 0;
}