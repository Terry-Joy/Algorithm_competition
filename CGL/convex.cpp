#include<bits/stdc++.h>

using namespace std;
#define cha(p1,p2,p3) (sign(det(p2-p1,p3-p1)))
typedef double db;
const db eps=1e-8;

int sign(db a){ //符号正负
    return a<-eps?-1:a>eps;
}

int dcmp(db a,db b){ //两数大小
    return sign(a-b);
}
const int maxn=105;
int n;
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
};
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
P p[maxn],ch[maxn];
int Andrew(){//求凸包 
	sort(p+1,p+n+1);//重载的排序
	int m = 0;
	for(int i = 1; i <=n; i++){
		while(m > 1 && cha(ch[m-2],ch[m-1],p[i]) < 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-1; i >= 1; i--){
		while(m > k && cha(ch[m-2],ch[m-1],p[i]) < 0) m--;
		ch[m++] = p[i];
	}
	if(n > 1) m--;
	return m;
}
int main(){ 
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
    int num=Andrew();
    if(num==n)puts("1");
    else puts("0");
    return 0;
}
