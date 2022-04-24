#include<bits/stdc++.h>
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))//p2-p1叉p3-p1
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
    db len2(){ return x*x+y*y;}//能用ll就ll，精度
    db len(){  return sqrt(len2());}
};

bool operator==(P a,P b){return !dcmp(a.x,b.x)&&!dcmp(a.y,b.y);}

db dis(P a,P b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

db dot(P a,P b){//内积
    return a.x*b.x+a.y*b.y;
}
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
//点积运用

db Angle(P a,P b){//(2)两向量夹角
    return acos(dot(a,b)/len(a)/len(b));
}

db AngleSign(P a,P b){//(3)两夹角钝锐直
    return sign(dot(a,b));
}

P proj(P p1,P p2,P p){//(4)求p投影到p1,p2直线的点
    P a=p2-p1;
    return p1+a*(dot(p-p1,a)/a.len2());
}

P reflect(P p1,P p2,P p){//(5) p关于p1,p2直线对称的点
    return proj(p1,p2,p)*2-p;
}

P Unit(const P&a){//(4)求单位向量
    double L=len(a);
    return P(a.x/L,a.y/L);
}

db Area2(P a,P b,P c){//两向量平行四边形有向面积
    return det(b-a,c-a);
}

P RotateL(const P&a,const double&rad){//逆时针旋转
    return P(a.x*cos(rad)-a.y*sin(rad),a.y*cos(rad)+a.x*sin(rad));
}

P RotateR(const P&a,const double&rad){//顺时针旋转
    return P(a.x*cos(rad)+a.y*sin(rad),a.y*cos(rad)-a.x*sin(rad));
}

P RotateL90(const P&a){//向量逆时针旋转90度
    return P(-a.y,a.x);
}

P RotateR90(const P&a){//顺时针旋转90度
    return P(a.y,-a.x);
}

struct L{//ps[0]->ps[1]
    P ps[2];
    P &operator[](int i){return ps[i];}
    P dir(){return ps[1]-ps[0];}//直线方向向量
    L(P X=P(),P Y=P()){ps[0]=X,ps[1]=Y;}
};

bool thesameLine(L x1,L x2){//两直线是否重合
    P a=x2.ps[1]-x1.ps[1];
    return (sign(det(x1.dir(),x2.dir()))==0&&sign(det(x2.dir(),a))==0);   
}

bool parallel(L x1,L x2){//判两直线是否平行
    P a=x2.ps[1]-x1.ps[1];
    return sign(det(x1.dir(),x2.dir())==0&&sign(det(x2.dir(),a))!=0);   
}

bool Orthogonal(L x1,L x2){//判两直线是否垂直
    return sign(dot(x1.dir(),x2.dir()))==0;
}

bool onLine(L l1,P a){//点在直线上
    return sign(det(l1.dir(),a-l1.ps[0]))==0;
}

bool LineInterset(L l1,L l2){//直线是否相交
    return !parallel(l1,l2);
}

db PLinedis(L l1,P a){//平行四边形面积求点到直线距离 
    return dAbs(det(a-l1.ps[0],l1.dir())/l1.dir().len());
}

P LineInter(L l1,L l2){ //两直线交点 不平行的时候用
    P a=l1.ps[0],b=l1.ps[1],c=l2.ps[0],d=l2.ps[1];
    db t=det(a-c,c-d)/det(a-b,c-d);
    return P(a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t);
}

//线段相关
bool onSeg(P c,P a,P b){//判断c是否在线段ab上
    return sign(det(c-a,b-a))==0&&sign(dot(c-a,c-b))<=0;
}

db PdisSeg(P c,P a,P b){//点c到线段ab的距离
    if(a==b)return (c-a).len();
    P x=c-a,y=c-b,z=b-a;
    if(AngleSign(x,z)<0)return x.len();//c离a更近
    if(AngleSign(y,z)>0)return y.len();//c离b更近
    return dAbs(det(x,z)/z.len());
}

bool LineInSeg(L c,P a,P b){//直线C与线段ab是否交
    if(c.ps[0]==c.ps[1])return false;//看情况特判直线是否是重点
    return sign(det(c.dir(),a-c.ps[0]))*sign(det(c.dir(),b-c.ps[0]))<=0;
}

bool recInter(db l1,db r1,db l2,db r2){//矩形相交 快速排斥
    if(l1>r1)swap(l1,r1);if(l2>r2)swap(l2,r2);
    return !(dcmp(r1,l2)==-1||dcmp(r2,l1)==-1);
}

bool isSegInter(P p1,P p2,P q1,P q2){//判 线段p1p2与q1q2是否相交 端点算交 重点无关
    return recInter(p1.x,p2.x,q1.x,q2.x)&&recInter(p1.y,p2.y,q1.y,q2.y)&&
    cha(p1,p2,q1)*cha(p1,p2,q2)<=0&&cha(q1,q2,p1)*cha(q1,q2,p2)<=0;  
}

bool isSegInter(P p1,P p2,P q1,P q2){//判 线段p1p2与q1q2是否相交 端点不算交
    return cha(p1,p2,q1)*cha(p1,p2,q2)<0&&cha(q1,q2,p1)*cha(q1,q2,p2)<0; 
}

db SSdis(P p1,P p2,P q1,P q2){//线段p1p2到线段q1q2的最短路径
    if(isSegInter(p1,p2,q1,q2))return 0;
    return min(min(PdisSeg(p1,q1,q2),PdisSeg(p2,q1,q2)),min(PdisSeg(q1,p1,p2),PdisSeg(q2,p1,p2)));
}

//多边形相关
//三角形
//重心 到三角形三顶点距离平方和最小的点
//到三角形三边距离之积最大的点
P gravity(P a,P b,P c){
    db x=(a.x+b.x+c.x)/3;
    db y=(a.y+b.y+c.y)/3;
    return P(x,y);
}

P Incenter(P a,P b,P c){//内心 到三边距离相等 
    #define diss(a,b) sqrt(dis(a,b))
    db A=diss(b,c),B=diss(a,c),C=diss(a,b);
    db S=A+B+C;
    db x=(A*a.x+B*b.x+C*c.x)/S;
    db y=(A*a.y+B*b.y+C*c.y)/S;
    return P(x,y);
}

P circumcenter(P a,P b,P c){//外心 到三顶点距离相等 
	db X1=a.x,Y1=a.y,X2=b.x,Y2=b.y,X3=c.x,Y3=c.y;
	db a1=2*(X2-X1),b1=2*(Y2-Y1);
	db c1=X2*X2+Y2*Y2-X1*X1-Y1*Y1;
	db a2=2*(X3-X2),b2=2*(Y3-Y2);
	db c2=X3*X3+Y3*Y3-X2*X2-Y2*Y2;
	db x=(c1*b2-c2*b1)/(a1*b2-a2*b1);
	db y=(a1*c2-a2*c1)/(a1*b2-a2*b1);
	return P(x,y); 
} 

P perpencenter(P a,P b,P c){//垂心 
	db A1=b.x-c.x,B1=b.y-c.y;
	db C1=A1*a.y-B1*a.x;
	db A2=a.x-c.x,B2=a.y-c.y;
	db C2=A2*b.y-B2*b.x;
	db x=(A1*C2-A2*C1)/(A2*B1-A1*B2);
	db y=(B1*C2-B2*C1)/(A2*B1-A1*B2);
	return P(x,y);
}

P feiPoint(P a,P b,P c){//三角形费马点 到三顶点距离之和最小的点
    #define diss(a,b) sqrt(dis(a,b))
    P u=gravity(a,b,c),v;
    db step=fabs(a.x)+fabs(b.x)+fabs(c.x)+fabs(a.y)+fabs(b.y)+fabs(c.y);
    int i,j,k;
    while(step>1e-10){
        for(k=0;k<10;step/=2,k++)
            for(i=-1;i<=1;++i)
                for(j=-1;j<=1;++j){
                    v.x=u.x+step*i;
                    v.y=u.y+step*j;
                    if(dcmp(diss(u,a)+diss(u,b)+diss(u,c),diss(v,a)+diss(v,b)+diss(v,c))>0)
                        u=v;
                }
    }
    return u;
}

db area(vector<P>p){//任意多边形面积 顺逆都可
    db ans=0;
    int sz=p.size();
    for(int i=0;i<sz-1;++i)ans+=det(p[i],p[i+1]);
    ans+=det(p[sz-1],p[0]);
    return dAbs(ans/2);
}


//O(n)点在任意多边形内 点数为1或2也可
int contain(P ps[],P p,int n){//2:onSeg 1:inside 0：outside
    int flag=0,cnt=0;
    db tmp;
    for(int i=1;i<=n;++i){
        int j=i<n?i+1:1;
        if(onSeg(p,ps[i],ps[j]))return 2;//点在多边形上
        if(p.y>=min(ps[i].y,ps[j].y)&&p.y<max(ps[i].y,ps[j].y))
            tmp=ps[i].x+(p.y-ps[i].y)/(ps[j].y-ps[i].y)*(ps[j].x-ps[i].x),cnt+=(sign(tmp-p.x)>0);
    }
    return cnt&1;
}

int TuContain(P p[],int n,P a){//二分法判断a是否在凸多边形以内 必须是凸多边形
    if(n==1)if(p[1]==a)return 2;else return 0;              //特判非凸包 看情况加
    else if(n==2)if(onSeg(a,p[1],p[2]))return 2;else return 0;
    else{ 
    //点必须按逆时针给 顺时针>改<即可
        if(cha(p[1],a,p[2])>0||cha(p[1],p[n],a)>0)return 0;//P[1,2]或[1,n]外
        if(onSeg(a,p[1],p[2])||onSeg(a,p[1],p[n]))return 2;//[1,2]/[1,n]上
        int l=2,r=n-1;
        while(l<r){
            int mid=l+r+1>>1;
            if(cha(p[1],p[mid],a)>0)l=mid;//使得a被mid,mid+1到1夹住
            else r=mid-1;
        }
        if(cha(p[l],a,p[l+1])>0)return 0;
        if(onSeg(a,p[l],p[l+1]))return 2;
        return 1;
    }
}

//线与多边形
//(1). 判断线段 AB 是否在任意多边形 Poly 以内：不相交且两端点 A,B 均在多边形以内。
//(2). 判断线段 AB 是否在凸多边形 Poly 以内：两端点 A,B 均在多边形以内。

//判两多边形是否相离 O(n^2logn)
int PPLI(P a[],P b[],int num1,int num2){//先求两凸包
    for(int i1=1;i1<=num1;++i1){ 
        int j1=i1<num1?i1+1:1;
        for(int i2=1;i2<=num2;++i2){ 
            int j2=i2<num2?i2+1:1;
            if(isSegInter(a[i1],a[j1],b[i2],b[j2]))return 0;//线段相交不相离
            if(TuContain(b,num2,a[i1])||TuContain(a,num1,b[i2]))return 0;//点在多边形内不相离
        }
    }
    return 1;
}

//极角排序
bool cmp1(P a,P b){
    if(dcmp(atan2(a.y,a.x),atan2(b.y,b.x))!=0)
        return dcmp(atan2(a.y,a.x),atan2(b.y,b.x))<0;
    else return dcmp(a.x,b.x)<0;
}

int Qua(P a){ 
    if(dcmp(a.x,0)>0&&dcmp(a.y,0)>=0)return 1;
    if(dcmp(a.x,0)<=0&&dcmp(a.y,0)>0)return 2;
    if(dcmp(a.x,0)<0&&dcmp(a.y,0)<=0)return 3;
    if(dcmp(a.x,0)>=0&&dcmp(a.y,0)<0)return 4;
}

bool cmp2(P a,P b,P c){ //对C极角排序
    P p1=a-c,p2=b-c;
    if(Qua(p1)==Qua(p2)){ //先按象限1234 再按逆时针排
        db tmp=cha(c,a,b);
        if(tmp>0)return 1;
        else if(tmp==0&&p1.len2()<p2.len2())return 1;
    } 
    return Qua(p1)<Qua(p2);
}

int Andrew(P p[],P ch[]){//求凸包 
	sort(p+1,p+n+1);//重载的排序
	int m = 0;
	for(int i = 1; i <=n; i++){
		while(m > 1 && cha(ch[m-2],ch[m-1],p[i]) <= 0) m--;//<=不需要共线
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-1; i >= 1; i--){
		while(m > k && cha(ch[m-2],ch[m-1],p[i]) <= 0) m--;
		ch[m++] = p[i];
	}
	if(n > 1) m--;
	return m;
}


int rotate_calipers(){//旋转卡壳凸包直径平方 直径相应改db和cha
    Andrew();
    int j=1,ans=0;//j上一次做完的点
    for(int i=0;i<m;++i){
        while(cha(ch[i],ch[i+1],ch[j])<cha(ch[i],ch[i+1],ch[j+1]))j=(j+1)%m;
        ans=max(ans,max(dis(ch[i],ch[j]),dis(ch[i+1],ch[j])));
    }
    return ans;
}


