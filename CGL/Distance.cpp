
#include<bits/stdc++.h>
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

db AngleSign(P a,P b){//(3)两夹角钝锐直
    return sign(dot(a,b));
}

db PdisSeg(P c,P a,P b){//点c到线段ab的距离
    if(a==b)return (c-a).len();
    P x=c-a,y=c-b,z=b-a;
    if(AngleSign(x,z)<0)return x.len();//c离a更近
    if(AngleSign(y,z)>0)return y.len();//c离b更近
    return dAbs(det(x,z)/z.len());
}

#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))//p2-p1叉p3-p1
bool recInter(db l1,db r1,db l2,db r2){//矩形相交 快速排斥
    if(l1>r1)swap(l1,r1);if(l2>r2)swap(l2,r2);
    return !(dcmp(r1,l2)==-1||dcmp(r2,l1)==-1);
}

bool isSegInter(P p1,P p2,P q1,P q2){//判 线段p1p2与q1q2是否相交 不用管重点
    return recInter(p1.x,p2.x,q1.x,q2.x)&&recInter(p1.y,p2.y,q1.y,q2.y)&&
        cha(p1,p2,q1)*cha(p1,p2,q2)<=0&&cha(q1,q2,p1)*cha(q1,q2,p2)<=0;
}

db SSdis(P p1,P p2,P q1,P q2){//线段p1p2到线段q1q2的最短路径
    if(isSegInter(p1,p2,q1,q2))return 0;
    return min(min(PdisSeg(p1,q1,q2),PdisSeg(p2,q1,q2)),min(PdisSeg(q1,p1,p2),PdisSeg(q2,p1,p2)));
}
P p[5];
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=4;++i){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        printf("%.10lf\n",SSdis(p[1],p[2],p[3],p[4]));
    }
    return 0;
}