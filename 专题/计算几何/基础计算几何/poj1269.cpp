#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
typedef double db;
const db eps=1e-8;
int sign(db a){ 
    return a<-eps?-1:a>eps;
}
int dcmp(db a,db b){ 
    return sign(a-b);
}
struct P{ 
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
    P operator+(P p){ return P(x+p.x,y+p.y);}
    P operator-(P p){ return P(x-p.x,y-p.y);}
    P operator*(db d){ return P(x*d,y*d);}
    P operator/(db d){ return P(x/d,y/d);}
    db len2(){ return x*x+y*y;}
    db len(){ return sqrt(len2());}
};
db det(P a,P b){ 
    return a.x*b.y-a.y*b.x;
}
struct L{ 
    P ps[2];
    P &operator[](int i){ return ps[i];}
    P dir(){ return ps[1]-ps[0];}
};
bool thesameLine(L x1,L x2){//两直线是否重合
    P a=x2.ps[1]-x1.ps[1];
    return (sign(det(x1.dir(),x2.dir()))==0&&sign(det(x2.dir(),a))==0);   
}

bool parallel(L x1,L x2){//判两直线是否平行
    P a=x2.ps[1]-x1.ps[1];
    return (sign(det(x1.dir(),x2.dir()))==0&&sign(det(x2.dir(),a))!=0);   
}
bool LineInterset(L l1,L l2){//直线是否相交
    return !parallel(l1,l2);
}
db PLinedis(L l1,P a){//平行四边形面积求点到直线距离
    return fabs(det(a-l1.ps[0],l1.dir())/l1.dir().len());
}
P LineInter(L l1,L l2){ //两直线交点 不平行的时候用
    P a=l1.ps[0],b=l1.ps[1],c=l2.ps[0],d=l2.ps[1];
    db t=det(a-c,c-d)/det(a-b,c-d);
    return P(a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t);
}
int main(){ 
    int n;
    scanf("%d",&n);
    L l1,l2;
    puts("INTERSECTING LINES OUTPUT");
    for(int i=1;i<=n;++i){ 
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&l1.ps[0].x,&l1.ps[0].y,&l1.ps[1].x,&l1.ps[1].y,&l2.ps[0].x,&l2.ps[0].y,&l2.ps[1].x,&l2.ps[1].y);
        if(thesameLine(l1,l2))
            puts("LINE");
        else if(parallel(l1,l2))
            puts("NONE");
        else{ 
            P a=LineInter(l1,l2);
            printf("POINT %.2lf %.2lf\n",a.x,a.y);
        }
    }
    puts("END OF OUTPUT");
    return 0;
}
