#include<bits/stdc++.h>
#define CLR(a,b) memset(a,b,sizeof(a));
const int inf=0x3f3f3f3f;
using namespace std;
typedef double db;
const db PI = acos(-1.0);
const int maxn= 110;
struct point {
    db x,y,z;
    point() {
    }
    point(db a, db b,db c) {
        x = a;
        y = b;
        z = c;
    }
    point operator -(const point &b)const {     
        return point(x - b.x, y - b.y,z-b.z);
    }
    point operator +(const point &b)const { 
        return point(x + b.x, y + b.y,z+b.z);
    }
    point operator *(const db &k)const {    
        return point(x * k, y * k,z*k);
    }
    point operator /(const db &k)const {    
        return point(x / k, y / k,z/k);
    }
    db operator *(const point &b)const {    
        return x*b.x + y*b.y+z*b.z;
    }
};
 
db dist(point p1, point p2) {       
    return sqrt((p1 - p2)*(p1 - p2));
}
struct sphere {//球
    db r;
    point centre;
};
sphere P[3];
void SphereInterVS(sphere a, sphere b,db &v,db &s) {
    db d = dist(a.centre, b.centre);
    db t = (d*d + a.r*a.r - b.r*b.r) / (2.0 * d);//
    db h = sqrt((a.r*a.r) - (t*t)) * 2;
    db angle_a = 2 * acos((a.r*a.r + d*d - b.r*b.r) / (2.0 * a.r*d)); 
    db angle_b = 2 * acos((b.r*b.r + d*d - a.r*a.r) / (2.0 * b.r*d)); 
    db l1 = ((a.r*a.r - b.r*b.r) / d + d) / 2;
    db l2 = d - l1;
    db x1 = a.r - l1, x2 = b.r - l2;
    db v1 = PI*x1*x1*(a.r - x1 / 3);
    db v2 = PI*x2*x2*(b.r - x2 / 3);
     v = v1 + v2;
    db s1 = PI*a.r*x1;
    db s2 = PI*a.r*x2; 
     s = 4 * PI*(a.r*a.r + b.r*b.r) - s1 - s2;
}
int t, n;
db x, y, z, r;
int cas = 1;
int main()
{
    cin >> t;
    while(t--){
        db a,b,c,d,e,f,a1,b1,c1,d1,e1,f1;
        cin>>a>>b>>c>>d>>e>>f>>a1>>b1>>c1>>d1>>e1>>f1;
        int k1,k2;
        cin>>k1>>k2;
        P[1].centre={1.0*(k1*k1*d-a)/(k1*k1-1),1.0*(k1*k1*e-b)/(k1*k1-1),1.0*(k1*k1*f-c)/(k1*k1-1)};
        P[1].r=sqrt((k1*k1*d-a)*(k1*k1*d-a)/((k1*k1-1)*(k1*k1-1))+((k1*k1*e-b)*(k1*k1*e-b))/((k1*k1-1)*(k1*k1-1))+((k1*k1*f-c)*(k1*k1*f-c))/((k1*k1-1)*(k1*k1-1))-((k1*k1*(d*d+e*e+f*f)-(a*a+b*b+c*c))/(k1*k1-1)));
         
        P[2].centre={1.0*(k2*k2*d1-a1)/(k2*k2-1),1.0*(k2*k2*e1-b1)/(k2*k2-1),1.0*(k2*k2*f1-c1)/(k2*k2-1)};
        P[2].r=sqrt((k2*k2*d1-a1)*(k2*k2*d1-a1)/((k2*k2-1)*(k2*k2-1))+((k2*k2*e1-b1)*(k2*k2*e1-b1))/((k2*k2-1)*(k2*k2-1))+((k2*k2*f1-c1)*(k2*k2*f1-c1))/((k2*k2-1)*(k2*k2-1))-((k2*k2*(d1*d1+e1*e1+f1*f1)-(a1*a1+b1*b1+c1*c1))/(k2*k2-1)));
            db ss, dis = dist(P[1].centre, P[2].centre),v;
            db ans=0;
            if(dis >= P[1].r + P[2].r)ans=0;;  //在外部
            else if(dis + min(P[1].r, P[2].r) <= max(P[1].r, P[2].r))  //在内部
            {
                ans += 4.0 / 3.0 * PI * min(P[1].r,P[2].r) * min(P[1].r,P[2].r) * min(P[1].r,P[2].r);
            }else{ 
                SphereInterVS(P[1], P[2], v, ss); //相交部分
                ans += v;
            }
            printf("%.5f\n",ans);
        }
}
