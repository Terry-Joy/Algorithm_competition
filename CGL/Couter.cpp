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
    db len2(){
        return x*x+y*y;
    }
    db len(){
        return sqrt(len2());
    }
};
db dot(P a,P b){//内积
    return a.x*b.x+a.y*b.y;
}
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}

int main(){
    P p0,p1;
    int q;
    scanf("%lf%lf%lf%lf",&p0.x,&p0.y,&p1.x,&p1.y);
    scanf("%d",&q);
    while(q--){
        P a;
        scanf("%lf%lf",&a.x,&a.y);
        double s1=sign(det(p1-p0,a-p0));
        double s2=sign(dot(a-p0,p1-p0));
        if(s1>0)cout<<"COUNTER_CLOCKWISE"<<"\n";
        else if(s1<0)cout<<"CLOCKWISE"<<"\n";
        else if(s1==0){
            if(s2<0)
                cout<<"ONLINE_BACK"<<"\n";
            else if(s2>0){
                if(sign((a-p0).len2()-(p1-p0).len2())>0)
                    cout<<"ONLINE_FRONT"<<"\n";
                else if(sign((a-p0).len2()-(p1-p0).len2())<=0)
                    cout<<"ON_SEGMENT"<<"\n";
            }
            else if(s2==0){
                if(sign((a-p0).len2()-(p1-p0).len2())>0)
                    cout<<"ONLINE_FRONT"<<"\n";
                else if(sign((a-p0).len2()-(p1-p0).len2())<=0)
                    cout<<"ON_SEGMENT"<<"\n";
            }
        }
    }
    return 0;
}