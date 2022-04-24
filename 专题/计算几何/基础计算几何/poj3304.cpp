#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef double db;
const db eps=1e-8;
const int maxn=105;
int t,n;
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

db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
db dot(P a,P b){ return a.x*b.y-a.y*b.x;}
struct L{//ps[0]->ps[1]
    P ps[2];
    P &operator[](int i){return ps[i];}
    P dir(){return ps[1]-ps[0];}//直线方向向量
    L(P X=P(),P Y=P()){ps[0]=X,ps[1]=Y;}
};
bool onSeg(P c,P a,P b){ 
    return sign(det(c-a,b-a))==0&&sign(dot(c-a,c-b))<=0;
}
P LineInter(L l1,L l2){ 
    P a=l1.ps[0],b=l1.ps[1],c=l2.ps[0],d=l2.ps[1];
    db t=det(a-c,c-d)/det(a-b,c-d);
    return P(a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t);
}
bool LineInSeg(L c,P a,P b){//直线C与线段ab是否相交
    return sign(det(c.dir(),a-c.ps[0]))*sign(det(c.dir(),b-c.ps[0]))<=0;
}
L l1[maxn];
bool operator==(P a,P b){return !dcmp(a.x,b.x)&&!dcmp(a.y,b.y);}
bool judge(L x){ 
	if(x.ps[0]==x.ps[1])return false; 
    for(int i=1;i<=n;++i){ 
        if(!LineInSeg(x,l1[i].ps[0],l1[i].ps[1]))return false;
    }
    return true;
}
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%lf%lf%lf%lf",&l1[i].ps[0].x,&l1[i].ps[0].y,&l1[i].ps[1].x,&l1[i].ps[1].y);
        bool flag=0;
        if(n==1){ puts("Yes!");continue;}
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){ 
                if(judge(L(l1[i].ps[0],l1[j].ps[0]))||judge(L(l1[i].ps[0],l1[j].ps[1]))
                                ||judge(L(l1[i].ps[1],l1[j].ps[0]))||judge(L(l1[i].ps[1],l1[j].ps[1])))
                 flag=1;
            }
            if(flag)break;
		}
        if(flag)puts("Yes!");
        else puts("No!");
    }
    return 0;
}
