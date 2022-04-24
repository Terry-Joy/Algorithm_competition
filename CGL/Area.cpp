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
vector<P>x;
bool operator==(P a,P b){return !dcmp(a.x,b.x)&&!dcmp(a.y,b.y);}

db dot(P a,P b){//内积
    return a.x*b.x+a.y*b.y;
}
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}

db area(vector<P>p){//任意多边形面积 顺逆都可
    db ans=0;
    int sz=p.size();
    for(int i=0;i<sz-1;++i)ans+=det(p[i],p[i+1]);
    ans+=det(p[sz-1],p[0]);
    return dAbs(ans/2);
}

int main(){ 
    int n;
    scanf("%d",&n);
    P a;
    for(int i=1;i<=n;++i){
        scanf("%lf%lf",&a.x,&a.y);
        x.push_back(a);
    }
    printf("%.1lf\n",area(x));
    return 0;
}