#include<bits/stdc++.h>
#define diss(a,b) sqrt(dis(a,b))
using namespace std;
typedef double db;
struct P{ //点向量类
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
    P operator-(P p){ return P(x-p.x,y-p.y);}
    db len2(){ return x*x+y*y;}//能用ll就ll，精度
    db len(){  return sqrt(len2());}
};
db dis(P a,P b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
P Incenter(P a,P b,P c){//内心 到三边距离相等 
    db A=diss(b,c),B=diss(a,c),C=diss(a,b);
    db S=A+B+C;
    db x=(A*a.x+B*b.x+C*c.x)/S;
    db y=(A*a.y+B*b.y+C*c.y)/S;
    return P(x,y);
} 
struct L{//ps[0]->ps[1]
    P ps[2];
    P &operator[](int i){return ps[i];}
    P dir(){return ps[1]-ps[0];}//直线方向向量
    L(P X=P(),P Y=P()){ps[0]=X,ps[1]=Y;}
};
db PLinedis(L l1,P a){//平行四边形面积求点到直线距离 
    return fabs(det(a-l1.ps[0],l1.dir())/l1.dir().len());
}
int main(){
    P a,b,c;
    scanf("%lf%lf",&a.x,&a.y);
    scanf("%lf%lf",&b.x,&b.y);
    scanf("%lf%lf",&c.x,&c.y);
    P ans=Incenter(a,b,c);
    L l1(a,b);
    printf("%.18f %.18f %.18f\n",ans.x,ans.y,PLinedis(l1,ans));
    return 0;
}