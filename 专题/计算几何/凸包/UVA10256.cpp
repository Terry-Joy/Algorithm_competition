#include<bits/stdc++.h>
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))//p2-p1叉p3-p1
using namespace std;
typedef double db;
const db eps=1e-8;
const int maxn=505;
int n,m,cnt1,cnt2=0;
int sign(db a){ //符号正负
    return a<-eps?-1:a>eps;
}

int dcmp(db a,db b){ //两数大小
    return sign(a-b);
}
db dAbs(db a){return a*sign(a);}

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
    db len2(){ return x*x+y*y;}//能用ll就ll，精度
    db len(){  return sqrt(len2());}
}a[maxn],b[maxn],ch1[maxn],ch2[maxn];
db dot(P a,P b){//内积
    return a.x*b.x+a.y*b.y;
}
bool operator==(P a,P b){return !dcmp(a.x,b.x)&&!dcmp(a.y,b.y);}
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
bool onSeg(P c,P a,P b){//判断c是否在线段ab上
    return sign(det(c-a,b-a))==0&&sign(dot(c-a,c-b))<=0;
}
bool recInter(db l1,db r1,db l2,db r2){//矩形相交 快速排斥
    if(l1>r1)swap(l1,r1);if(l2>r2)swap(l2,r2);
    return !(dcmp(r1,l2)==-1||dcmp(r2,l1)==-1);
}
bool isSegInter(P p1,P p2,P q1,P q2){//判 线段p1p2与q1q2是否相交 端点算交 重点无关
    return recInter(p1.x,p2.x,q1.x,q2.x)&&recInter(p1.y,p2.y,q1.y,q2.y)&&
    cha(p1,p2,q1)*cha(p1,p2,q2)<=0&&cha(q1,q2,p1)*cha(q1,q2,p2)<=0;  
}
int TuContain(P p[],int n,P a){//二分法判断a是否在凸多边形以内 必须是凸多边形
    if(n==1)if(p[1]==a)return 2;else return 0;              //特判非凸包 看情况加
    else if(n==2)if(onSeg(a,p[1],p[2]))return 2;else return 0;
    else{ 
    //点必须按逆时针给 顺时针>改<即可
        if(cha(p[1],a,p[2])>0||cha(p[1],p[n],a)>0)return 0;//P[1,2]或[1,n]外
        if(onSeg(a,p[1],p[2])||onSeg(a,p[1],p[n]))return 2;//[1,2]/[1,n]上
        int l=2,r=n-1;
        while(l<r){
            int mid=l+r+1>>1;
            if(cha(p[1],p[mid],a)>0)l=mid;//使得a被mid,mid+1到1夹住
            else r=mid-1;
        }
        if(cha(p[l],a,p[l+1])>0)return 0;
        if(onSeg(a,p[l],p[l+1]))return 2;
        return 1;
    }
}
void Andrew(P p[],P ch[],int&m,int n){//求凸包 
	sort(p+1,p+n+1);//重载的排序
	for(int i = 1; i <=n; i++){
		while(m > 1 && cha(ch[m-2],ch[m-1],p[i]) <= 0) m--;//<=不需要共线
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-1; i >= 1; i--){
		while(m > k && cha(ch[m-2],ch[m-1],p[i]) <= 0) m--;
		ch[m++] = p[i];
	}
	if(n > 1) m--;
}
int PPLI(P a[],P b[],int num1,int num2){//判两多边形是否相离 先求两凸包
    for(int i1=1;i1<=num1;++i1){ 
        int j1=i1<num1?i1+1:1;
        for(int i2=1;i2<=num2;++i2){ 
            int j2=i2<num2?i2+1:1;
            if(isSegInter(a[i1],a[j1],b[i2],b[j2]))return 0;//线段相交不相离
            if(TuContain(b,num2,a[i1])||TuContain(a,num1,b[i2]))return 0;//点在多边形内不相离
        }
    }
    return 1;
}
int main(){ 
    while(~scanf("%d%d",&n,&m)&&n+m){ 
        cnt1=cnt2=0;
        for(int i=1;i<=n;++i)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        for(int i=1;i<=m;++i) 
            scanf("%lf%lf",&b[i].x,&b[i].y);
        Andrew(a,ch1,cnt1,n);
        Andrew(b,ch2,cnt2,m);
        for(int i=cnt1-1;i>=0;--i)ch1[i+1]=ch1[i];
        for(int i=cnt2-1;i>=0;--i)ch2[i+1]=ch2[i];
        for(int i=1;i<=cnt1;++i)cout<<ch1[i].x<<" "<<ch1[i].y<<"\n";
        if(PPLI(ch1,ch2,cnt1,cnt2))puts("Yes");
        else puts("No");
    }
    return 0;
}
