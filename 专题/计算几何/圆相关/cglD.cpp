#include<bits/stdc++.h>
#define diss(a,b) sqrt(dis(a,b))
#define pb push_back
using namespace std;
typedef double db;
const db eps=1e-8;
int q;
int sign(db a){ //符号正负
    return a<-eps?-1:a>eps;
}
int dcmp(db a,db b){ //两数大小
    return sign(a-b);
}
struct P{ //点向量类
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
    P operator+(P p){return P(x+p.x,y+p.y);}//左操作数
    P operator-(P p){ return P(x-p.x,y-p.y);}
    P operator*(db d){return P(x*d,y*d);}
    P operator/(db d){ return P(x/d,y/d);}
    db len2(){ return x*x+y*y;}//能用ll就ll，精度
    db len(){  return sqrt(len2());}
     bool operator<(P p)const{//点按x排序后按y排序
        int c=dcmp(x,p.x);
        if(c)return c==-1;
        return dcmp(y,p.y)==-1;
    }
};
db dis(P a,P b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
struct L{//ps[0]->ps[1]
    P ps[2];
    P &operator[](int i){return ps[i];}
    P dir(){return ps[1]-ps[0];}//直线方向向量
    L(P X=P(),P Y=P()){ps[0]=X,ps[1]=Y;}
};
struct Cir{
    db r;
    P c;
    Cir(P _c=P(),db _r=0):c(_c),r(_r){}
};
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
db PLinedis(L l1,P a){//平行四边形面积求点到直线距离 
    return fabs(det(a-l1.ps[0],l1.dir())/l1.dir().len());
}
P LineInter(L l1,L l2){ //两直线交点 不平行的时候用
    P a=l1.ps[0],b=l1.ps[1],c=l2.ps[0],d=l2.ps[1];
    db t=det(a-c,c-d)/det(a-b,c-d);
    return P(a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t);
}
void getCircleLineSec(P c,db r,P p1,P p2,vector<P>&ans){//圆与直线交点 重点就2个一样
    P p=c;
    db t;
    p.x+=p1.y-p2.y;
    p.y+=p2.x-p1.x;
    p=LineInter(L(p,c),L(p1,p2));
    t=sqrt(r*r-diss(p,c)*diss(p,c))/diss(p1,p2);
    P x1,x2;
    x1={p.x+(p2.x-p1.x)*t,p.y+(p2.y-p1.y)*t};
    x2={p.x-(p2.x-p1.x)*t,p.y-(p2.y-p1.y)*t};
    ans.pb(x1);ans.pb(x2);
}
Cir read_cir(){
    Cir C;
    scanf("%lf%lf%lf",&C.c.x,&C.c.y,&C.r);
    return C;
}
int main(){ 
    Cir xx=read_cir();
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        vector<P>ps;
        P p1,p2,p3,p4;
        scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
        getCircleLineSec(xx.c,xx.r,p1,p2,ps);
        sort(ps.begin(),ps.end());
        for(auto&v:ps){
            printf("%.10f %.10f ",v.x,v.y);
        }
        puts("");
    }
    return 0;
}