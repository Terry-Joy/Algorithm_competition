#include<bits/stdc++.h>
#define diss(a,b) sqrt(dis(a,b))
#define pb push_back
using namespace std;
typedef long double db;
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
db dot(P a,P b){ 
    return a.x*b.x+a.y*b.y;
}
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
//圆与直线交点
//线段就直接求判点是否在线段上
vector<P> getCircleLineSec(P c,db r,P p1,P p2){//返回空 or 1 or 2交点
	vector<P>ans;
	db dd=PLinedis(L(p1,p2),c);
	if(dcmp(dd,r)>0)return ans;//离
    P p=c;
    db t;
    p.x+=p1.y-p2.y;
    p.y+=p2.x-p1.x;
    p=LineInter(L(p,c),L(p1,p2));
    t=sqrt(r*r-diss(p,c)*diss(p,c))/diss(p1,p2);
    P x1,x2;
    x1={p.x+(p2.x-p1.x)*t,p.y+(p2.y-p1.y)*t};
    x2={p.x-(p2.x-p1.x)*t,p.y-(p2.y-p1.y)*t};
	ans.pb(x1);
	if(dcmp(dd,r)==0)//切
    	return ans;
	else	
		ans.pb(x2);
	return ans;
}

Cir read_cir(){
    Cir C;
	cin>>C.c.x>>C.c.y>>C.r;
    return C;
}

P RotateL90(const P&a){ 
    return P(-a.y,a.x);
}

