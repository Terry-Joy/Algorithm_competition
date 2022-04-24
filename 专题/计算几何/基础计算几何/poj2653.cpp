#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define cha(p1,p2,p3)  (sign(det(p2-p1,p3-p1)))
#define fi first
#define se second
using namespace std;
const int maxn=1e5+5;
bool used[maxn];
typedef double db;
const db eps=1e-8;
int sign(db a){
    return a<-eps?-1:a>eps;
}
int dcmp(db a,db b){return sign(a-b);}
struct P{
    db x,y;
    P(db _x=0,db _y=0):x(_x),y(_y){}
    P operator+(P p){return P(x+p.x,y+p.y);}
    P operator-(P p){return P(x-p.x,y-p.y);}
};
typedef pair<P,P>pp;
int n;
db dot(P a,P b){
    return a.x*b.x+a.y*b.y;
}
db det(P a,P b){
    return a.x*b.y-a.y*b.x;
}
bool recInter(db l1,db r1,db l2,db r2){
    if(l1>r1)swap(l1,r1);if(l2>r2)swap(l2,r2);
    return !(dcmp(r1,l2)==-1||dcmp(r2,l1)==-1);
}
bool isSegInter(P p1,P p2,P q1,P q2){
    return recInter(p1.x,p2.x,q1.x,q2.x)&&recInter(p1.y,p2.y,q1.y,q2.y)&&
    cha(p1,p2,q1)*cha(p1,p2,q2)<=0&&cha(q1,q2,p1)*cha(q1,q2,p2)<=0;
}
pp a[maxn];
vector<int>ans;
int main(){
    while(~scanf("%d",&n)&&n){
        ans.clear();
        for(int i=1;i<=n;++i)used[i]=1;
        for(int i=1;i<=n;++i){
            scanf("%lf%lf%lf%lf",&a[i].fi.x,&a[i].fi.y,&a[i].se.x,&a[i].se.y);
        }
        for(int i=1;i<=n-1;++i){
            for(int j=i+1;j<=n;++j){
                if(isSegInter(a[i].fi,a[i].se,a[j].fi,a[j].se)){
                    used[i]=0;break;
                }
            }
        }
        printf("Top sticks: ");
        for(int i=1;i<=n;++i){
            if(used[i])ans.push_back(i);
        }
        int len=ans.size();
        for(int i=0;i<len-1;++i){
            cout<<ans[i]<<", ";
        }
        cout<<ans[len-1]<<".\n";
    }
    return 0;
}