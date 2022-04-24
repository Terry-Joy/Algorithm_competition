#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=1e-8;
int sign(db a){
    return a<-eps?-1:a>eps;
}
struct P{ //点向量类
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
};
struct Cir{
    db r;
    P c;
    Cir(P _c=P(),db _r=0):c(_c),r(_r){}
};
db dis(P a,P b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
Cir read_cir(){
    Cir C;
    scanf("%lf%lf%lf",&C.c.x,&C.c.y,&C.r);
    return C;
}
//4相离 3外切 2两点交 1内切 0内含
int relationCir(Cir x,Cir y){
    db d=sqrt(dis(x.c,y.c));
    int f1=sign(d-x.r-y.r);
    if(f1>0)return 4;
    if(f1==0)return 3;
    db l=fabs(x.r-y.r);
    int f2=sign(d-l);
    if(f1<0&&f2>0)return 2;
    if(f2==0)return 1;
    if(f2<0)return 0;
}
int main(){
    Cir a=read_cir(),b=read_cir();
    cout<<relationCir(a,b)<<"\n";
    return 0;
}