vector<P>getCircelIntersec(P a,db r,P b,db R){ //圆与圆交点
    vector<P>ret;
    db d=diss(a,b);
    if (dcmp(d,r+R)>0||dcmp(d+min(r,R),max(r,R))<0) return ret;
	db x = (d*d-R*R+r*r)/(2*d);
	db y = sqrt(r*r-x*x);
	P v = (b-a)/d;
	ret.push_back(a+v*x + RotateL90(v)*y);
	if (sign(y)>0) ret.push_back(a+v*x - RotateL90(v)*y);
	return ret;
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

// 圆的公切线条数 a,b分别表示第i条切线在圆c1,c2上切点
// 重合-无数条 内含-无 内切-一条外公切线 相交-两条外公切线 
// 外切 3条公切线 一条内公切线,两条外公切线
// 相离 4条公切线 内公切线2条 外公切线2条
int getPCir_tangents(Cir c1,Cir c2,P*a,P*b){//点集在[0,cnt-1]上
    int cnt=0;
    if(dcmp(c1.r,c2.r)<0)swap(c1,c2),swap(a,b);//对应点集仍不变
    int f=relationCir(c1,c2);
    if(!f)return 0;//内含
    P p1=c1.c,p2=c2.c;
    db r1=c1.r,r2=c2.r;
    if(dcmp(dis(p1,p2),0)==0&&dcmp(r1,r2)==0)return -1;//无数条切线
    db base=atan2(p2.y-p1.y,p2.x-p1.x);
    if(f==1){//内切一条
        a[cnt]=c1.GP(base);
        b[cnt]=c2.GP(base);cnt++;
        return 1;
    }
    //2条外公切线
    db ang=acos((r1-r2)/diss(p1,p2));
    a[cnt]=c1.GP(base+ang);b[cnt]=c2.GP(base+ang);cnt++;
    a[cnt]=c1.GP(base-ang);b[cnt]=c2.GP(base-ang);cnt++;
    if(f==3){//一条内
        a[cnt]=c1.GP(base);b[cnt]=c2.GP(PI+base);cnt++;
    }else if(f==4){//两条内
        db ang=acos((r1+r2)/diss(p1,p2));
        a[cnt]=c1.GP(base+ang);b[cnt]=c2.GP(PI+base+ang);cnt++;
        a[cnt]=c1.GP(base-ang);b[cnt]=c2.GP(PI+base-ang);cnt++;
    }
    return cnt;
}

db Cirarea(P a,db r1,P b,db r2){//两圆面积交  很可能要开long double 精度不够
    db d = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	if (dcmp(d,r1+r2)>=0)return 0;//相离相切
	if (dcmp(r1,r2)>0)swap(r1,r2);
	if(dcmp(r2-r1,d)>=0)//内含
		return PI*r1*r1;
	db ang1=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	db ang2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
	return ang1*r1*r1 + ang2*r2*r2 - r1*d*sin(ang1);
}

//判某条线段能否被若干圆完全覆盖
bool direct(L x){
	vector<pair<P,int>>sec;
	P a=x.ps[0],b=x.ps[1];
	if(a<b)swap(a,b);
	sec.push_back({a,-2});
	sec.push_back({b,2});
	for(auto&u:cir){
		auto tmpjiao=getCircleLineSec(u.c,u.r,x.ps[0],x.ps[1]);
		if(tmpjiao.size()==2){
			if(tmpjiao[0]<tmpjiao[1])swap(tmpjiao[0],tmpjiao[1]);
			sec.push_back({tmpjiao[0],0});
			sec.push_back({tmpjiao[1],1});
		}
	}
	sort(sec.begin(),sec.end());
	bool ret = true, counting = false;
	int inside = 0;
	for(int i=0; i < sec.size(); i++) {
		if(abs(sec[i].se) == 2) counting = !counting;
		else sec[i].se ? inside-- : inside++;
		if(counting and !inside) ret = false;
	}
	return ret;
}


//求多个圆与线段的交的长度
using PDD = pair<double, double>;
#define sqr(x) ((x) * (x))
db coverLen(L a, Cir c[], int n) {//[1,n]是圆
  db Cos = ((a.ps[1].x - a.ps[0].x) / a.len()), Sin = ((a.ps[1].y - a.ps[0].y) / a.dir().len());
  db dx = a.ps[0].x, dy = a.ps[0].y;
  vector<PDD> mat;
  for (int i = 1; i <= n; i++) {
    db A = 1;
    db B = -2 * (Cos * (c[i].c.x - dx) + Sin * (c[i].c.y - dy));
    db C = pow2(c[i].c.x - dx) + pow2(c[i].c.y - dy) - c[i].r * c[i].r;
    db D = B * B - 4 * A * C;
    if (sign(D) < 0) continue;
    D = sign(D) ? sqrt(D) : 0;  // 清误差
    db L = max(0.0, min(a.dir().len(), (-B - D) / (2 * A)));
    db R = max(0.0, min(a.dir().len(), (-B + D) / (2 * A)));
    mat.eb(mp(L, R));
  }
  sort(all(mat));
  db las = 0, tot = 0;
  for (int i = 0; i < mat.size(); i++) {
    if (dcmp(las,mat[i].fi)<0) las = mat[i].fi;
    if (dcmp(las,mat[i].se)<0) tot += mat[i].se - las, las = mat[i].se;
  }
  return tot;
}


db TriCirInterction(Cir c,P a,P b){ //三角剖分求圆与多边形面积交
    P oa=a-c.c,ob=b-c.c;//逆时针
    P ba=a-b,bc=c.c-b;
    P ab=b-a,ac=c.c-a;
    db doa=oa.len(),dob=ob.len(),dab=ab.len(),r=c.r;
    if(dcmp(det(oa,ob),0)==0)return 0;//三点一线 无三角形
    if(dcmp(doa,r)<0&&dcmp(dob,r)<0)return 0.5*det(oa,ob);//三点内部
    else if(dcmp(dob,r)<0&&dcmp(doa,r)>=0){ 
        db x=(dot(ba,bc)+sqrt(r*r*dab*dab-det(ba,bc)*det(ba,bc)))/dab;
        db TS=det(oa,ob)*0.5;
        return asin(TS*(1-x/dab)*2/r/doa)*r*r*0.5+TS*x/dab;
    }else if(dcmp(dob,r)>=0&&dcmp(doa,r)<0){ 
        db y=(dot(ab,ac)+sqrt(r*r*dab*dab-det(ab,ac)*det(ab,ac)))/dab;
        db TS=det(oa,ob)*0.5;
        return asin(TS*(1-y/dab)*2/r/dob)*r*r*0.5+TS*y/dab;
    }else if(fabs(det(oa,ob))>=r*dab||dcmp(dot(ab,ac),0)<=0||(dcmp(dot(ba,bc),0)<=0)){//两点外 单扇形 
        db ang=acos(dot(oa,ob)/doa/dob);
        return sign(det(oa,ob))*ang*r*r*0.5;
    }else{ 
        db x=(dot(ba,bc)+sqrt(r*r*dab*dab-det(ba,bc)*det(ba,bc)))/dab;
        db y=(dot(ab,ac)+sqrt(r*r*dab*dab-det(ab,ac)*det(ab,ac)))/dab;
        db TS=det(oa,ob)*0.5;
        return (asin(TS*(1-x/dab)*2/r/doa)+asin(TS*(1-y/dab)*2/r/dob))*r*r*0.5+TS*((x+y)/dab-1);
    }
}
int n;
db PolyonCirArea(Cir c,vector<P>&p){ //圆与多边形面积交
    db ans=0;
    for(int i=0;i<n;++i){ 
        ans+=TriCirInterction(c,p[i],p[i+1]);
    }
    return fabs(ans);
}

vector<P>p(100005);
int main(){ 
    db x,y,h,x1,y1,t,r,ans=0;
    cin>>n>>r;
    Cir c;
    c.c=P(0,0);c.r=r;
    for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
    p[n]=p[0];
    printf("%.12f\n",PolyonCirArea(c,p));
    return 0;
}

db cap(db r,db h){return pi*(r*3-h)*h*h/3;}

//2球体积交
db sphere_intersect(db x1,db y1,db z1,db r1,db x2,db y2,db z2,db r2){
	db d=dis(x1,y1,z1,x2,y2,z2);
	//相离
	if(d>=pow2(r1+r2))return 0;
	//包含
	if(d<=pow2(r1-r2))return pow3(min(r1,r2))*4*pi/3;
	//相交
	db h1=r1-r1*cos(r2,r1,sqrt(d)),h2=r2-r2*cos(r1,r2,sqrt(d));
	return cap(r1,h1)+cap(r2,h2);
}

//2球体积并
db sphere_union(db x1,db y1,db z1,db r1,db x2,db y2,db z2,db r2){
	db d=dis(x1,y1,z1,x2,y2,z2);
	//相离
	if(d>=pow2(r1+r2))return (pow3(r1)+pow3(r2))*4*pi/3;
	//包含
	if(d<=pow2(r1-r2))return pow3(max(r1,r2))*4*pi/3;
	//相交
	db h1=r1+r1*cos(r2,r1,sqrt(d)),h2=r2+r2*cos(r1,r2,sqrt(d));
	return cap(r1,h1)+cap(r2,h2);
}
