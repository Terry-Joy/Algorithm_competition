#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))
using namespace std;
typedef double db;
const db eps=1e-8;
int sign(db a){
    return a<-eps?-1:a>eps;
}
int dcmp(db a,db b){return sign(a-b);}
struct P{
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){
    }
    P operator+(P p){return P(x+p.x,y+p.y);}
    P operator-(P p){return P(x-p.x,y-p.y);}
    db len2(){return x*x+y*y;}
    int id;
};
db  det(P a,P b){
    return a.x*b.y-a.y*b.x;
}
P p[60];
int m,pos,n;
bool cmp(P a,P b){
    db tmp=cha(p[pos],a,b);
    if(tmp>0)return 1;
    else if(tmp==0&&(p[pos]-a).len2()<(p[pos]-b).len2())return 1;
    return 0;
}
int main(){
    scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d%lf%lf",&p[i].id,&p[i].x,&p[i].y);
        for(int i=2;i<=n;++i){
            if(dcmp(p[i].y,p[1].y)<0||((dcmp(p[i].y,p[1].y)==0&&dcmp(p[i].x,p[1].x)<0)))
                swap(p[1],p[i]);
        }
        pos=1;
        for(int i=2;i<=n;++i){
            sort(p+i,p+1+n,cmp);
            pos++;
        }
        cout<<n;
        for(int i=1;i<=n;++i)
            cout<<" "<<p[i].id;
        cout<<"\n";
    }
    return 0;
}