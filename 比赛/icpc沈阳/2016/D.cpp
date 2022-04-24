#include<bits/stdc++.h>

using namespace std;
typedef double db;
const db eps=1e-12;
const db pi=acos(-1.0);
db S(db a){
    return -a*cos(a)+sin(a)-(1/3.0)*sin(a)*sin(a)*sin(a);
}
int sign(db a){ //符号正负
    return a<-eps?-1:a>eps;
}
int dcmp(db a,db b){ //两数大小
    return sign(a-b);
}
int main(){
    int t;   
    scanf("%d",&t);
    while(t--){
        db d;
        scanf("%lf",&d);
        if(dcmp(d,0)==0){
            printf("%.5lf\n",0);
        }else if(dcmp(d,1)>=0){
            printf("%.5lf\n",pi/(sin(atan(1/(2-d)))));
        }else{
            db V;
            db l=0;db r=pi/4.0;
            for(int i=1;i<=100;++i){
                db mid=(l+r)/2.0;
                db a=acos(1.0-2.0*tan(mid));
                db v=S(a)/tan(mid);
                if(dcmp(v,pi*d)==0){
                    V=mid;break;
                }else if(dcmp(v,pi*d)>=0){
                    r=mid;
                }else l=mid;
            }
            db a=acos(1.0-2.0*tan(V));
            db x=(a-sin(2*a)/2.0)/sin(V);
            printf("%.5lf\n",x);
        }
    }
    return 0;
}