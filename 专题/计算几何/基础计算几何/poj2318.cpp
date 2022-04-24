#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5005;
typedef double db;
const db eps=1e-8;
struct P{
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){}
    P operator+(P p){return P(x+p.x,y+p.y);}
    P operator-(P p){return P(x-p.x,y-p.y);}
};
struct L{
    P ps[2];
    P &operator[](int i){return ps[i];}
    P dir(){return ps[1]-ps[0];}
}line[maxn];
db det(P a,P b){return a.x*b.y-a.y*b.x;}
int sign(db a){ return  a<-eps?-1:a>eps;}
int n,m,x1,y1,x2,y2,a,b,X[maxn],ans[maxn];
bool check(int x,P in){ 
    db tmp=sign(det(line[x].dir(),in-line[x].ps[0]));
    return tmp<0;
}
int main(){
    while(~scanf("%d",&n)){
        if(!n)break;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for(int i=2;i<=n+1;++i){
            scanf("%d%d",&a,&b);
            line[i].ps[1]=P(a,y1);line[i].ps[0]=P(b,y2);
            X[i]=a;
        }
        line[1].ps[1]=P(x1,y1);line[1].ps[0]=P(x1,y2);
        X[1]=x1,X[n+2]=x2;
        line[n+2].ps[1]=P(x2,y1);line[n+2].ps[0]=P(x2,y2);
        P in;
        for(int i=0;i<=n+1;++i)ans[i]=0;
        for(int i=1;i<=m;++i){
            scanf("%lf%lf",&in.x,&in.y);
            int l=0,r=n+2;
            while(l<r){ 
                int mid=(l+r+1)>>1;
                if(check(mid,in))l=mid;
                else r=mid-1;
            }
            ans[l-1]++;
        }
        for(int i=1;i<=n+1;++i){
            cout<<i-1<<": "<<ans[i-1]<<"\n";
            if(i==n+1)puts("");
        }
    }   
    return 0;
}
