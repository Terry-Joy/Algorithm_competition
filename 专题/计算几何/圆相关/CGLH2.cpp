#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=1e-8;
struct P{ 
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
    P operator+(P p){ return P(x+p.x,y+p.y);}
    P operator-(P p){ return P(x-p.x,y-p.y);}
    db len2(){ return x*x+y*y;}
    db len(){ return sqrt(len2());}
};
struct Cir{ 
    P c;
    db r;
    Cir(P _c=P(),db _r=0):c(_c),r(_r){ }
};
int sign(db a){ 
    return a<-eps?-1:a>eps;
}
int dcmp(db a,db b){ 
    return sign(a-b);
}
db det(P a,P b){ 
    return a.x*b.y-b.x*a.y;
}
db dot(P a,P b){ 
    return a.x*b.x+a.y*b.y;
}
db TriCirInterction(Cir c,P a,P b){ 
    P oa=a-c.c,ob=b-c.c;
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
db PolyonCirArea(Cir c,vector<P>&p){ 
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
