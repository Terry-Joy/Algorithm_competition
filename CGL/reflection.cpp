#include<bits/stdc++.h>

using namespace std;
typedef double db;
struct P{
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){}
    P operator+(P p){return P(x+p.x,y+p.y);}
    P operator-(P p){return P(x-p.x,y-p.y);}
    P operator*(db d){return P(x*d,y*d);}
    P operator/(db d){return P(x/d,y/d);}
    db len2(){
        return x*x+y*y;
    }
};
db dot(P a,P b){
    return a.x*b.x+a.y*b.y;
}

P proj(P p1,P p2,P p){
    P a=p2-p1;
    return p1+a*(dot(p-p1,a)/a.len2());
}
P reflect(P p1,P p2,P p){
    return proj(p1,p2,p)*2-p;
}
int main(){
    P p1,p2;
    int q;
    scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
    scanf("%d",&q);
    while(q--){
        P a;
        scanf("%lf%lf",&a.x,&a.y);
        P ans=reflect(p1,p2,a);
        printf("%.10lf %.10lf\n",ans.x,ans.y);
    }
    return 0;
}