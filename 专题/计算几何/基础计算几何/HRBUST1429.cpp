#include<bits/stdc++.h>
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))
using namespace std;
typedef double db;
const db eps=1e-8;
const int maxn=1e5+5;

int sign(db a){ return a<-eps?-1:a>eps;}
int dcmp(db a,db b){ return sign(a-b);}
int n,m;
struct P{ 
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
    P operator+(P p){ return P(x+p.x,y+p.y);}
    P operator-(P p){ return P(x-p.x,y-p.y);}
}p[maxn],b[maxn];
db det(P a,P b){ 
    return a.x*b.y-a.y*b.x;
}
db dot(P a,P b){ 
    return a.x*b.x+a.y*b.y;
}
bool onSeg(P c,P a,P b){ 
    return sign(det(c-a,b-a))==0&&sign(dot(c-a,c-b))<=0;
}
int TuContain(P a){ 
    if(cha(p[1],a,p[2])<0||cha(p[1],p[n],a)<0)return 0;
    if(onSeg(a,p[1],p[2])||onSeg(a,p[1],p[n]))return 2;
    int l=2,r=n-1;
    while(l<r){ 
        int mid=l+r+1>>1;
        if(cha(p[1],p[mid],a)<0)l=mid;
        else r=mid-1;
    }
    if(cha(p[l],a,p[l+1])<0)return 0;
    if(onSeg(a,p[l],p[l+1]))return 2;
    return 1;
}
int main(){ 
    while(~scanf("%d",&n)){ 
        for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
        scanf("%d",&m);
        for(int i=1;i<=m;++i)scanf("%lf%lf",&b[i].x,&b[i].y);
        bool f=1;
        for(int i=1;i<=m;++i){ 
            if(TuContain(b[i])!=1){ 
                f=0;break;
            }
        }
        puts(f?"YES":"NO");
    }
    return 0;
}
