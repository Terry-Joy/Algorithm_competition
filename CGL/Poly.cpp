
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
int n,m;
vector<P>ps;

//线段相关
bool onSeg(P c,P a,P b){//判断c是否在线段ab上
    return sign(det(c-a,b-a))==0&&sign(dot(c-a,c-b))<=0;
}

int contain(P p){//2:onSeg 1:inside 0：outside
    int n=ps.size(),cnt=0;
    db tmp;
    for(int i=0;i<n;++i){
        int j=i<n-1?i+1:0;
        if(onSeg(p,ps[i],ps[j]))return 1;
        if(p.y>=min(ps[i].y,ps[j].y)&&p.y<max(ps[i].y,ps[j].y))
            tmp=ps[i].x+(p.y-ps[i].y)/(ps[j].y-ps[i].y)*(ps[j].x-ps[i].x),cnt+=(sign(tmp-p.x)>0);
    }
    if(cnt&1)return 2;
    else return 0;
}
int main(){
    scanf("%d",&n);
    ps.clear();
    P a;
    for(int i=1;i<=n;++i){
        scanf("%lf%lf",&a.x,&a.y);
        ps.push_back(a);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        scanf("%lf%lf",&a.x,&a.y);  
        cout<<contain(a)<<"\n";
    }
    return 0;
}