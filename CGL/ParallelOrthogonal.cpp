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
    db len2(){
        return x*x+y*y;
    }
    db len(){
        return sqrt(len2());
    }
};
db dot(P a,P b){//内积
    return a.x*b.x+a.y*b.y;
}
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}

struct L{//ps[0]->ps[1]
    P ps[2];
    P &operator[](int i){return ps[i];}
    P dir(){return ps[1]-ps[0];}//直线方向向量
};


bool thesameLine(L x1,L x2){//两直线是否重合
    if(x1.ps[0].x==x1.ps[1].x&&x2.ps[0].x==x2.ps[1].x){
        if(x1.ps[0].x==x2.ps[0].x)return 1;//重合
        else return 0;//垂直x轴平行
    }
    if(x1.ps[0].y==x1.ps[1].y&&x2.ps[0].y==x2.ps[1].y){
        if(x1.ps[0].y==x2.ps[0].y)return 1;//重合
        else return 0;//垂直
    }
    db del=dcmp(det(x1.ps[1],x1.ps[0]),det(x2.ps[1],x2.ps[0]));
    return (sign(det(x1.dir(),x2.dir()))==0&&del==0);   

}

bool parallel(L x1,L x2){//判两直线是否平行
    if(x1.ps[0].x==x1.ps[1].x&&x2.ps[0].x==x2.ps[1].x){
        if(x1.ps[0].x==x2.ps[0].x)return 0;//重合
        else return 1;//垂直x轴平行
    }
    if(x1.ps[0].y==x1.ps[1].y&&x2.ps[0].y==x2.ps[1].y){
        if(x1.ps[0].y==x2.ps[0].y)return 0;//重合
        else return 1;
    }
    db del=dcmp(det(x1.ps[1],x1.ps[0]),det(x2.ps[1],x2.ps[0]));
    return (sign(det(x1.dir(),x2.dir()))==0&&del!=0);   
}

bool Orthogonal(L x1,L x2){//判两直线是否垂直
    return sign(dot(x1.dir(),x2.dir()))==0;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        L a,b;
        scanf("%lf%lf%lf%lf",&a.ps[0].x,&a.ps[0].y,&a.ps[1].x,&a.ps[1].y);
        scanf("%lf%lf%lf%lf",&b.ps[0].x,&b.ps[0].y,&b.ps[1].x,&b.ps[1].y);
        if(parallel(a,b))
            puts("2");
        else if(Orthogonal(a,b))
            puts("1");
        else puts("0");
    }
    return 0;
}
