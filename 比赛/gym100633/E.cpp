#include<bits/stdc++.h>
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))
#define cha2(p1,p2,p3) det(p2-p1,p3-p1)
#define pb push_back
using namespace std;
using db=double;
const db eps=1e-8;
const int maxn=8e4+100;
int n,cnt;
int sign(db a){
    return a<-eps?-1:a>eps;
}
int dcmp(db a,db b){
    return sign(a-b);
}
struct P{
    db x,y;
    P (db _x=0,db _y=0):x(_x),y(_y){}
    P operator-(P p){return P(x-p.x,y-p.y);}
    P operator+(P p){return P(x+p.x,y+p.y);}
    P operator*(db d){return P(x*d,y*d);}
    db len2(){return x*x+y*y;}
    db len(){return sqrt(len2());}
    bool operator<(P p)const{
        int c=dcmp(x,p.x);
        if(c)return c==-1;
        return dcmp(y,p.y)==-1;
    }
}p[maxn],res[maxn];
P unit(P a){
    return P(a.x/a.len(),a.y/a.len());
}
db det(P a,P b){
    return a.x*b.y-a.y*b.x;
}
db dot(P a,P b){
    return a.x*b.x+a.y*b.y;
}
P RotateL90(const P&a){
    return P(-a.y,a.x);
}
int Andrew(P p[],P ch[]){
    sort(p+1,p+1+n);
    int m=0;
    for(int i=1;i<=n;++i){
        while(m>1&&cha(ch[m-2],ch[m-1],p[i])<=0)m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-1;i>=1;--i){
        while(m>k&&cha(ch[m-2],ch[m-1],p[i])<=0)m--;
        ch[m++]=p[i];
    }
    if(n>1)m--;
    return m;
}
int nxt(int x){
    return (x+1)%cnt;
}
P proj(P p1,P p2,P p){
    P a=p2-p1;
    return p1+a*(dot(p-p1,a)/a.len2());
}
db area(vector<P>p){
    db ans=0;
    int sz=p.size();
    for(int i=0;i<sz-1;++i)ans+=det(p[i],p[i+1]);
    ans+=det(p[sz-1],p[0]);
    return fabs(ans/2);
}
db Pdis(P p0,P p1,P a){
    return fabs(det(a-p0,p1-p0)/(p1-p0).len());
}
void print(P a){
    printf("%.10lf %.10lf\n",a.x,a.y);
}
db solve(P x0,P x1,P x2,P x3,P x4,vector<P>&now){
    P a0,a1,a2,a3;
    a0=proj(x0,x1,x4);
    a1=proj(x0,x1,x2);
    now.pb(a0);
    now.pb(a1);
    P rot=RotateL90(x1-x0);
    P w=unit(rot);
    db len=Pdis(x0,x1,x3);
    a2=a1+w*len;
    a3=a0+w*len;
    now.pb(a2);
    now.pb(a3);
    return area(now);
}
vector<P>tmp,nowans;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>p[i].x>>p[i].y;
    cnt=Andrew(p,res);
    int p1=0,p2=-1,p3=1;
    db ans=9e18;
    for(int i=0;i<=cnt-1;++i){//p1右方 p2左边 p3正上方
        while(cha2(res[i],res[i+1],res[p3])<cha2(res[i],res[i+1],res[nxt(p3)]))p3=nxt(p3);
        P dir=res[i+1]-res[i];
        while(sign(dot(dir,res[nxt(p1)]-res[p1]))>0)p1=nxt(p1);
        if(p2==-1)p2=p3;
        while(sign(dot(dir,res[nxt(p2)]-res[p2]))<0)p2=nxt(p2);
        db mnans=solve(res[i],res[i+1],res[p1],res[p3],res[p2],tmp);
        if(dcmp(mnans,ans)<0){
            ans=mnans;
            nowans=tmp;
        }
        tmp.clear();
    }
     for(auto u:nowans)
         print(u);
    return 0;
}
