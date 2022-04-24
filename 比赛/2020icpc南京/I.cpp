#include<bits/stdc++.h>
#define cha(p1,p2,p3) (det(p2-p1,p3-p1))
#define fi first 
#define se second
using namespace std;
typedef double db;
const db INF=1e20;
struct P{
    int x,y;
    P(int _x=0,int _y=0):x(_x),y(_y){}
    bool operator<(const P&a)const{return y<a.y;}
    P operator-(P p){return P(x-p.x,y-p.y);}
};
int det(P a,P b){
    return a.x*b.y-a.y*b.x;
}
int sign(int a){
    return a==0?0:a>0?1:-1;
}
const int maxn=105;
bool isSegInter(P p1,P p2,P q1,P q2){
    return cha(p1,p2,q1)*cha(p1,p2,q2)<0&&cha(q1,q2,p1)*cha(q1,q2,p2)<0;
}

db dp[maxn<<1];
int n,m,vy;
P p[maxn<<1];
pair<P,P>L[maxn<<1];

bool ok(P a,P b){
    for(int i=0;i<n;++i){
        if(isSegInter(a,b,L[i].fi,L[i].se))return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d%d",&n,&m,&vy);
    for(int i=0;i<n;++i){
        scanf("%d%d",&p[i<<1].x,&p[i<<1].y);
        scanf("%d%d",&p[i<<1|1].x,&p[i<<1|1].y);
        L[i]={p[i<<1],p[i<<1|1]};
    }
    sort(p,p+2*n);
    for(int i=0;i<2*n;++i)dp[i]=INF;
    db ans=INF;
    for(int i=0;i<2*n;++i){
        if(p[i].x<=-m||p[i].x>=m)continue;//必须加 此时已经边界转移过去铁定无法满足
        if(ok(P(p[i].x,-10001),p[i]))dp[i]=0;//边界
        for(int j=0;j<i;++j){
            if(p[i].y==p[j].y)break;
            if(ok(p[i],p[j])){
                dp[i]=min(dp[i],max(dp[j],fabs(1.0*(p[i].x-p[j].x)/(p[i].y-p[j].y))));
            }

        }
        if(ok(P(p[i].x,10001),p[i]))ans=min(ans,dp[i]);//可以到终点
    }
    if(ok(P(0,-10001),P(0,10001)))ans=0;//考虑起点和终点的贡献
    if(ans>1e15)cout<<-1<<"\n";
    else printf("%.10f\n",ans*vy);
    return 0;
}