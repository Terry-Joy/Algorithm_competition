#include<bits/stdc++.h>
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))//p2-p1叉p3-p1
#define eb emplace_back
using namespace std;
typedef double db;
const db eps=1e-8;
const int maxn=105;
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
    bool operator<(P p)const{//点按x排序后按y排序
        int c=dcmp(x,p.x);
        if(c)return c==-1;
        return dcmp(y,p.y)==-1;
    }
    db len2(){ return x*x+y*y;}//能用ll就ll，精度
    db len(){  return sqrt(len2());}
}p[maxn];
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}

struct L{//ps[0]->ps[1]
    P ps[2];
    P &operator[](int i){return ps[i];}
    P dir(){return ps[1]-ps[0];}//直线方向向量
    L(P X=P(),P Y=P()){ps[0]=X,ps[1]=Y;}
}q[maxn];
int Qua(P a){ 
    if(a.x>0&&a.y>=0)return 1;
    if(a.x<=0&&a.y>0)return 2;
    if(a.x<0&&a.y<=0)return 3;
    if(a.x>=0&&a.y<0)return 4;
}
bool cmp(L l1,L l2){ 
    P a=l1.dir(),b=l2.dir();
    int f1=Qua(a),f2=Qua(b);
    if(f1==f2){ 
        db tmp=det(a,b);
        return tmp>=0;
    }
    return f1<f2;    
}
db area(vector<P>p){//任意多边形面积 顺逆都可
    db ans=0;
    int sz=p.size();
    if(!sz)return ans;
    for(int i=0;i<sz-1;++i)ans+=det(p[i],p[i+1]);
    ans+=det(p[sz-1],p[0]);
    return fabs(ans/2);
}
P LineInter(L l1,L l2){ //两直线交点 不平行的时候用
    P a=l1.ps[0],b=l1.ps[1],c=l2.ps[0],d=l2.ps[1];
    db t=det(a-c,c-d)/det(a-b,c-d);
    return P(a.x+(b.x-a.x)*t,a.y+(b.y-a.y)*t);
}
bool onRight(P a,L x){ 
    return sign(det(x.dir(),a-x.ps[0]))<=0;
}
int HalfPlaneInter(vector<L>line,vector<P>&sol){ 
    int n=line.size(),h,t;
    sort(line.begin(),line.end(),cmp);
    q[h=t=0]=line[0];
    for(int i=1;i<=n-1;++i){ 
        while(h<t&&onRight(p[t-1],line[i]))t--;
        while(h<t&&onRight(p[h],line[i]))h++;
        q[++t]=line[i];
        if(sign(det(q[t].dir(),q[t-1].dir()))==0){ 
            t--;//共线保留靠左
            if(!onRight(line[i].ps[0],q[t]))q[t]=line[i];
        }
        if(h<t)p[t-1]=LineInter(q[t],q[t-1]);
    }
    while(h<t&&onRight(p[t-1],q[h]))t--;
    if(t-h<=1)return 0;
    sol.clear();p[t]=LineInter(q[h],q[t]);
    for(int i=h;i<=t;++i)sol.eb(p[i]);
    return 1;
}
vector<P>a,hpi;//多边形、半平面
vector<L>line;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        a=vector<P>(n+1);
        for(int i=0;i<n;++i)cin>>a[i].x>>a[i].y;
        a[n]=a[0];
        for(int i=0;i<n;++i)line.eb(L(a[i],a[i+1]));
    }
    HalfPlaneInter(line,hpi);
  /*  for(auto&u:hpi){ 
        cout<<u.x<<" "<<u.y<<"\n";
    }*/
    printf("%.3lf",area(hpi));
    return 0;
}
