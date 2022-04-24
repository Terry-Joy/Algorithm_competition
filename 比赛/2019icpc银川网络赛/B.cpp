#include<bits/stdc++.h>
using namespace std;
using db=double;
struct P{ 
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
    P operator-(P p){ return P(x-p.x,y-p.y);}
    P operator+(P p){ return P(x+p.x,y+p.y);}
    db len2(){ return x*x+y*y;}
    db len(){ return sqrt(len2());}
};
db dot(P a,P b){ 
    return a.x*b.x+a.y*b.y;
}
db Angle(P a,P b){ 
    return acos(dot(a,b)/a.len()/b.len());
}
P RotateR(const P&b,const P&a,const db&rad){ //a绕b逆时针旋转
    db x0=(a.x-b.x)*cos(rad)-(a.y-b.y)*sin(rad)+b.x;
    db y0=(a.x-b.x)*sin(rad)+(a.y-b.y)*cos(rad)+b.y;
    return P(x0,y0);
}
vector<P>p;
P Q;
int main(){ 
    int t,n;
    cin>>t;
    int T=0;
    while(t--){ 
        cin>>n;
        p.clear();
        p.resize(n+2);
        for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
        p[n]=p[0];
        p[n+1]=p[1];
        cin>>Q.x>>Q.y;
        P res={1e9,0},O={ 0,0};
        db ans=0,ang;
        for(int i=0;i<n;++i){ 
            ang=Angle(p[i+1]-p[i],p[i+2]-p[i+1]);
            P x=Q-p[i+1];
            ans+=x.len()*ang;
        }
        cout<<"Case #"<<++T<<": "<<fixed<<setprecision(3)<<ans<<"\n";
    }
    return 0;
}
