#include<bits/stdc++.h>

using namespace std;
typedef double db;
const db eps=1e-8;
const int maxn=1e5+5;
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
    db len2(){ return x*x+y*y;}
    db len(){  return sqrt(len2()); }
};
bool operator==(P a,P b){return !dcmp(a.x,b.x)&&!dcmp(a.y,b.y);}
db dot(P a,P b){//内积
    return a.x*b.x+a.y*b.y;
}
db det(P a,P b){//叉积
    return a.x*b.y-a.y*b.x;
}
db AngleSign(P a,P b){//(3)两夹角钝锐直
    return sign(dot(a,b));
}
P proj(P p1,P p2,P p){//(4)求p投影到p1,p2直线的点
    P a=p2-p1;
    return p1+a*(dot(p-p1,a)/a.len2());
}
P seg[maxn],ans;
int n;
db mx;
void PdisSeg(P c,P a,P b){ 
    if(a==b){ 
        if(dcmp((c-a).len(),mx)<0)mx=(c-a).len(),ans.x=a.x,ans.y=a.y;
    }
    P x=c-a,y=c-b,z=b-a;
    if(AngleSign(x,z)<0){ 
        if(dcmp(x.len(),mx)<0){ 
            mx=x.len();ans.x=a.x;ans.y=a.y;
            return;
        }
    }
    if(AngleSign(y,z)>0){ 
        if(dcmp(y.len(),mx)<0){ 
            mx=y.len();ans.x=b.x,ans.y=b.y;
            return;
        }
    }
    db k=dAbs(det(x,z)/z.len());
    if(dcmp(k,mx)<0){ 
        mx=k;
        P pr=proj(a,b,c);
        ans.x=pr.x;ans.y=pr.y;
    }
}
int main(){ 
    P m;
    while(~scanf("%lf%lf",&m.x,&m.y)){ 
        scanf("%d",&n);
        mx=2e9;
        for(int i=1;i<=n+1;++i){ 
            scanf("%lf%lf",&seg[i].x,&seg[i].y);
        }  
        if(!n){ 
            printf("%.4lf\n%.4lf\n",seg[1].x,seg[1].y);
            continue;
        }
        int i=1,j=2;
        while(i<=n&&j<=n+1){ 
            PdisSeg(m,seg[i],seg[j]);
            i++;j++;
        }
        printf("%.4lf\n%.4lf\n",ans.x,ans.y);
    } 
    return 0;
}
