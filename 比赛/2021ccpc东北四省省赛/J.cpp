#include<bits/stdc++.h>
using namespace std;
using db=double;
const db eps=1e-8;
const db PI=acos(-1.0);
db sqr(db a){ 
    return a*a;
}
struct P{ 
    db x,y,z;
    P(db _x=0,db _y=0,db _z=0):x(_x),y(_y),z(_z){ }
    db len()const{ 
        return sqrt(sqr(x)+sqr(y)+sqr(z));
    }
    P std()const;
}A,B;
void read(P&a){ 
    scanf("%lf%lf%lf",&a.x,&a.y,&a.z);
}
P operator+(const P&a,const P&b){ 
    return P(a.x+b.x,a.y+b.y,a.z+b.z);
}
P operator-(const P&a,const P&b){ 
    return P(a.x-b.x,a.y-b.y,a.z-b.z);
}
P operator*(const P&a,db b){ 
    return P(a.x*b,a.y*b,a.z*b);
}
P operator/(const P&a,db b){ 
    return P(a.x/b,a.y/b,a.z/b);
}
P P::std()const{ 
    return *this/len();
}
P det(const P&a,const P&b){ 
    return P(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
db dot(const P&a,const P &b){ 
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
int cmp(db a){ 
    return a<-eps?-1:a>eps;
}
P rotate(P a,P b,db angle){ 
    P e1,e2,e3;
    e3=b.std();
    b=b.std();
    db len=dot(a,e3);
    P p=e3*len;
    e1=a-p;
    if(e1.len()>(eps))e1=e1.std();
    e2=det(e1,e3);
    db x1=dot(a,e2),y1=dot(a,e1);
    db x=x1*cos(angle)-y1*sin(angle);
    db y=x1*sin(angle)+y1*cos(angle);
    return e1*y+e2*x+p;
}
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){ 
        read(A);
        read(B);
        db ang;
        scanf("%lf",&ang);
        ang=1.0*ang*PI/180;
        P x1=rotate(B,A,ang),x2=rotate(B,A,-ang);
        if(cmp(x1.z-x2.z)>0){ 
            printf("%.9f %.9f %.9f\n",x1.x,x1.y,x1.z);
        }else
            printf("%.9f %.9f %.9f\n",x2.x,x2.y,x2.z);
    }
    return 0;
}
