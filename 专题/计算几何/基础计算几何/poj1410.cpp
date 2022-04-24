#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef double db;
const db eps=1e-8;

int sign(db a){ //符号正负
    return a<-eps?-1:a>eps;
}

int dcmp(db a,db b){ //两数大小
    return sign(a-b);
}

db dAbs(db a){return a*sign(a);}

struct P{ //点向量类
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
    P operator+(P p){return P(x+p.x,y+p.y);}//左操作数
    P operator-(P p){ return P(x-p.x,y-p.y);}
    P operator*(db d){return P(x*d,y*d);}
    P operator/(db d){ return P(x/d,y/d);}
    bool operator<(P p)const{//点按x排序后按y排序
        int c=dcmp(x,p.x);
        if(c)return c==-1;
        return dcmp(y,p.y)==-1;
    }
    db len2(){ return x*x+y*y;}
    db len(){  return sqrt(len2());}
};
bool operator==(P a,P b){return !dcmp(a.x,b.x)&&!dcmp(a.y,b.y);}
db dot(P a,P b){//内积
    return a.x*b.x+a.y*b.y;
}
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))//p2-p1叉p3-p1
bool recInter(db l1,db r1,db l2,db r2){//矩形相交 快速排斥
    if(l1>r1)swap(l1,r1);if(l2>r2)swap(l2,r2);
    return !(dcmp(r1,l2)==-1||dcmp(r2,l1)==-1);
}
bool isSegInter(P p1,P p2,P q1,P q2){//判 线段p1p2与q1q2是否相交 保证不重点
    return recInter(p1.x,p2.x,q1.x,q2.x)&&recInter(p1.y,p2.y,q1.y,q2.y)&&
        cha(p1,p2,q1)*cha(p1,p2,q2)<=0&&cha(q1,q2,p1)*cha(q1,q2,p2)<=0;
}
bool onSeg(P c,P a,P b){//判断c是否在线段ab上
    return sign(det(c-a,b-a))==0&&sign(dot(c-a,c-b))<=0;
}
P p[7];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){ 
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y,&p[6].x,&p[6].y);
        if(p[3].x>p[6].x)swap(p[3],p[6]);
        if(p[3].y>p[6].y)
            p[4]=P(p[6].x,p[3].y),p[5]=P(p[3].x,p[6].y);
        else{ 
            p[4]=P(p[3].x,p[6].y),p[5]=P(p[6].x,p[3].y);
        }
        int h=max(p[6].y,p[3].y),t=min(p[6].y,p[3].y),l=min(p[6].x,p[3].x),r=max(p[6].x,p[3].x);
        if(max(p[1].x,p[2].x)<=r&&min(p[1].x,p[2].x)>=l&&max(p[1].y,p[2].y)<=h&&min(p[1].y,p[2].y)>=t){ 
            puts("T");continue;
        }
        if(isSegInter(p[1],p[2],p[3],p[4])||isSegInter(p[1],p[2],p[4],p[6])||isSegInter(p[1],p[2],p[5],p[6])||isSegInter(p[1],p[2],p[3],p[5]))
                puts("T");
        else puts("F");
    } 
    return 0;
}
