#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
typedef double db;
const db eps=1e-8;
const int maxn=300+5;
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
struct L{ 
    P ps[2];
    P &operator[](int i){ return ps[i];}
    P dir(){ return ps[1]-ps[0];}
    L(P X=P(),P Y=P()){ ps[0]=X,ps[1]=Y;}
}l[maxn];
int n,cnt,m,t;
P p[maxn];
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))//p2-p1叉p3-p1
bool recInter(db l1,db r1,db l2,db r2){//矩形相交 快速排斥
    if(l1>r1)swap(l1,r1);if(l2>r2)swap(l2,r2);
    return !(dcmp(r1,l2)==-1||dcmp(r2,l1)==-1);
}
bool isSegInter(P p1,P p2,P q1,P q2){//判 线段p1p2与q1q2是否相交 不用管重点
    return 
        cha(p1,p2,q1)*cha(p1,p2,q2)<0&&cha(q1,q2,p1)*cha(q1,q2,p2)<0;
}
typedef pair<db,int>Q;
db d[maxn][maxn];
void floyd(){
    for(int k=1;k<=cnt;++k){
        for(int i=1;i<=cnt;++i)
            for(int j=1;j<=cnt;++j){
                if(dcmp(d[i][j],d[i][k]+d[k][j])>0)
                    d[i][j]=d[i][k]+d[k][j];
            }
    }
}
bool onSeg(P c,P a,P b){ 
    return sign(det(c-a,b-a))==0&&sign(dot(c-a,c-b))<=0;
}
int main(){ 
    while(~scanf("%d",&n)&&n!=-1){ 
        cnt=m=0;
        db x,a,b,c,dd;
        p[++cnt]=P(0,5);
        for(int i=1;i<=n;++i){ 
            scanf("%lf%lf%lf%lf%lf",&x,&a,&b,&c,&dd);
            p[++cnt]=P(x,a);
            p[++cnt]=P(x,b);
            p[++cnt]=P(x,c);
            p[++cnt]=P(x,dd);
            l[++m]=L(P(x,0),p[cnt-3]);
            l[++m]=L(p[cnt-2],p[cnt-1]);
            l[++m]=L(p[cnt],P(x,10));
        }
        p[++cnt]=P(10,5);
        int k;
        for(int i=1;i<=cnt;++i)
            for(int j=1;j<=cnt;++j){
                if(i==j)d[i][j]=0;
                else d[i][j]=1e9;
            }
        for(int i=1;i<=cnt;++i)
            for(int j=i+1;j<=cnt;++j){ 
                for(k=1;k<=m;++k){
                    if(isSegInter(p[i],p[j],l[k].ps[0],l[k].ps[1]))
                        break;
                }
                if(k>m){
                    if(dcmp(d[i][j],(p[i]-p[j]).len()))
                        d[i][j]=(p[i]-p[j]).len();
                }
            }
        floyd();
        printf("%.2f\n",d[1][cnt]);
    }
    return 0;
}