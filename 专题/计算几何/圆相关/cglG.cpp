#include<bits/stdc++.h>
#define diss(a,b) sqrt(dis(a,b))
#define pb push_back
using namespace std;
typedef double db;
const db eps=1e-8;
const db PI=acos(-1.0);
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
    P GP(db b){//圆上过一点知道角度和距离
        return P(c.x+cos(b)*r,c.y+sin(b)*r);
    }
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
//圆与直线交点 重点就2个一样 
//线段就直接求判点是否在线段上
void getCircleLineSec(P c,db r,P p1,P p2,vector<P>&ans){
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
void getCircleIntersec(P c1,db r1,P c2,db r2,vector<P>&ans){//圆与圆交点 要保证有交点圆心不重合 先判了圆的关系
    P u,v;
    db t;
    t=(1+(r1*r1-r2*r2)/diss(c1,c2)/diss(c1,c2))/2;
    u.x=c1.x+(c2.x-c1.x)*t;
    u.y=c1.y+(c2.y-c1.y)*t;
    v.x=u.x+c1.y-c2.y;
    v.y=u.y-c1.x+c2.x;
    getCircleLineSec(c1,r1,u,v,ans);
}
P RotateL(const P&a,const double&rad){//逆时针旋转
    return P(a.x*cos(rad)-a.y*sin(rad),a.y*cos(rad)+a.x*sin(rad));
}

//点p1到圆c的两条切线对应的切点
int getPCir_tangents(P c,db r,P p1,vector<P>&ans){
    P u=c-p1;
    db dist=diss(p1,c);
    if(dcmp(dist,r)<0)return 0;//内含
    else if(dcmp(dist,r)==0){//1条
        P x=RotateL(u,PI/2);
        ans.pb(p1);
        ans.pb(p1);
        return 1;
    }else{//2条切线
        db ang=asin(r/dist);
        u=u*sqrt(dis(p1,c)-r*r)/dist;
        P x1=RotateL(u,ang),x2=RotateL(u,-ang);
        ans.pb(x1+p1);
        ans.pb(x2+p1);
        return 2;
    }
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

//圆的公切线条数 a,b分别表示第i条切线在圆c1,c2上切点
//重合-无数条 内含-无 内切-一条外公切线 相交-两条外公切线 
//外切 3条公切线 一条内公切线,两条外公切线
//相离 4条公切线 内公切线2条 外公切线2条
int getPCir_tangents(Cir c1,Cir c2,P*a,P*b){//点集在[0,cnt-1]上
    int cnt=0;
    if(dcmp(c1.r,c2.r)<0)swap(c1,c2),swap(a,b);//对应点集仍不变
    int f=relationCir(c1,c2);
    if(!f)return 0;//内含
    P p1=c1.c,p2=c2.c;
    db r1=c1.r,r2=c2.r;
    if(dcmp(dis(p1,p2),0)==0&&dcmp(r1,r2)==0)return -1;//无数条切线
    db base=atan2(p2.y-p1.y,p2.x-p1.x);
    if(f==1){
        a[cnt]=c1.GP(base);
        b[cnt]=c2.GP(base);cnt++;
        return 1;
    }
    //2条外公切线
    db ang=acos((r1-r2)/diss(p1,p2));
    a[cnt]=c1.GP(base+ang);b[cnt]=c2.GP(base+ang);cnt++;
    a[cnt]=c1.GP(base-ang);b[cnt]=c2.GP(base-ang);cnt++;
    if(f==3){
        a[cnt]=c1.GP(base);b[cnt]=c2.GP(PI+base);cnt++;
    }else if(f==4){
        db ang=acos((r1+r2)/diss(p1,p2));
        a[cnt]=c1.GP(base+ang);b[cnt]=c2.GP(PI+base+ang);cnt++;
        a[cnt]=c1.GP(base-ang);b[cnt]=c2.GP(PI+base-ang);cnt++;
    }
    return cnt;
}

db Cirarea(P a,db r1,P b,db r2){//两圆面积交
    db d = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	if (dcmp(d,r1+r2)>=0)return 0;//相离相切
	if (dcmp(r1,r2)>0)swap(r1,r2);
	if(dcmp(r2-r1,d)>=0)//内含
		return PI*r1*r1;
	db ang1=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	db ang2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
	return ang1*r1*r1 + ang2*r2*r2 - r1*d*sin(ang1);
}
P ans1[5],ans2[5];
int main(){ 
    Cir xx=read_cir();
    Cir yy=read_cir();
    int m=getPCir_tangents(xx,yy,ans1,ans2);
    sort(ans1,ans1+m);
    for(int i=0;i<m;++i){
        printf("%.10f %.10f\n",ans1[i].x,ans1[i].y);
    }
    return 0;
}