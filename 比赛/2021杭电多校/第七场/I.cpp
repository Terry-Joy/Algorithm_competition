#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e5+5;
const int mod=1e9+7;
const db eps=1e-8;
struct P{ 
    int x,y;
    P(int _x=0,int _y=0):x(_x),y(_y){ }
    P operator+(P p){ return P(x+p.x,y+p.y);}
    P operator-(P p){ return P(x-p.x,y-p.y);}
    ll len2(){ return (ll)x*x+(ll)y*y;}
    db len(){ return sqrt(len2());}
}a[maxn],b[maxn];
int t;
bool operator==(P a,P b){ 
    return a.x==b.x&&a.y==b.y;
}
int sign(ll x){ 
    return (x<0)?-1:x>0;
}
int sgn(db a){ 
    return a<-eps?-1:a>eps;
}
int dcmp(db a,db b){ 
    return sgn(a-b);
}
ll dot(P a,P b){ 
    return (ll)a.x*b.x+(ll)a.y*b.y;
}
int AngleSign(P a,P b){ 
    return sign(dot(a,b));
}
ll det(P a,P b){ 
    return (ll)a.x*b.y-(ll)a.y*b.x;
}
db PdisSeg(P c,P a,P b){ 
    if(a==b)return (c-a).len();
    P x=c-a,y=c-b,z=b-a;
    if(AngleSign(x,z)<0)return x.len();
    if(AngleSign(y,z)>0)return y.len();
    return fabs(1.0*det(x,z)/z.len());
}
ll mypow(ll a,ll b){ 
    ll ans=1;
    a%=mod;
    while(b){ 
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int PdisSegReal(P c,P a,P b){ 
    if(a==b)return (c-a).len2()%mod;
    P x=c-a,y=c-b,z=b-a;
    if(AngleSign(x,z)<0)return x.len2()%mod;
    if(AngleSign(y,z)>0)return y.len2()%mod;
    return ((det(x,z)%mod)*(det(x,z)%mod))%mod*mypow(z.len2(),mod-2)%mod;
}
int n,m;
int nxt(int x){ 
    return x==m?1:x+1; 
}
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&m);
        for(int i=1;i<=m;++i)scanf("%d%d",&a[i].x,&a[i].y);
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d%d",&b[i].x,&b[i].y);
        db minans=2e18;
        int pos;
        for(int i=1;i<=m;++i){ 
            db now=PdisSeg(b[1],a[i],a[nxt(i)]);
            if(now<minans)
                minans=now,pos=i;
        }
        minans=0;
        ll ans=0;
        for(int i=1;i<=n;++i){ 
            while(1){ 
                db now1=PdisSeg(b[i],a[pos],a[nxt(pos)]);
                db now2=PdisSeg(b[i],a[nxt(pos)],a[nxt(nxt(pos))]);
                if(dcmp(now1,now2)>=0)pos=nxt(pos);
                else break;
            }
            if(dcmp(PdisSeg(b[i],a[pos],a[nxt(pos)]),minans)>0){ 
                minans=PdisSeg(b[i],a[pos],a[nxt(pos)]);
                ans=PdisSegReal(b[i],a[pos],a[nxt(pos)]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
