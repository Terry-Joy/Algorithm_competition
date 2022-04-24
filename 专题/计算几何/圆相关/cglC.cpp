#include<bits/stdc++.h>
using namespace std;
typedef double db;
struct P{ //点向量类
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){ }
};
P circumcenter(P a,P b,P c){//外心 到三顶点距离相等 
	db X1=a.x,Y1=a.y,X2=b.x,Y2=b.y,X3=c.x,Y3=c.y;
	db a1=2*(X2-X1),b1=2*(Y2-Y1);
	db c1=X2*X2+Y2*Y2-X1*X1-Y1*Y1;
	db a2=2*(X3-X2),b2=2*(Y3-Y2);
	db c2=X3*X3+Y3*Y3-X2*X2-Y2*Y2;
	db x=(c1*b2-c2*b1)/(a1*b2-a2*b1);
	db y=(a1*c2-a2*c1)/(a1*b2-a2*b1);
	return P(x,y); 
} 
db dis(P a,P b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
db R(P a,P b){
    return sqrt(dis(a,b));
}
int main(){
    P a,b,c;
    scanf("%lf%lf",&a.x,&a.y);
    scanf("%lf%lf",&b.x,&b.y);
    scanf("%lf%lf",&c.x,&c.y);
    P ans=circumcenter(a,b,c);
    printf("%.18f %.18f %.18f\n",ans.x,ans.y,R(ans,a));
    return 0;
}