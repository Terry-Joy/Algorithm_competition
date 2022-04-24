#include<bits/stdc++.h>
#define pb push_back
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))//p2-p1叉p3-p1
using namespace std;
typedef double db;
const db eps=1e-8;
const int maxn=1005;
int n,m;
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
    db len2(){ return x*x+y*y;}//能用ll就ll，精度
}p[maxn],st,ed;
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
    L(P X=P(),P Y=P()){ps[0]=X,ps[1]=Y;}
}l1;
bool onSeg(P c,P a,P b){//判断c是否在线段ab上
    return sign(dot(c-a,c-b))<=0;
}
P LineInter(L l1,L l2){ //两直线交点 不平行的时候用
    P a=l1.ps[0],b=l1.ps[1],c=l2.ps[0],d=l2.ps[1];
    db t=det(a-c,c-d)/det(a-b,c-d);
    return P(a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t);
}
vector<P>ans[maxn];
bool cmp(P a,P b){
    return (a-st).len2()<(b-st).len2();
}
int main(){ 
    scanf("%d%d",&n,&m);
    scanf("%lf%lf%lf%lf",&st.x,&st.y,&ed.x,&ed.y);
    for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j)continue;
            P a=LineInter(L(st,ed),L(p[i],p[j]));
            if(onSeg(a,st,ed)){
                ans[i].pb(a);
            }
        }
        sort(ans[i].begin(),ans[i].end(),cmp);
    }
    int hi,ki;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&hi,&ki);
        if(ki>ans[hi].size())puts("-1");
        else printf("%.10f %.10f\n",ans[hi][ki-1].x,ans[hi][ki-1].y);
    }
    return 0;
}